import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    Column {
        IconButton {
            icon.source: "fav.png"
            onClicked: console.log("Ajouté aux favoris !")
            anchors.right: parent.right
        }

        Label {
            id: lblUnlock
            text: "Débloque :"
        }
        Label {
            text: "Source :"
        }
        Label {
            text: "Catégorie :"
        }
        Label {
            text: "Conditions :"
        }
        Label {
            text: "Description :"
        }
    }
}
