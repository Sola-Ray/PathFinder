import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.LocalStorage 2.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Les dons")
                onClicked: pageStack.push(Qt.resolvedUrl("FeatsPage.qml"))
            }
            MenuItem {
                text: qsTr("Favoris")
                onClicked: pageStack.push(Qt.resolvedUrl("FavPage.qml"))
            }
        }

        // Tell SilicaFlickable the height of its content.
        contentHeight: column.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
            PageHeader {
                title: qsTr("Accueil Pathfinder")
            }

            Row {
                Button {
                    text: qsTr("Dons")
                    onClicked: pageStack.push(Qt.resolvedUrl("FeatsPage.qml"))
                }

                Button {
                    text: qsTr("Favoris")
                    onClicked: pageStack.push(Qt.resolvedUrl("FavPage.qml"))
                }
                width: parent.width
            }

            Label {
                text: qsTr("Pour commencer, vous devez télécharger les données de l'application en cliquant sur le bouton ci-dessous.")
                width: parent.width
                wrapMode: "WordWrap"
            }
//            Button {
//                text: qsTr("Démarrer")
////                function loadData() {
////                    var db = LocalStorage.openDatabaseSync("pathfinderfr-data.db", "1.0", "Pathfinder Data", 1000000)

////                    db.transaction(function(tx) {
////                        var results = tx.executeSql('SELECT name FROM skills')
////                        for (var i = 0; i < results.rows.length; i++) {
////                            console.log(results.rows.item(i))
////                        }
////                    })
////                }
//                onClicked: loadData()
//            }

        }
    }
}
