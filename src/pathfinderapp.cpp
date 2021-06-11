#include "pathfinderapp.h"

PathFinderApp::PathFinderApp()
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
            int id = query.value(0).toInt();
            QString feat = query.value(1).toString();
            qDebug() << id << feat;
        }
    }

}
