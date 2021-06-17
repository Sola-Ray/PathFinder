#include "pathfinderapp.h"

PathFinderApp::PathFinderApp()
{
}

void PathFinderApp::loadData(FeatsModel &model)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/usr/share/Pathfinder/res/pathfinderfr-data.db");

    if(!db.open()) {
        qDebug() << db.lastError();
    } else {
        qDebug() << db.connectionName();
        qDebug() << db.isOpen();
        qDebug() << db.contains();

        qDebug() << db.tables();

        QSqlQuery query(db);
        query.exec("SELECT * FROM feats");
        while(query.next()) {
            model.addFeats(new Feats(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(),
                                     query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
                                     query.value(6).toString(), query.value(7).toString(), query.value(8).toString(),
                                     query.value(9).toString(), query.value(10).toString(), query.value(11).toString(),
                                     query.value(12).toString(), false));
        }
    }
}

//void PathFinderApp::loadFav(FeatsModel &model)
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("/usr/share/Pathfinder/res/pathfinderfr-data.db");

//    if(!db.open()) {
//        qDebug() << db.lastError();
//    } else {
//        qDebug() << db.connectionName();
//        qDebug() << db.isOpen();
//        qDebug() << db.contains();
//        qDebug() << db.tables();

//        QSqlQuery query(db);
//        if(!db.tables().contains("feats_fav")) {
//            query.exec("CREATE TABLE feats_fav (id integer PRIMARY key, version integer version, name text, description text, "
//                       "reference text, source text,summary text, category text, conditions text, requires text, advantage text, "
//                       "special text, normal text, isfav bool)");

//            qDebug() << "created";
//        } else {
//            query.exec("SELECT * FROM feats_fav");
//            while(query.next()) {
//                model.addFavFeats(new Feats(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(),
//                                         query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
//                                         query.value(6).toString(), query.value(7).toString(), query.value(8).toString(),
//                                         query.value(9).toString(), query.value(10).toString(), query.value(11).toString(),
//                                         query.value(12).toString(), true));
//            }
//        }
//    }
//}
