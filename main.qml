﻿import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.VirtualKeyboard 2.1

ApplicationWindow {
    id: window
    visible: true
    width: 480
    height: 700
    title: qsTr("WeChat Printer")


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1{

        }

        Page2{

        }
        Page3{

        }
    }

    footer: TabBar {
        id: tabBar
        height: 40
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("历史订单记录")
        }
        TabButton {
            text: qsTr("硬件配置")
        }
        TabButton {
            text: qsTr("软件配置")
        }
    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
