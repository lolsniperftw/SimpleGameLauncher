#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QDir>
class Library
{
private:
    static QString pathToMetaData;
    void loadLibrary();
    QStringList gameNames;
public:
    Library();
    QStringList getGameNames() const;

};

#endif // LIBRARY_H

