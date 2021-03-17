#include "game.h"

Game::Game(QString gameName, QString app_name, QString imgUrl)
{
   this->gameName=gameName;
   this->app_name=app_name;
   this->imgUrl=imgUrl;
}
QString Game::getGameName() const
{
    return gameName;
}
QString Game::getAppName() const
{
    return app_name;
}
QString Game::getImgUrl() const
{
    return imgUrl;
}
