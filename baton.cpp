#include "baton.h"
#include <cmath>

#define _USE_MATH_DEFINES

Ball::Ball(double mass, double radius){
    m_mass = mass;
    m_radius = radius;
}

double Ball::getBallMass(){
    return m_mass;
}

double Ball::getBallRadius(){
    return m_radius;
}

double Ball::getBallInertia(){
    return (2 / 5) * m_mass * pow(m_radius, 2);
}


Path::Path(double velocity, double angle){
    m_initVelocity = velocity;
    m_angle = angle;
    m_initVx = velocity * cos(angle * M_PI / 180);
    m_initVy = velocity * sin(angle * M_PI / 180);
}

double Path::getX(double time){
    return m_initVx * time;
}

double Path::getY(double time){
    return m_initVy * time - 0.5 * g * pow(time, 2);
}

double Path::getVx(){
    return m_initVx;
}

double Path::getVy(double time){
    return m_initVy - g * time;
}

Baton::Baton(double mass, double radius, double velocity, double angle, double length, double angVelocity):Ball {mass, radius}, Path {velocity, angle}{
    m_length = length;
    m_angVelocity = angVelocity;
}

double Baton::getBatonMass(){
    return 2 * getBallMass();
}

double Baton::getBatonInertia(){
    return 2 * getBallInertia() + 0.5 * getBallMass() * pow(m_length, 2);
}

double Baton::getBall1x(double time){
    return getX(time) + 0.5 * m_length * cos(m_angVelocity * time);
}

double Baton::getBall1y(double time){
    return getY(time) + 0.5 * m_length * sin(m_angVelocity * time);
}

double Baton::getBall2x(double time){
    return getX(time) - 0.5 * m_length * cos(m_angVelocity * time);
}

double Baton::getBall2y(double time){
    return getY(time) - 0.5 * m_length * sin(m_angVelocity * time);
}

double Baton::getKE(double time){
    return 0.5 * getBatonMass() * (pow(getVx(), 2) + pow(getVy(time), 2));
}

double Baton::getPE(double time){
    return getBatonMass() * g * getY(time);
}




