#include "widget.h"
#include "ui_widget.h"

void Widget::InitMsgTable()
{
    theModel = new QStandardItemModel(0,4,this); //创建数据模型

    //为tableView设置数据模型
    //ui->tableView->setModel(theModel); //设置数据模型
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList headerList;
    headerList<<"消息时间"<<"消息等级"<<"消息来源"<<"消息概述";
    theModel->setHorizontalHeaderLabels(headerList); //设置表头文字
    levelProxyModel=new QSortFilterProxyModel;
    levelProxyModel->setSourceModel(theModel);
    levelProxyModel->setFilterKeyColumn(1);
    sourceProxyModel=new QSortFilterProxyModel;
    sourceProxyModel->setSourceModel(levelProxyModel);
    sourceProxyModel->setFilterKeyColumn(2);
    ui->tableView->setModel(sourceProxyModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableView, SIGNAL(itemChanged(QTableWidgetItem*)), ui->tableView, SLOT(resizeRowsToContents()));
}

void Widget::AddOneMsg(MSG_INFO new_msg_info)
{
    //更新消息列表(如果列表已满，删除最旧的一条消息)
    int row=theModel->rowCount();
    if (row >= MSG_BUFFER_SIZE)
    {
        theModel->removeRow(row-1);
    }
    theModel->insertRow(0);
    theModel->setItem(0, 0, new QStandardItem(new_msg_info.time));
    theModel->setItem(0, 1, new QStandardItem(mapLevel[new_msg_info.level]));
    theModel->setItem(0, 2, new QStandardItem(new_msg_info.source));

    QString str=QString::fromLocal8Bit(new_msg_info.content);

    theModel->setItem(0, 3, new QStandardItem(str));
    if(!sourceList.contains(new_msg_info.source))
    {
        sourceList.append(new_msg_info.source);
        ui->comboBox_2->addItem(new_msg_info.source);
    }
}

void Widget::getMsgCenter()
{
    SendGetMes("http://127.0.0.1:12159/naclient/getmessage", 1);
}

void Widget::AddMsgModel(QString msg)
{
    MSG_INFO new_msg_info;
    QDomDocument doc_msg;
    if (!doc_msg.setContent(msg))
    {
        QMessageBox::warning(this, "错误", "接收消息格式错误", "确定");
        return ;
    }
    QDomElement root_element = doc_msg.documentElement();
    QDomNode node = root_element.firstChild();
    QDomElement element;

    while(!node.isNull())
    {
        element = node.toElement();
        if (!element.isNull())
        {
            if (element.tagName() == "time")
            {
                new_msg_info.time = element.text();
            }
            else if (element.tagName() == "level")
            {
                new_msg_info.level = element.text().toInt();
            }
            else if (element.tagName() == "source")
            {
                new_msg_info.source = element.text();
            }
            else if (element.tagName() == "content_b64")
            {
                new_msg_info.content = QByteArray::fromBase64(element.text().toLocal8Bit());
            }
        }
        node = node.nextSibling();
    }

    AddOneMsg(new_msg_info);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->showNormal();
    //this->resize(QApplication::desktop()->width(), QApplication::desktop()->width()/2);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    copyres=0;
    #ifdef Q_OS_ANDROID
        file_t = new filethread(this);
        file_t->start();
        connect(file_t,SIGNAL(over()),this,SLOT(filecopyover()));
    #else
        copyres=1;
        initas();
    #endif
    mapLevel[1] = tr("错误");
    mapLevel[2] = tr("警告");
    mapLevel[4] = tr("信息");
    InitMsgTable();
    msgcenter_t=new msgcenter(this);
    msgcenter_t->start();
    connect(msgcenter_t, SIGNAL(getMsg()), this, SLOT(getMsgCenter()));
}

Widget::~Widget()
{
    delete ui;
    #ifdef Q_OS_ANDROID
        disconnect(file_t,SIGNAL(over()),this,SLOT(filecopyover()));
    #endif
    disconnect(msgcenter_t, SIGNAL(getMsg()), this, SLOT(getMsgCenter()));
}


