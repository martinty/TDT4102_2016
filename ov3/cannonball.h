//
// Created by tysse on 02.02.2018.
//

#ifndef OV3_CANNONBALL_H
#define OV3_CANNONBALL_H


double acclY();
double acclX();
double velocityY(double initVelocityY, double time);
double velocityX(double initVelocityX, double time);
double posY(double initVelocityY, double time);
double posX(double initVelocityX, double time);
void printTime(double time);
double flightTime(double initVelocityY);
void testFunctions();
void getUserInput(double *theta, double *absVelocity);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
void testTargetPractice();
void playTargetPractice();

#endif //OV3_CANNONBALL_H
