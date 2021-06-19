#include "pathfinderapp.h"

PathFinderApp::PathFinderApp()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/usr/share/Pathfinder/res/pathfinderfr-data.db");
}

void PathFinderApp::loadData(FeatsModel &model)
{
    FeatsList * list = new FeatsList();
    if(!m_db.open()) {
        qDebug() << m_db.lastError();
    } else {
        qDebug() << m_db.connectionName();
        qDebug() << m_db.isOpen();
        qDebug() << m_db.contains();

        qDebug() << m_db.tables();

        QSqlQuery query(m_db);
        query.exec("SELECT * FROM feats");

        while(query.next()) {
             list->push_back(new Feats(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(),
                                     query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
                                     query.value(6).toString(), query.value(7).toString(), query.value(8).toString(),
                                     query.value(9).toString(), query.value(10).toString(), query.value(11).toString(),
                                     query.value(12).toString(), query.value(13).toInt()));
        }
        model.setList(list);
    }
    //return list;
}

void PathFinderApp::updateIsFavFeat(Feats * feats)
{
    if(!m_db.open()) {
        qDebug() << m_db.lastError();
    } else {
        qDebug() << "IS UPDATING " << feats->isFav();
        QSqlQuery query(m_db);
        query.prepare("UPDATE feats SET isfav = :isfav WHERE id = :id");
        query.bindValue(":isfav", feats->isFav());
        query.bindValue(":id", feats->id());
        query.exec();
    }
}
