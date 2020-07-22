#include "json.h"
#include <QMessageBox>

json::json()
{

}

int json::parseJsonStr(QByteArray json_data, QString key, QString &value)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(json_data, &json_error));

    if(json_error.error != QJsonParseError::NoError)
    {
        return ERR_JSON_PARSE;
    }
    if(jsonDoc.isNull()||jsonDoc.isEmpty())
    {
        return ERR_JSON_EMPTY;
    }
    QJsonObject rootObj = jsonDoc.object();

    if(rootObj.contains(key))
    {
        value=rootObj[key].toString();
        return 0;
    }
    return ERR_JSON_NOTFOUND;
}

int json::parseJsonInt(QByteArray json_data, QString key, int *value)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(json_data, &json_error));

    if(json_error.error != QJsonParseError::NoError)
    {
        return ERR_JSON_PARSE;
    }
    if(jsonDoc.isNull()||jsonDoc.isEmpty())
    {
        return ERR_JSON_EMPTY;
    }
    QJsonObject rootObj = jsonDoc.object();

    if(rootObj.contains(key))
    {
        *value=rootObj[key].toInt();
        return 0;
    }
    return ERR_JSON_NOTFOUND;
}

int json::parseMsgCenter(QByteArray json_data, int *msg_count, MSG_INFO **msg_info)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(json_data, &json_error));

    if(json_error.error != QJsonParseError::NoError)
    {
        return ERR_JSON_PARSE;
    }
    if(jsonDoc.isNull()||jsonDoc.isEmpty())
    {
        return ERR_JSON_EMPTY;
    }
    QJsonObject rootObj = jsonDoc.object();
    if(!rootObj.contains("message")) return ERR_JSON_EMPTY;
    QJsonArray msgArray= rootObj.take("message").toArray();
    *msg_count=msgArray.size();
    MSG_INFO *msg_tmp;
    msg_tmp=new MSG_INFO[*msg_count];
    for(int i=0;i<msgArray.size();i++)
    {
        QJsonValue msgValue=msgArray.at(i);
        if(!msgValue.isObject()) ERR_JSON_PARSE;
        QJsonObject jsonObj=msgValue.toObject();
        if(jsonObj.contains("time"))
        {
            msg_tmp[i].time = jsonObj["time"].toString();
        }
        if (jsonObj.contains("level"))
        {
            msg_tmp[i].level = jsonObj["level"].toInt();
        }
        if (jsonObj.contains("module"))
        {
            msg_tmp[i].source = jsonObj["module"].toString();
        }
        if (jsonObj.contains("content"))
        {
            msg_tmp[i].content = jsonObj["content"].toString().toLocal8Bit();
        }
    }
    *msg_info=msg_tmp;
    return 0;
}

void json::freeMsgCenter(MSG_INFO *msg_info)
{
    delete [] msg_info;
}

