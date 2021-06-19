#ifndef PATHFINDERAPP_H
#define PATHFINDERAPP_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "featsmodel.h"
#include "iostream"
#include <QDebug>
#include <QSqlError>
#include <QFile>

using namespace std;

class PathFinderApp : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void updateIsFavFeat(Feats * feats);
    PathFinderApp();
    void loadData(FeatsModel &model);
private:
    QSqlDatabase m_db;
};

#endif // PATHFINDERAPP_H
