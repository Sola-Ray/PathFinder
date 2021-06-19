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

//            Label {
//                x: Theme.horizontalPageMargin
//                text: qsTr("Don") + " " + index
//                anchors.verticalCenter: parent.verticalCenter
//                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
//            }
            onClicked: pageStack.push("DetailFeatPage.qml", { feat: detailFeat } )
        }
        VerticalScrollDecorator {}
        SearchField {  }
    }

}
