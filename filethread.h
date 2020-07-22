#ifndef FILETHREAD_H
#define FILETHREAD_H

#include <QThread>

class filethread : public QThread
{
    Q_OBJECT

public:
    explicit filethread(QObject *parent = nullptr);
protected:
    void run();//多线程执行的内容将通过重新该虚函数实现
public:
    int getcopyres();
private:
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
    bool iscopyright;
signals:
    void over();
};

#endif // FILETHREAD_H
