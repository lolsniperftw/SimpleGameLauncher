#include "library.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QString Library::pathToMetaData=QDir::homePath()+"\\"+"\\.config\\legendary\\metadata";

Library::Library()
{
    loadLibrary();
}

void Library::loadLibrary()
{
    int gameCount,i;
    QString gameName,app_name,imgUrl;
    QByteArray data;
    QFile file;
    QJsonArray array;
    QDir files(pathToMetaData);
    QStringList fileList = files.entryList();
    gameCount=fileList.size();
    for(i=2;i<gameCount;i++)
    {
        file.setFileName(pathToMetaData+"\\"+fileList[i]);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        data=file.readAll();
        file.close();
        QJsonDocument sd = QJsonDocument::fromJson(data);
        QJsonObject sett2 = sd.object();
        gameName=sett2.value("app_title").toString();
        app_name=sett2.value("app_name").toString();
        array=sett2.value("metadata").toObject().value("keyImages").toArray();
        imgUrl=array[0].toObject().value("url").toString();
        gameList.append(new Game(gameName,app_name,imgUrl));
    }

}

QList<Game*> Library::getGameList() const
{
    return gameList;
}
