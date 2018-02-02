//
// Created by tysse on 02.02.2018.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
using namespace std;
#define PI 3.14159265
#include "cannonball.h"
#include "utilities.h"


void testFunctions(){
    for(int t = 0; t<3; t++){
        double time = t*2.5;
        cout << "Time = "; printTime(time);
        cout << "acclX = " << acclX() << endl;
        cout << "acclY = " << acclY() << endl;
        cout << "velX = " << velocityX(50, time) << endl;
        cout << "velY = " << velocityY(25, time) << endl;
        cout << "posX = " << posX(50, time) << endl;
        cout << "posY = " << posY(25, time) << endl;
        cout << "FlightTime = "; printTime(flightTime(25));
        cout<<setfill('-')<<setw(60)<<"-"<<endl;
    }
}

double acclY(){
    return -9.81;
}

double acclX(){
    return 0;
}

double velocityY(double initVelocityY, double time){
    return initVelocityY + acclY() * time;
}

double velocityX(double initVelocityX, double time){
    return initVelocityX + acclX() * time;
}

double posY(double initVelocityY, double time){
    return initVelocityY*time + acclY()*time*time/2;
}

double posX(double initVelocityX, double time){
    return initVelocityX*time + acclX()*time*time/2;
}

void printTime(double time){
    int intTime = int(time);
    double decimalSecond = time - double(intTime);
    int second = intTime%60;
    int min = ((intTime - second)/60)%60;
    int hour = (((intTime - second)/60)-min)/60;
    double doubleSecond = double(second) + decimalSecond;
    cout << hour << " timer, " << min << " minutter og " << doubleSecond << " sekunder" << endl;
}

double flightTime(double initVelocityY){
    return abs(initVelocityY/acclY() * 2);
}

void getUserInput(double *theta, double *absVelocity){
    cout << "Theta [degree]: ";
    cin >> *theta;
    cout << "Abs Velocity [m/s]: ";
    cin >> *absVelocity;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity * cos(theta*PI/180);
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity * sin(theta*PI/180);
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY){
    *velocityX = absVelocity * cos(theta*PI/180);
    *velocityY = absVelocity * sin(theta*PI/180);
}

double getDistanceTraveled(double velocityX, double velocityY){
    return velocityX * flightTime(velocityY);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void testTargetPractice(){
    double distanceToTarget = 100;
    cout << "Distance To Target [m]: " << distanceToTarget << endl;
    double theta, absVelocity, velocityX, velocityY;
    getUserInput(&theta, &absVelocity);
    getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
    double distanceFromTarget = targetPractice(distanceToTarget, velocityX, velocityY);
    cout << "Distance From Target [m]: " << distanceFromTarget << endl;
}

void playTargetPractice(){
    double theta, absVelocity, velocityX, velocityY, distanceToTarget;
    distanceToTarget = double(randomWithLimits(100, 1000));
    bool win = false;
    cout << "Kanonkulespill\n" << endl;
    for(int i = 0; i < 10; i++){
        getUserInput(&theta, &absVelocity);
        getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
        double distanceFromTarget = targetPractice(distanceToTarget, velocityX, velocityY);
        cout << "Distance From Target [m]: " << distanceFromTarget << endl;
        cout<<setfill('-')<<setw(40)<<"-"<<endl;
        if (abs(distanceFromTarget) < 5){
            win = true;
            break;
        }
    }
    if (win){
        cout << "Gratulerer, du vant!" << endl;
    } else{
        cout << "Beklager, du tapte!" << endl;
    }
}