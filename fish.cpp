//fish.cpp
#include <iostream>
#include <cmath>
#include "fish.h"
const int PI = 3.14159;

Fish::Fish(float tmpx, float tmpy, float tmpz){
	this->x = tmpx;
	this->y = tmpy;
	this->z = tmpz;
	this->angle = 0;
	this->velocity = 0;
}

void Fish::drawFish(){
	glColor3f(1.0, 1.0, 0.0);	//Yellow
	glBegin(GL_POLYGON);
	  glVertex3f(x, y, z);
	  if (angle < 90 || angle > 270){
	    glVertex3f(x-0.4, y+0.4, z);
	    glVertex3f(x-0.8, y+0.02, z);
	    glColor3f(1.0, 0.0, 0.0);	//Red
	    glVertex3f(x-1, y+0.4, z);
	    glVertex3f(x-1, y-0.4, z);
	    glColor3f(1.0, 1.0, 0.0);	//Yellow
	    glVertex3f(x-0.8, y-0.02, z);
	    glVertex3f(x-0.4, y-0.4, z);
	    glVertex3f(x, y, z);
	  }
	  else if (angle > 90 || angle < 270){
	    glVertex3f(x+0.4, y-0.4, z);
	    glVertex3f(x+0.8, y-0.02, z);
	    glColor3f(1.0, 0.0, 0.0);	//Red
	    glVertex3f(x+1, y-0.4, z);
	    glVertex3f(x+1, y+0.4, z);
	    glColor3f(1.0, 1.0, 0.0);	//Yellow
	    glVertex3f(x+0.8, y+0.02, z);
	    glVertex3f(x+0.4, y+0.4, z);
	  }
	glEnd();
}

void Fish::update(){
	x += velocity * cos(angle * PI/180);
	y += velocity * sin(angle * PI/180);
	if(x <= -18.0){
		changeAngle(0);
	}
	else if (x >= 19.0){
		changeAngle(180);
	}
	if (y >= 9.0){
		changeAngle(270);
	}
	else if (y <= -8.0){
		changeAngle(90);
	}
	glutPostRedisplay();	//Redraw the scene
}

void Fish::behavior(int choice){
	switch(choice){
	case 0:	//Stop
		setVelocity(0);
		break;
	case 1:	//Go right
		changeAngle(0);
		setVelocity(0.25);
		break;
	case 2: //Go left
		changeAngle(180);
		setVelocity(0.25);
		break;
	case 3: //Go diagonally up-right.
		changeAngle(30);
		setVelocity(0.25);
		break;
	case 4: //Go diagonally up-left.
		changeAngle(150);
		setVelocity(0.25);
		break;
	case 5: //Go diagonally down-right.
		changeAngle(330);
		setVelocity(0.25);
		break;
	case 6: //Go diagonally down-left.
		changeAngle(210);
		setVelocity(0.25);
		break;
	
	}
}

void Fish::setVelocity(float value){
	if(value <= 0.5)
		this->velocity = value;
}

void Fish::eatFood(Food& pellet){
	float distance = sqrt(pow(this->x - pellet.x, 2) + pow(this->y - pellet.y, 2));
	if(distance < 1.5){
		pellet.setEaten();
	}
}

void Fish::accelerate(){              //Increase velocity.
	if (velocity <= 0.5){
		this->velocity += 0.01;
	}
}

void Fish::decelerate(){              //Decrease velocity.
	this->velocity -= 0.1;
}

void Fish::changeAngle(float newangle){             //Change angle.
	this->angle = newangle;
}

void Fish::turnAround(){              //Reverse direction.
	std::cout << "Turning around!" << std::endl;
	if (0 <= angle || angle <= 180.0)
		this->angle += 180.0;
	else
		this->angle -= 180.0;
}
