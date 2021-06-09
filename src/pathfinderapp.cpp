#include "pathfinderapp.h"

PathFinderApp::PathFinderApp()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":/res/pathfinderfr-data.db");

    if(!db.open()) {
        cout << "Error load db" << endl;
        qDebug() << db.lastError();
    } else {
        qDebug() << db.connectionName();
        qDebug() << db.isOpen();
        qDebug() << db.contains();

        qDebug() << db.tables();
        QSqlQuery query(db);
        query.prepare("SELECT * FROM feats");
        while(query.next()) {
            qDebug("id = %d, name = %s.", query.value(0).toInt(), qPrintable(query.value(2).toString()));
        }
    }

}
