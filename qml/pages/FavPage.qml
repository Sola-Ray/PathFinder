import QtQuick 2.0
import Sailfish.Silica 1.0

import FeatLib 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        model: favorites
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Favoris")
        }
        delegate: FeatItem {
            id: delegate
            onClicked: pageStack.push("DetailFeatPage.qml", { feat: detailFeat } )
        }
        VerticalScrollDecorator {}
    }

    function updateFilter() {
        favorites.setFilterFixedString(search.text)
    }
}
