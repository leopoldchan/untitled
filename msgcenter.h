#ifndef MSGCENTER_H
#define MSGCENTER_H

#include <QThread>
#include "json.h"

class msgcenter : public QThread
{
    Q_OBJECT

public:
    explicit msgcenter(QObject *parent = nullptr);
    ~msgcenter();
protected:
    void run();//多线程执行的内容将通过重新该虚函数实现
private:
    void getmsg(QString url);
    void *session;		//会话句柄
    QString queue_name;	//消息队列名称
    json *rec_json;
signals:
    void initFail();					//初始化失败
    void appMsg(QString msg);
    void getMsg();
};

#endif // MSGCENTER_H
