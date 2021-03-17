#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game
{
private:
    QString gameName;
    QString app_name;
    QString imgUrl;
public:
    Game(QString,QString,QString);
    QString getGameName() const;
    QString getAppName() const;
    QString getImgUrl() const;
};

#endif // GAME_H
