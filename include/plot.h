#ifndef PLOT_H
#define PLOT_H

#include "baton.h"

#include <QwtPlot>
#include <QElapsedTimer>
#include <QwtPlotCurve>


class Plot : public QwtPlot
{
public:
    Plot( double xInitPath, double yInitPath, double xInitBall1, double yInitBall1, double xInitBall2, double yInitBall2, QWidget* = NULL);
    void updateCurves(double newXPath, double newYPath, double newXBall1, double newYBall1, double newXBall2, double newYBall2, bool showBaton);

private:
    QPolygonF m_pointsPath;
    QPolygonF m_pointsBaton;
    QwtPlotCurve *m_curvePath;
    QwtPlotCurve *m_curveBaton;
    QElapsedTimer m_timer;

};

#endif // PLOT_H
