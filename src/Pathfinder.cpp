#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "pathfinderapp.h"

int main(int argc, char *argv[])
{

//    auto app = SailfishApp::application(argc, argv);
//    auto view = SailfishApp::createView();

    PathFinderApp pApp;

//    view->rootContext()->setContextProperty("NI", &ni);
//    view->setSource(SailfishApp::pathToMainQml());
//    view->show();

//    return app->exec();

    return SailfishApp::main(argc, argv);
}
