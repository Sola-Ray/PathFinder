import QtQuick 2.0
import Sailfish.Silica 1.0

ListItem {
    id: featItem
    contentHeight: 50

    Row {
        Label { text: index + " - " }

        TextInput {
            text: name
            onAccepted: {
                name = text
                focus = false
            }
        }

        Label { text: " -> " + id }
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