void Widget::on_pushButton_clicked()
{
    QString passwd,info;
    passwd=ui->lineEdit_2->text();
    if(passwd.isEmpty())
    {
        QMessageBox::information(this, "提示", "密码为空", "确定");
        return;
    }

    QString msg_body=tr("{\r\n\t\"oldPIN\":\"%1\", \r\n\t\"newPIN\":\"\"\r\n}").arg(passwd);
    SendPostMsg("http://127.0.0.1:12159/naclient/setpin", msg_body);
    /*SDTMQ_SESSION mqSession = NULL;
    SDTMQ_MESSAGE message = { 0 };

    message.type = SDTMSGNO_ASAG_LOGIN;
    SDTMQ_Init();
    mqSession = SDTMQ_OpenSession(NULL);
    if (NULL == mqSession)
    {
        QMessageBox::critical(this, "错误", tr("发送认证消息失败, %1").arg(SDTMQ_GetLastErrorText()), "确定");
        return;
    }
    int ret=SDTMQ_Push(mqSession, "naclient", &message);
    if(ret!=0)
    {
        QMessageBox::critical(this, "错误", tr("发送认证消息失败, %1").arg(SDTMQ_GetLastErrorText()), "确定");
        SDTMQ_CloseSession(mqSession);
        return;
    }
    SDTMQ_CloseSession(mqSession);*/
}

void Widget::addXmlEmptyNode(QDomElement item)
{
    QDomText text;
    text=doc.createTextNode("");
    item.appendChild(text);
    text.clear();
}

void Widget::initas()
{
    QString curPath;
#ifdef Q_OS_ANDROID
    curPath="/data/data/com.sdt.sdtas/files/sdtas/data/naconfig.xml";
#else
    curPath=QCoreApplication::applicationDirPath();
    curPath=curPath.mid(0, curPath.lastIndexOf('/'));
    curPath+="/data/naconfig.xml";
#endif
    QFile file(curPath);
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::information(this, "提示", tr("打开%1失败").arg(curPath),"确定");
        return;
    }
    if (!doc.setContent(&file))
    {
        QMessageBox::warning(this, "错误", "配置文件格式错误", "确定");
        file.close();
        return ;
    }
    ui->lineEdit_3->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->comboBox_3->setEnabled(true);
    QDomElement root_element = doc.documentElement();
    QDomNode node = root_element.firstChild();
    QDomElement element;

    while(!node.isNull())
    {
        if(node.nodeName()=="ASADDR")
        {
            QDomNodeList list=node.toElement().elementsByTagName("item");
            QDomElement child=list.at(0).toElement();
            ui->lineEdit_3->setText(child.attribute("as_ip"));
            ui->spinBox->setValue(child.attribute("as_port").toInt());
            ui->comboBox_3->setCurrentIndex(child.attribute("as_type").toInt());
        }
        else
        {
            QDomNodeList list=node.childNodes();
            if(list.count()==0) addXmlEmptyNode(node.toElement());
            for(int i=0;i<list.count();i++)
            {
                QDomNode n=list.at(i);
                if(n.childNodes().count()==0) addXmlEmptyNode(n.toElement());
            }
        }
        node = node.nextSibling();
    }
    file.close();
}

void Widget::filecopyover()
{
    copyres=file_t->getcopyres();
    if(copyres) initas();
}

void Widget::SendPostMsg(QString url, QString msg_body)
{
   //创建一个请求
   QNetworkRequest request;
   request.setUrl(QUrl(url));
   request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=utf-8"));
   //创建一个管理器
   QNetworkAccessManager *manager = new QNetworkAccessManager(this);
   auto body = QString(msg_body).toLatin1();
   QNetworkReply *reply = manager->post(request, body);

   //连接请求结束信号
   connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyLoginFinished(QNetworkReply*)));
   //连接响应时返回数据信号
   connect(reply, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
}

void Widget::SendGetMes(QString url, int msg_type)
{
    //创建一个请求
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    //创建一个管理器
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);
    //连接请求结束信号
    if(msg_type==0) connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyTokenFinished(QNetworkReply*)));
    else connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyMsgFinished(QNetworkReply*)));
    //连接响应时返回数据信号
    connect(reply, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
}

