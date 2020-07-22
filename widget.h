#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "filethread.h"
#include "misc.h"
#include "json.h"
#include "msgcenter.h"
#include "sdtmq.h"
#include "SDTMessage.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QtXml>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QtAndroid>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void filecopyover();//处理新线程返回的结束信号
    void replyLoginFinished(QNetworkReply* reply);
    void replyTokenFinished(QNetworkReply* reply);
    void replyMsgFinished(QNetworkReply* reply);
    void on_readyRead();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void AddMsgModel(QString msg);
    void getMsgCenter();
    void initMQFail();

    void on_pushButton_3_clicked();


private:
    Ui::Widget *ui;
    filethread *file_t;
    msgcenter *msgcenter_t;
    json *rec_json;
    int copyres;
    QMap<int, QString> mapLevel;
    QDomDocument doc;
    void SendPostMsg(QString url, QString msg_body);
    void SendGetMes(QString url, int msg_type);
    void InitMsgTable();
    void AddOneMsg(MSG_INFO new_msg_info);
    void initas();
    void addXmlEmptyNode(QDomElement item);
    void saveAS(int port, QString ip, int type);
    QStandardItemModel  *theModel;//数据模型
    QSortFilterProxyModel *levelProxyModel;
    QSortFilterProxyModel *sourceProxyModel;
    QStringList sourceList;

};
#endif // WIDGET_H
