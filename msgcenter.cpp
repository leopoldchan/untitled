#include "msgcenter.h"
#include "SDTMessage.h"
#include "sdtmq.h"
#include <QMessageBox>

msgcenter::msgcenter(QObject *parent) : QThread(parent)
{
    /*session = NULL;
    queue_name = "CDM_QUEUE_SYSTEMTRAY";
    session = SDTMQ_OpenSession(NULL);
    if (NULL == session)
    {
        emit initFail();
        return;
    }
    int ret = SDTMQ_Declare(session, queue_name.toLocal8Bit().data(), QUEUE_EXCLUSIVE);
    if (0 != ret)
        emit initFail();*/
}

msgcenter::~msgcenter()
{
    /*if (session)
    {
        SDTMQ_Free(session, queue_name.toLocal8Bit().data());
        SDTMQ_CloseSession(session);
    }*/
}

void msgcenter::run()
{
    /*int ret;
    SDTMQ_MESSAGE rsv_message = { 0 };
    QString str_msg;
    if (NULL == session)
        return ;
    while(1)
    {
       ret = SDTMQ_Poll(session, queue_name.toLocal8Bit().data(), &rsv_message);
       if (0 != ret)
            continue;
        switch (rsv_message.type)
        {
            case SDTMSGNO_APPNOTICE:
                str_msg = QString((char*)rsv_message.data);
                emit appMsg(str_msg);
                break;
            default:
                break;
        }
        ret = SDTMQ_DestroyMessage(&rsv_message);
        if (0 != ret)
            continue;
    }*/
    while(1)
    {
        emit getMsg();
        sleep(2);
    }
}
