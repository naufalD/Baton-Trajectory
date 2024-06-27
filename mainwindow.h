#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "plot.h"
#include "baton.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(double mass, double radius, double velocity, double angle, double length, double angVelocity, QWidget *parent = nullptr);

protected:
    virtual void timerEvent( QTimerEvent* ) QWT_OVERRIDE;

private:
    Plot* m_plot;
    Plot* m_plotKE;
    Plot* m_plotPE;
    Baton* m_baton;
    QElapsedTimer m_timer;

};
#endif // MAINWINDOW_H
