//Mysaniquarium.cpp
#include <ctime>
#include <iostream>
#include <vector>
#include "functions.h"
#include "fish.h"
#include "food.h"

using namespace std;

const int SCREENWIDTH = 1920;
const int SCREENHEIGHT = 1080;

void addFish(float, float);
void feed(float, float);

vector<Fish> fish;
vector<Food> food;

void init(){
  srand(time(nullptr));	//Initialize random seed.
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);//Set clear color to black.
  Fish newFish(0, 0, 0);
  fish.push_back(newFish);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  background();
  for (int i = 0; i < fish.size(); i++){
	fish[i].drawFish();
	fish[i].update();
  }
  for (int j = 0; j < food.size(); j++){
	fish[j].eatFood(food[j]);
	food[j].draw();
	food[j].update();
  }
  //cout << "food size: " << food.size() << endl;
  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(75.0, (GLfloat) w/(GLfloat) h, 1.0, 16.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y){
   switch(key){
	case 27:
		exit(0);
		break;
   }
}

void mouse(int button, int state, int mx, int my){
   int window_width = glutGet(GLUT_WINDOW_WIDTH);
   int window_height = glutGet(GLUT_WINDOW_HEIGHT);
   float new_x = ((float)mx/(float)window_width) * 40.0f - 20.0f;
   float new_y = ((float)(window_height - my)/(float)window_height) * 20.0f - 10.0f;
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	addFish(new_x, new_y);
   }
   else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
	feed(new_x, new_y);
   }
}

void timerCallback(int value){
  //Every callback set new behavior.
  for (int i = 0; i < fish.size(); i++){
	fish[i].behavior(rand()%6);	//Call behavior function for each fish.
  }//Clean up food objects every callback.
  for (int j = 0; j < food.size(); j++){
	if(food[j].isEaten){
		food.erase(food.begin()+j);
	}
  }
  glutTimerFunc((rand()%5000)+1500, timerCallback, 0);	//Reset the timer.
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("MySaniquarium!");
  init();
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(3000, timerCallback, 0); //Call timerCallback after 3 seconds.
  glutMainLoop();
}

void addFish(float x, float y){
  if(fish.size() < 5){
  	Fish newFish(x, y, 0);
  	fish.push_back(newFish);
	//cout << "New fish added at " << x << ", " << y << ", 0" << endl;
  }
}

void feed(float x, float y){
  Food newFood(x, y, 0);
  food.push_back(newFood);
  //cout << "New food pellet added at " << x << ", " << y << ", 0" << endl;
}
