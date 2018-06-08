import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Controls 1.4

Page1Form {
    Item {
        anchors.fill: parent
        Item{//主界面标题实现
            id: uititle
            width:parent.width
            height: 30
            Text {
                anchors.fill: parent
                font.pointSize: 24
                text: qsTr("<b>订单记录</b>")
            }
        }
        Item {//图片显示区域
            x:0
            y:uititle.height
            width: parent.width - parent.width*0.6
            height: parent.height
            id: imgArea
            Image {
                id: screenimg
                anchors.fill: parent
                source: "./1.png"
            }

        }
        Item {//历史订单记录区域
            x:imgArea.width
            y:uititle.height
            width: parent.width - imgArea.width
            height: parent.height
            Item {//历史记录文本标题
                width: parent.width
                height: 14
                id: historytitle
                Text {
                    anchors.fill: parent
                    font.pointSize: 12
                    text: qsTr("<b>当前打印记录</b>")
                }
            }
            Item {//记录显示区域
                x:0
                y:historytitle.height
                width: parent.width
                height: parent.height-historytitle.height-uititle.height

                ListModel {
                    id: libraryModel
                    ListElement {
                        time: "A Masterpiece"
                        descreption: "Gabriel"
                    }
                    ListElement {
                        time: "Brilliance"
                        descreption: "Jens"
                    }
                    ListElement {
                        time: "Outstanding"
                        descreption: "Frederik"
                    }
                }
                TableView {
                    id:recordtable
                    anchors.fill: parent
                    TableViewColumn {
                        role: "time"
                        title: qsTr("订单时间")
                        width: 100
                    }
                    TableViewColumn {
                        role: "descreption"
                        title: qsTr("订单明细")
                        width: 200
                    }
                    model: libraryModel
                    onClicked: {
                        //获取行号
                        console.log("选中行号:"+recordtable.currentRow)
                        //获取订单描述
                        console.log(libraryModel.get(recordtable.currentRow).descreption)
                        //添加数据
                        libraryModel.insert(0,{"time":"12.21","descreption":"this is test"})
                    }
                }
            }
        }
    }
}
