#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "featsmodel.h"
#include "pathfinderapp.h"

int main(int argc, char *argv[])
{
    FeatsModel model;
    PathFinderApp pApp;

    pApp.loadData(model);

    auto app = SailfishApp::application(argc, argv);
    auto view = SailfishApp::createView();

    view->rootContext()->setContextProperty("featsModel", &model);
    qmlRegisterType<Feats>("FeatLib", 1, 0, "Feat");

    view->setSource(SailfishApp::pathToMainQml());
    view->show();

    return app->exec();

    //return SailfishApp::main(argc, argv);
}
