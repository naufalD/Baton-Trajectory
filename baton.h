#ifndef BATON_H
#define BATON_H

class Ball
{
public:
    Ball(double mass, double radius);
    double getBallMass();
    double getBallRadius();
    double getBallInertia();

private:
    double m_mass;
    double m_radius;
};

class Path
{
public:
    Path(double velocity, double angle);
    double getX(double time);
    double getY(double time);
    double getVx();
    double getVy(double time);

private:
    const double g {9.8};
    double m_initVelocity;
    double m_initVx;
    double m_initVy;
    double m_angle;
};

class Baton : public Ball, public Path
{
public:
    Baton(double mass, double radius, double velocity, double angle, double length, double angVelocity);
    double getBatonMass();
    double getBatonInertia();
    double getBall1x(double time);
    double getBall1y(double time);
    double getBall2x(double time);
    double getBall2y(double time);
    double getKE(double time);
    double getPE(double time);

private:
    const double g {9.8};
    double m_length;
    double m_angVelocity;
};

#endif // BATON_H
