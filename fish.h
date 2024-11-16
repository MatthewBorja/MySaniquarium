//fish.h
#ifndef FISH_H
#define FISH_H
#include <GL/glut.h>
#include "food.h"
class Fish{
	private:
		float x, y, z;			//Position
		const int SIZE = 5;
		float velocity;
		float angle;			//Angle of movement
	public:
		Fish(float, float, float);	//Constructor
		void drawFish();		//Draw a fish.
		void update();
		void behavior(int);		//Behaviors
		void setVelocity(float);
		void eatFood(Food&);
		void accelerate();		//Increase velocity.
		void decelerate();		//Decrease velocity.
		void changeAngle(float);	//Change angle.
		void turnAround();		//Reverse direction.
		friend class Food;

};
#endif
