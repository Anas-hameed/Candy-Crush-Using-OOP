//============================================================================
// Name        : .cpp
// Author      : Anas Hameed
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<fstream>
//#include"shapes.h"
#include<string>
#include<cstdlib> 
#include<ctime>
#include"Grid.h"
#include"Manu.h"
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
Grid px;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
void GameDisplay()
{	
	if(px.getlife()==0)
	px.setscreen(4);
	else if(px.getscreen()==1)
	{
		px.Display(1);
		if(px.getMove()!=0)
		px.CheckRandomMakedMatches(1);
		px.checkCondition();
	}
	else if(px.getscreen()==0 )
	{  
		px.ManuDisplay();
	}
	else if(px.getscreen()==2)
	{
		px.DisplayHelp();
	}
	else if(px.getscreen()==3)
	{
		px.PouseScreen();
	}
	else if(px.getscreen()==5)
	{
		px.DisplayPlayerInfo();
	}
	else if(px.getscreen()==-2)
	{
		px.TakeInputandDisplay();
	}
	else if(px.getscreen()==-3)
	{
		px.selectmode();
	}
	else if(px.getscreen()==4)
	{
		px.gameOverScreen();
	}
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT ) {
		px.SetRandom();

	}  else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */  
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if(px.getscreen()==0 )
	{
		if(( key=='S' || key=='s'))
		px.setscreen(1);
		else if(key=='M' || key=='m') 
		{
			px.setscreen(-3);
			px.selectmode();	
		}
		else if(key=='H' || key=='h')
		px.setscreen(2);
		else if(key=='i' || key=='I')
		px.setscreen(5);
	}
	else if(px.getscreen()==5)
	{
		if(key=='b' || key=='B')
		px.setscreen(0);
	}
	else if(px.getscreen()== 1)
	{
		if(key=='H' || key=='h')
		px.PrivideHint();
		else if(key=='p'|| key=='P')
		px.setscreen(3);
	}
	else if(px.getscreen()== 3)
	{
		if(key=='R' || key=='r')
		px.setscreen(1);
	}
	else if(px.getscreen()==2)
	{
		if(key=='B' || key=='b')
		px.setscreen(0);
	}
	else if(px.getscreen()==4)
	{
		if(key=='s' || key=='S')
		{
			px.setscreen(0);
			px.setlife(3);
			px.setLevel(0);
			px.settarget(2000);
			px.settime(80);
			px.setMove(40);
		}
	}
	else if(px.getscreen()==-3)
	{
		if(key=='N' || key=='n')
		px.setMode(1);
		else if(key=='T'  || key=='t')
		px.setMode(0);
		else if(key=='E' || key=='e')
		px.setscreen(0);
	}
	else if(px.getscreen()==-2 )
	{
		if(key!='1')
		px.setName(key);
		else
		{
			px.saveName();
			px.setscreen(0);
		}
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}
}
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	if(px.getscreen()==1)
	{
		static int x=0;
		x++;
		if(x==1)
		{
			int t= px.gettime();
			px.settime(--t);
			x=0;
		}
	}
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */ 
void MousePressedAndMoved(int x, int y)
{
	y+=30;
	if(px.getscreen()==1)
	px.ShowMouseMovement(x,y);
	glutSwapBuffers();
}  
// this give coordinate of mouse movement.
void MouseMoved(int x, int y)
{
	
	//cout<<"X= "<<x<<"   y= "<<y<<endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x , int y) 
{
	y=840-(y*825/655);
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if(px.getscreen()==1)
		{
			px.Swapposition(x,y);
		}
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
	cout<<"Right Button Pressed"<<endl;
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 840 x 600

	InitRandomizer(); // seed the random number generator...
	srand(time(0));
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
