# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = Pathfinder

CONFIG += sailfishapp

SOURCES += src/Pathfinder.cpp \
    src/feats.cpp \
    src/pathfinderapp.cpp

DISTFILES += qml/Pathfinder.qml \
    qml/cover/CoverPage.qml \
    qml/pages/DetailDonPage.qml \
    qml/pages/DonsPage.qml \
    qml/pages/FavPage \
    qml/pages/FavPage.qml \
    qml/pages/HomePage.qml \
    res/pathfinderfr-data.db \
    rpm/Pathfinder.changes.in \
    rpm/Pathfinder.changes.run.in \
    rpm/Pathfinder.spec \
    rpm/Pathfinder.yaml \
    translations/*.ts \
    Pathfinder.desktop \
    res/pathfinderfr-data.db

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/Pathfinder-de.ts

database.files = res
database.path = /usr/share/$${TARGET}


HEADERS += \
    src/feats.h \
    src/pathfinderapp.h

QT += sql

RESOURCES += \
    MyRes.qrc

INSTALLS += database
