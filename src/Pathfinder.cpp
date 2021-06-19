#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "favsortfilterproxymodel.h"
#include "featsmodel.h"
#include "pathfinderapp.h"

FavSortFilterProxyModel * initProxy(FeatsModel *model)
{
    FavSortFilterProxyModel *proxyModel = new FavSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    proxyModel->setSortRole(FeatsModel::FavRole);
    proxyModel->setFilterFixedString("1");
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

//    FeatsList* list = pApp.loadData(model);
//    QScopedPointer<FeatsList> feats(list);
//    view->rootContext()->setContextProperty("featslist", feats.data()); // Data est le get du ScopedPointer (get arrive en 5.11)


    FavSortFilterProxyModel *proxyModel = initProxy(&model);

    view->rootContext()->setContextProperty("featsModel", &model);
    view->rootContext()->setContextProperty("pathFinderApp", &pApp);
    view->rootContext()->setContextProperty("favorites", proxyModel);

    qmlRegisterType<Feats>("FeatLib", 1, 0, "Feat");
    qmlRegisterType<PathFinderApp>("FeatLib", 1, 0, "PathFinderApp");
//    qmlRegisterUncreatableType<FeatsList>("FeatLib",1,0,"FeatsList", "Le métier crée les données, pas la vue!");
//    qmlRegisterType<FeatsModel>("FeatLib", 1, 0, "FeatsModel");

    view->setSource(SailfishApp::pathToMainQml());
    view->show();

    return app->exec();
}
