//////////////////////////////////////////////////////////////////////////
var w = uiLoader.load('main.ui');
w.windowIcon = new QIcon('icon.png');
w.ui.taskPanel.setTitleBarWidget(new QWidget(w));


w.ui.actionNetwork.activated.connect(function() {
    network.showDialog();
});

//////////////////////////////////////////////////////////////////////////
w.ui.actionFull_screen.triggered.connect(function(fs) {
    if (fs) {
        w.showFullScreen();
    }
    else {
        w.showNormal();
    }
});

//////////////////////////////////////////////////////////////////////////
w.__proto__.closeEvent = function(evt) {
    //log('w.closeEvent:', evt.type());
    network.stop();
};


w;