void Widget::replyMsgFinished(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();

    int ret;
    QString res;
    rec_json=new json();
    rec_json->parseJsonInt(data, "errCode", &ret);
    if(ret!=0) return;
    QString msgb64;
    rec_json->parseJsonStr(data, "msgB64", msgb64);
    if(msgb64.isNull()||msgb64.isEmpty()) return;
    QByteArray ba=QByteArray::fromBase64(msgb64.toLatin1());
    int msg_count;
    MSG_INFO *msg_info;
    rec_json->parseMsgCenter(ba, &msg_count, &msg_info);
    for(int i=0;i<msg_count;i++)
    {
        AddOneMsg(msg_info[i]);
    }
    rec_json->freeMsgCenter(msg_info);
}

void Widget::replyTokenFinished(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();

    int ret;
    QString res;
    rec_json=new json();
    rec_json->parseJsonInt(data, "errCode", &ret);
    if(ret!=0)
    {
        rec_json->parseJsonStr(data, "errMsg", res);
        QMessageBox::information(this, "信息", tr("获取票据失败, %1").arg(res),"确定");
        return;
    }
    QMessageBox::information(this, "信息", "获取票据成功","确定");
#ifdef Q_OS_ANDROID
    /*QAndroidJniEnvironment env;
    QAndroidJniObject action = QAndroidJniObject::fromString("android.intent.action.KEY_STATUS");
    QAndroidJniObject intent("android/content/Intent","(Ljava/lang/String;)V", action.object<jstring>());*/
    //QAndroidJniObject QAndroidJniObject_MyJavaClass_obj("org/MyJavaClass");
    //jint n = QAndroidJniObject::callStaticMethod<jint>("org/MyJavaClass", "SendLoginSuccessBroadcast");
    QAndroidJniObject::callStaticMethod<void>("org/MyJavaClass", "SendLoginSuccessBroadcast", "(Landroid/content/Context;)V", QtAndroid::androidActivity().object());
#endif
}

void Widget::replyLoginFinished(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();

    int ret;
    QString res;
    rec_json=new json();
    rec_json->parseJsonInt(data, "errCode", &ret);
    if(ret!=0)
    {
        rec_json->parseJsonStr(data, "errMsg", res);
        QMessageBox::information(this, "信息", tr("登录失败, %1").arg(res),"确定");
#ifdef Q_OS_ANDROID
    QAndroidJniObject::callStaticMethod<void>("org/MyJavaClass", "SendOfflineBroadcast", "(Landroid/content/Context;)V", QtAndroid::androidActivity().object());
#endif
        return;
    }
    QMessageBox::information(this, "信息", "登录成功","确定");
    SendGetMes("http://127.0.0.1:12159/naclient/gettoken", 0);
}

void Widget::on_readyRead()
{

}

