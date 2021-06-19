import QtQuick 2.0
import Sailfish.Silica 1.0

import FeatLib 1.0

Page {
    property Feat feat : null

    PageHeader {
        title: feat.name
        id: header
        IconButton {
            icon.source: "fav.png"
            icon.highlighted: feat.isFav

            function setFav() {
                if(!feat.isFav) {
                    feat.isFav = 1
                    icon.highlighted = true
                    pathFinderApp.updateIsFavFeat(feat)
                    console.log("Ajouté aux favoris !")
                }
                else {
                    feat.isFav = 0
                    icon.highlighted = false
                    pathFinderApp.updateIsFavFeat(feat)
                    console.log("Retiré des favoris !")
                }
            }
            onClicked: setFav()
            anchors.right: parent.right
        }
    }
    id: detailPage

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    Column {
        anchors.top: header.bottom
        width: parent.width

        Label {
            id: lblUnlock
            text: "Débloque : "
            width: parent.width
            wrapMode: "WordWrap"
        }
        Label {
            text: "Source : " + feat.source
            width: parent.width
            wrapMode: "WordWrap"
        }
        Label {
            text: "Catégorie : " + feat.category
            width: parent.width
            wrapMode: "WordWrap"
        }
        Label {
            text: "Conditions : " + feat.conditions
            width: parent.width
            wrapMode: "WordWrap"
        }
        Label {
            text: "Description : " + feat.description
            width: parent.width
            wrapMode: "WordWrap"
        }
    }
}
