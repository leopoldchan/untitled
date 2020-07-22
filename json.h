#ifndef JSON_H
#define JSON_H

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include "misc.h"

class json
{
public:
    json();
    int parseJsonStr(QByteArray json_data, QString key, QString &value);
    int parseJsonInt(QByteArray json_data, QString key, int *value);
    int parseMsgCenter(QByteArray json_data, int *msg_count, MSG_INFO **msg_info);
    void freeMsgCenter(MSG_INFO *msg_info);
};

#endif // JSON_H
