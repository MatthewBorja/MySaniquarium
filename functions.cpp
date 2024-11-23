//functions.cpp
#include "functions.h"

void background(){
  glBegin(GL_QUADS);
    //Back Wall
    glColor3f(0.0, 0.0, 1.0);   //Blue
    glVertex3f(-20.0, -10.0, 0.0);
    glVertex3f(20.0, -10.0, 0.0);
    glColor3f(0.01, 0.71, 0.96);//Cerulean
    glVertex3f(20.0, 10.0, 0.0);
    glVertex3f(-20.0, 10.0, 0.0);
  glEnd();
  glBegin(GL_POLYGON);
    //Sandy Floor
    glColor3f(0.63, 0.54, 0.40);//Sandal
    glVertex3f(-20.0, -9.0, 0.0);       //Bottom-left corner
    glVertex3f(20.0, -9.0, 0.0);        //Bottom-right corner
    glVertex3f(20.0, -5.0, 0.0);        //Top-right corner
    glVertex3f(-20.0, -5.5, 0.0);       //Top-left corner
  glEnd();
  glBegin(GL_POLYGON);
    //Exposed sides of sandy floor-depths
    glColor3f(0.18, 0.10, 0.0);         //Cola
    glVertex3f(-20.0, -10.0, 0.0);      //Bottom-left corner
    glVertex3f(20.0, -10.0, 0.0);       //Bottom-right corner
    glVertex3f(20.0, -8.3, 0.0);        //Top-right corner
    glVertex3f(19.0, -8.2, 0.0);
    glVertex3f(18.0, -8.1, 0.0);
    glVertex3f(17.0, -8.0, 0.0);
    glVertex3f(16.0, -8.0, 0.0);
    glVertex3f(15.0, -8.0, 0.0);
    glVertex3f(14.0, -8.1, 0.0);
    glVertex3f(13.0, -8.1, 0.0);
    glVertex3f(12.0, -8.2, 0.0);
    glVertex3f(11.0, -8.3, 0.0);
    glVertex3f(10.0, -8.3, 0.0);
    glVertex3f(9.0, -8.4, 0.0);
    glVertex3f(8.0, -8.4, 0.0);
    glVertex3f(7.0, -8.5, 0.0);
    glVertex3f(6.0, -8.5, 0.0);
    glVertex3f(5.0, -8.6, 0.0);
    glVertex3f(4.0, -8.6, 0.0);
    glVertex3f(3.0, -8.7, 0.0);
    glVertex3f(2.0, -8.7, 0.0);
    glVertex3f(1.0, -8.7, 0.0);
    glVertex3f(0.0, -8.8, 0.0);
    glVertex3f(-1.0, -8.8, 0.0);
    glVertex3f(-2.0, -8.8, 0.0);
    glVertex3f(-3.0, -8.7, 0.0);
    glVertex3f(-4.0, -8.7, 0.0);
    glVertex3f(-5.0, -8.7, 0.0);
    glVertex3f(-6.0, -8.6, 0.0);
    glVertex3f(-7.0, -8.6, 0.0);
    glVertex3f(-8.0, -8.6, 0.0);
    glVertex3f(-9.0, -8.5, 0.0);
    glVertex3f(-10.0, -8.5, 0.0);
    glVertex3f(-11.0, -8.4, 0.0);
    glVertex3f(-12.0, -8.4, 0.0);
    glVertex3f(-13.0, -8.4, 0.0);
    glVertex3f(-14.0, -8.3, 0.0);
    glVertex3f(-15.0, -8.3, 0.0);
    glVertex3f(-16.0, -8.3, 0.0);
    glVertex3f(-17.0, -8.3, 0.0);
    glVertex3f(-18.0, -8.4, 0.0);
    glVertex3f(-19.0, -8.4, 0.0);
    glVertex3f(-20.0, -8.5, 0.0);       //Top-left corner
  glEnd();
}

