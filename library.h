#ifndef LIBRARY_H
#define LIBRARY_H
#include "game.h"
#include <QObject>
#include <QDir>
class Library
{
private:
    static QString pathToMetaData;
    void loadLibrary();
    QList<Game*> gameList;
public:
    Library();
    QList<Game*> getGameList() const;

};

#endif // LIBRARY_H

