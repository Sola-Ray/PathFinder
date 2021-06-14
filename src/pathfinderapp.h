#ifndef PATHFINDERAPP_H
#define PATHFINDERAPP_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "featsmodel.h"
#include "iostream"
#include <QDebug>
#include <QSqlError>
#include <QFile>

using namespace std;

class PathFinderApp
{
public:
    PathFinderApp();
    void loadData(FeatsModel &model);
};

#endif // PATHFINDERAPP_H
