#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "favsortfilterproxymodel.h"
#include "featsmodel.h"
#include "pathfinderapp.h"

FavSortFilterProxyModel * initProxy(FeatsModel *model, FeatsModel::FeatsRoles role, QString filter)
{
    FavSortFilterProxyModel *proxyModel = new FavSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    proxyModel->setSortRole(role);
    proxyModel->setFilterFixedString(filter);
    proxyModel->setDynamicSortFilter(true);

    return proxyModel;
}



int main(int argc, char *argv[])
{
    auto app = SailfishApp::application(argc, argv);
    auto view = SailfishApp::createView();

    FeatsModel model;
    PathFinderApp pApp;

    pApp.loadData(model);

    FavSortFilterProxyModel *proxyModel = initProxy(&model, FeatsModel::FavRole, "1");
    FavSortFilterProxyModel *proxyModelSortOnName = initProxy(&model, FeatsModel::NameRole, "");

    view->rootContext()->setContextProperty("featsModel", proxyModelSortOnName);
    view->rootContext()->setContextProperty("pathFinderApp", &pApp);
    view->rootContext()->setContextProperty("favorites", proxyModel);

    qmlRegisterType<Feats>("FeatLib", 1, 0, "Feat");
    qmlRegisterType<PathFinderApp>("FeatLib", 1, 0, "PathFinderApp");
    qmlRegisterType<FeatsModel>("FeatLib", 1, 0, "FeatsModel");

    view->setSource(SailfishApp::pathToMainQml());
    view->show();

    return app->exec();
}
