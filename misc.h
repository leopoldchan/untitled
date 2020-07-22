#ifndef MISC_H
#define MISC_H
#include <QString>

#define MSG_BUFFER_SIZE 512
#define ERR_JSON_PARSE  5001
#define ERR_JSON_NOTFOUND 5002
#define ERR_JSON_EMPTY 5002

typedef struct MSG_INFO_st
{
    int level;
    QString time;
    QString source;
    QByteArray content;
} MSG_INFO;

#endif // MISC_H
