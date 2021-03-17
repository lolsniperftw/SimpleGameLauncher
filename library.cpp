#include "library.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

QString Library::pathToMetaData=QDir::homePath()+"\\"+"\\.config\\legendary\\metadata";

Library::Library()
{
    loadLibrary();
}

void Library::loadLibrary()
{
    int x;
    QString homePath=QDir::homePath(),data,appTitle;
    QFile file;
    QString path=homePath+"\\.config\\legendary\\metadata";
    QDir test(path);
    QStringList testlist = test.entryList();
    x=testlist.size();
    for(int i=2;i<x;i++)
    {
        file.setFileName(path+"\\"+testlist[i]);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        data=file.readAll();
        file.close();
        QJsonDocument sd = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject sett2 = sd.object();
        appTitle=sett2.value(QString("app_title")).toString();
        gameNames.append(appTitle);
    }

}

QStringList Library::getGameNames() const
{
    return gameNames;
}
