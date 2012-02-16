
// var res = include("P:/projects/r3/repo/runtime/Debug/client/test.js");
// print("from main2: ", script.filePath, ", ", res);


importExtension('qt');
importExtension('qt.core');
importExtension('qt.gui');
importExtension('qt.uitools');
importExtension('qt.sql');


function AnalogClock(parent) {

    QWidget.call(this, parent);

    var timer = new QTimer(this);
    timer.timeout.connect(this, "update()");
    timer.start(1000);

    this.setWindowTitle("Analog Clock");
    this.resize(200, 200);
}

AnalogClock.prototype = new QWidget();

AnalogClock.prototype.paintEvent = function() {
    var side = Math.min(this.width, this.height);
    var time = new Date();

    var painter = new QPainter();
    painter.begin(this);
    painter.setRenderHint(QPainter.Antialiasing);
    painter.translate(this.width / 2, this.height / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(new QPen(Qt.NoPen));
    painter.setBrush(new QBrush(AnalogClock.hourColor));

    painter.save();
    painter.rotate(30.0 * ((time.getHours() + time.getMinutes() / 60.0)));
    painter.drawConvexPolygon(AnalogClock.hourHand);
    painter.drawLine(0, 0, 100, 100);
    painter.restore();

    painter.setPen(AnalogClock.hourColor);

    for (var i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(new QPen(Qt.NoPen));
    painter.setBrush(new QBrush(AnalogClock.minuteColor));

    painter.save();
    painter.rotate(6.0 * (time.getMinutes() + time.getSeconds() / 60.0));
    painter.drawConvexPolygon(AnalogClock.minuteHand);
    painter.restore();

    painter.setPen(AnalogClock.minuteColor);

    for (var j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
	        painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
    
    
    painter.setPen(new QPen(Qt.NoPen));
    painter.setBrush(new QBrush(AnalogClock.secondColor));

    painter.save();
    painter.rotate(6.0 * (time.getSeconds()));
    painter.drawConvexPolygon(AnalogClock.secondHand);
    painter.restore();

    painter.end();
};

AnalogClock.hourColor = new QColor(127, 0, 127);

AnalogClock.minuteColor = new QColor(0, 127, 127, 191);

AnalogClock.secondColor = new QColor(0, 0, 127, 127);

AnalogClock.hourHand = new QPolygon([new QPoint(7, 8),
                                     new QPoint(-7, 8),
                                     new QPoint(0, -40)]);
                                     
AnalogClock.minuteHand = new QPolygon([new QPoint(7, 8),
                                       new QPoint(-7, 8),
                                       new QPoint(0, -70)]);

AnalogClock.secondHand = new QPolygon([new QPoint(3, 3),
                                       new QPoint(-3, 3),
                                       new QPoint(0, -90)]);

var clock = new AnalogClock();
clock.show();

QCoreApplication.exec();
