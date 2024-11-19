//food.cpp
#include <GL/glut.h>
#include <cmath>
#include "food.h"

const float PI = 3.14159;

Food::Food(float newx, float newy, float newz){
	this->x = newx;
	this->y = newy;
	this->z = newz;
	this->velocity = 0.2;
	this->isEaten = false;
}

void Food::draw(){
	if(!isEaten){
		glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidSphere(0.1, 10, 10);
		glPopMatrix();
	}
}

bool Food::checkIfEaten(float fishX, float fishY, float fishZ){
	float distance = sqrt(pow(fishX - x, 2) + pow(fishY - y, 2) + pow(fishZ - z, 2));
	if (distance < 1){
		isEaten = true;
		return true;
	}
	return false;
}

void Food::setEaten(){
	isEaten = true;
}

void Food::update(){
	y += velocity * sin(270 * PI/180);
	if (y <= -8.0){
		isEaten = true;
	}
	glutPostRedisplay();
}
