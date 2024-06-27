#include "mainwindow.h"
#include "plot.h"
#include "baton.h"

#include <QwtLegend>
#include <QwtPlotGrid>
#include <QLayout>

MainWindow::MainWindow(double mass, double radius, double velocity, double angle, double length, double angVelocity, QWidget *parent)
    : QWidget(parent)
{

    setWindowTitle("Landau 4.10");

    m_baton = new Baton(mass, radius, velocity, angle, length, angVelocity);

    m_plot = new Plot(m_baton->getX(0), m_baton->getY(0), m_baton->getBall1x(0), m_baton->getBall1y(0), m_baton->getBall2x(0), m_baton->getBall2y(0));
    m_plot->setTitle( "Baton" );
    m_plot->setCanvasBackground( Qt::white );
    //m_plot->setAxisScale( QwtAxis::YLeft, 0, 50 );
    //m_plot->setAxisScale( QwtAxis::XBottom, 0, 50 );

    m_plotPE = new Plot(0, m_baton->getPE(0), 0, 0, 0, 0);
    m_plotPE->setTitle( "Potential Energy" );
    m_plotPE->setCanvasBackground( Qt::white );
    //m_plotPE->setAxisScale( QwtAxis::YLeft, 0, 1000 );
    //m_plotPE->setAxisScale( QwtAxis::XBottom, 0, 10 );


    m_plotKE = new Plot(0, m_baton->getKE(0), 0, 0, 0, 0);
    m_plotKE->setTitle( "Kinetic Energy" );
    m_plotKE->setCanvasBackground( Qt::white );
    //m_plotKE->setAxisScale( QwtAxis::YLeft, 0, 600 );
    //m_plotKE->setAxisScale( QwtAxis::XBottom, 0, 10 );


    QVBoxLayout* layoutEnergy = new QVBoxLayout();
    layoutEnergy->addWidget( m_plotPE);
    layoutEnergy->addWidget( m_plotKE);

    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addWidget( m_plot, 60);
    layout->addLayout(layoutEnergy);


    m_timer.start();
    ( void )startTimer( 50 );
}

void MainWindow::timerEvent( QTimerEvent*)
{
    m_plot->updateCurves(m_baton->getX(m_timer.elapsed()*0.001), m_baton->getY(m_timer.elapsed()*0.001), m_baton->getBall1x(m_timer.elapsed()*0.001), m_baton->getBall1y(m_timer.elapsed()*0.001), m_baton->getBall2x(m_timer.elapsed()*0.001), m_baton->getBall2y(m_timer.elapsed()*0.001), true);
    m_plot->replot();

    m_plotPE->updateCurves(m_timer.elapsed()*0.001, m_baton->getPE(m_timer.elapsed()*0.001), 0, 0, 0, 0, false);
    m_plotPE->replot();

    m_plotKE->updateCurves(m_timer.elapsed()*0.001, m_baton->getKE(m_timer.elapsed()*0.001), 0, 0, 0, 0, false);
    m_plotKE->replot();
}