/*void Widget::on_pushButton_3_clicked()
{
    AddMsgModel("<test><time>2020-07-01 09:21:19:319</time>\r\n<level>1</level>\r\n<source>NAClient</source>\r\n<content_b64>MIGWMTkwNwYDVQQKDDDnlLXlrZDmlL/liqHlhoXnvZHms5XpmaLns7vnu5/kuIDnuqforqTor4Hnu5PngrkxOTA3BgNVBAMMMOeUteWtkOaUv+WKoeWGhee9keazlemZouezu+e7n+S4gOe6p+iupOivgee7k+eCuTEeMBwGA1UEBgwV5Lit5Y2O5Lq65rCR5YWx5ZKM5Zu9</content_b64></test>");
    AddMsgModel("<test><time>2020-07-01 09:21:19:211</time>\r\n<level>1</level>\r\n<source>LocalProxy</source>\r\n<content_b64>MIGWMTkwNwYDVQQKDDDnlLXlrZDmlL/liqHlhoXnvZHms5XpmaLns7vnu5/kuIDnuqforqTor4Hnu5PngrkxOTA3BgNVBAMMMOeUteWtkOaUv+WKoeWGhee9keazlemZouezu+e7n+S4gOe6p+iupOivgee7k+eCuTEeMBwGA1UEBgwV5Lit5Y2O5Lq65rCR5YWx5ZKM5Zu9</content_b64></test>");
    AddMsgModel("<test><time>2020-07-01 09:21:19:319</time>\r\n<level>2</level>\r\n<source>NAClient</source>\r\n<content_b64>MIGWMTkwNwYDVQQKDDDnlLXlrZDmlL/liqHlhoXnvZHms5XpmaLns7vnu5/kuIDnuqforqTor4Hnu5PngrkxOTA3BgNVBAMMMOeUteWtkOaUv+WKoeWGhee9keazlemZouezu+e7n+S4gOe6p+iupOivgee7k+eCuTEeMBwGA1UEBgwV5Lit5Y2O5Lq65rCR5YWx5ZKM5Zu9</content_b64></test>");
    AddMsgModel("<test><time>2020-07-01 09:21:19:211</time>\r\n<level>2</level>\r\n<source>LocalProxy</source>\r\n<content_b64>MIGWMTkwNwYDVQQKDDDnlLXlrZDmlL/liqHlhoXnvZHms5XpmaLns7vnu5/kuIDnuqforqTor4Hnu5PngrkxOTA3BgNVBAMMMOeUteWtkOaUv+WKoeWGhee9keazlemZouezu+e7n+S4gOe6p+iupOivgee7k+eCuTEeMBwGA1UEBgwV5Lit5Y2O5Lq65rCR5YWx5ZKM5Zu9</content_b64></test>");

}*/

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString str=arg1;
    if(str=="全部")
    {
        str="";
    }
    QRegExp regExp(str, Qt::CaseInsensitive, QRegExp::FixedString);
    levelProxyModel->setFilterRegExp(regExp);
}

void Widget::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
     QString str=arg1;
     if(str=="全部")
     {
         str="";
     }
    QRegExp regExp(str, Qt::CaseInsensitive, QRegExp::FixedString);
    sourceProxyModel->setFilterRegExp(regExp);
}

void Widget::initMQFail()
{
    QMessageBox::warning(this, tr("警告"), tr("初始化消息队列失败！"), tr("确定"));
}

void RemoveAllChild(QDomNode node)
{
    while(node.hasChildNodes())
    {
        RemoveAllChild(node.lastChild());
        node.removeChild(node.lastChild());
    }
}

void Widget::saveAS(int port, QString ip, int type)
{
    QDomElement root=doc.documentElement();
    QDomNodeList list=root.elementsByTagName("ASADDR");
    QDomNode node=list.at(0);
    RemoveAllChild(node);
    QDomElement item=doc.createElement("item");
    item.setAttribute("as_port", QString::number(port));
    item.setAttribute("as_ip", ip);
    item.setAttribute("as_type", QString::number(type));
    addXmlEmptyNode(item);

    node.appendChild(item);
    QString curPath;
#ifdef Q_OS_ANDROID
    curPath="/data/data/com.sdt.sdtas/files/sdtas/data/naconfig.xml";
    system("chmod 777 /data/data/com.sdt.sdtas/files/sdtas/data/naconfig.xml");
#else
    curPath=QCoreApplication::applicationDirPath();
    curPath=curPath.mid(0, curPath.lastIndexOf('/'));
    curPath+="/data/naconfig.xml";
#endif
    QFile file(curPath);
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QMessageBox::information(this, "提示", tr("打开%1失败").arg(curPath),"确定");
        return;
    }
    QTextStream out_stream(&file);
    doc.save(out_stream, 4);
    file.close();
    QMessageBox::information(this, "提示", tr("配置保存成功"),"确定");
}

void Widget::on_pushButton_3_clicked()
{
    QRegExp *regExp=new QRegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    QRegExpValidator v_ip(*regExp, 0);
    QString ip=ui->lineEdit_3->text();
    if(!regExp->exactMatch(ip)&&ip.length()>=1)
    {
        QMessageBox::warning(this, "提示", "请输入正确的IP地址","确定");
        return;
    }
    saveAS(ui->spinBox->value(), ip, ui->comboBox_3->currentIndex());
}
