#include "mainwindow.h"

#include <QApplication>
#include <QwtLegend>
#include <QwtPlotGrid>

int main(int argc, char *argv[])
{
    double mass {1};
    double radius {1};
    double velocity {30};
    double angle {80};
    double length {4};
    double angVelocity {1};
    QApplication a(argc, argv);
    MainWindow w(mass, radius, velocity, angle, length, angVelocity);

    w.show();
    w.resize(1000,800);

    return a.exec();
}
