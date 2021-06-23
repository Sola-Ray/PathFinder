import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listFeats
        model: featsModel
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Dons")
        }
        delegate: FeatItem {
            id: delegate

            onClicked: pageStack.push("DetailFeatPage.qml", { feat: detailFeat } )
        }
        VerticalScrollDecorator {}
        SearchField{
            id: search
            onTextChanged: updateFilter()
        }
    }

    function updateFilter() {
        featsModel.setFilterFixedString(search.text)
    }

}
