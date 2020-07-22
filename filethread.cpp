#include "filethread.h"
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QMessageBox>

filethread::filethread(QObject *parent) : QThread(parent)
{

}

//拷贝文件夹
bool filethread::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists())
    {/*如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
         return false;
    }
    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList)
    {
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..") continue;
        if(fileInfo.isDir())
        {/*当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(), targetDir.filePath(fileInfo.fileName()), coverFileIfExist))
                return false;
        }
        else
        {/*当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }
            if(!QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName())))
            {
                return false;
            }
        }
    }
    return true;
}

void filethread::run()
{
    QString curPath=QDir::currentPath();
    curPath=curPath.mid(0, curPath.lastIndexOf('/'));
    curPath+="/files/sdtas";
    if(QFile::exists(curPath+"/lib/NAClient"))
    {
        iscopyright=true;
        QString str = curPath+"/lib/start.sh &";
        system(str.toLatin1());
        emit over();
        return;
    }
    iscopyright=copyDirectoryFiles("assets:/sdtas", curPath, true);
    if(iscopyright==false)
    {
        emit over();
        return;
    }
    QString str ="chmod 777 "+curPath+"/lib/*";
    system(str.toLatin1());
    str = curPath+"/lib/naclient_init.sh";
    system(str.toLatin1());
    str = curPath+"/lib/start.sh &";
    system(str.toLatin1());
    emit over();//复杂函数结束后发出信号

}

int filethread::getcopyres()
{
    return iscopyright;
}
