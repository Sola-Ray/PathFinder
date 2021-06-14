import QtQuick 2.0
import Sailfish.Silica 1.0

ListItem {
    id: featItem
    contentHeight: 50

    Row {
        Label {
            text: name
        }
    }

    menu: ContextMenu {
        MenuItem {
            text: "Remove"
            onClicked: remove()
        }
    }

    function remove() {
        remorseAction("Deleting", function() {
            view.model.removeRows(index, 1)
        })
    }
}
