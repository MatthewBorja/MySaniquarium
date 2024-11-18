//food.h
#ifndef FOOD_H
#define FOOD_H
class Food{
	public:
		float x, y, z;
		float velocity;
		bool isEaten;
		Food(float, float, float);
		void draw();
		bool checkIfEaten(float, float, float);
		void setEaten();
		void update();
		friend class Fish;
};
#endif
