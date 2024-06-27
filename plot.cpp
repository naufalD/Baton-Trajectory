#include "plot.h"

#include <QwtPlotCurve>
#include <QwtPlot>
#include <QWidget>
#include <QwtPlotLayout>


Plot::Plot( double xInitPath, double yInitPath, double xInitBall1, double yInitBall1, double xInitBall2, double yInitBall2, QWidget* parent ) : QwtPlot(parent)
{
    m_pointsPath << QPointF( xInitPath, yInitPath );
    m_pointsBaton << QPointF( xInitBall1, yInitBall1 )<< QPointF( xInitBall2, yInitBall2 );

    plotLayout()->setCanvasMargin( 10 );
    setMinimumSize(300,300);

    m_curvePath = new QwtPlotCurve();
    m_curvePath -> setPen(Qt::black, 2);
    m_curvePath -> setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curvePath -> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curvePath -> setSamples(m_pointsPath);
    m_curvePath -> attach(this);

    m_curveBaton = new QwtPlotCurve();
    m_curveBaton -> setPen(Qt::red, 4);
    m_curveBaton -> setCurveAttribute(QwtPlotCurve::Fitted, true);
    m_curveBaton -> setRenderHint( QwtPlotItem::RenderAntialiased, true );
    m_curveBaton -> setSamples(m_pointsBaton);
    m_curveBaton -> attach(this);
}

void Plot::updateCurves(double newXPath, double newYPath, double newXBall1, double newYBall1, double newXBall2, double newYBall2, bool showBaton)
{
    m_pointsPath << QPointF(newXPath, newYPath);
    m_curvePath->setSamples( m_pointsPath );

    m_pointsBaton.clear();
    if (showBaton){
        m_pointsBaton << QPointF( newXBall1, newYBall1)<< QPointF( newXBall2, newYBall2);
        m_curveBaton->setData(NULL);
        m_curveBaton->setSamples( m_pointsBaton );
    }
}
