#ifndef MANU_CPP_
#define MANU_CPP_
#include"Manu.h"
#include<fstream>
//Constructor for Manu
Manu::Manu():player()
{
    screen=-2; //Default manu screen
}
//Getter, setter for manus
void Manu::setscreen(int s)
{
    screen=s;
}
int Manu::getscreen()const
{
    return screen;
}
void Manu::DisplayHelp()
{
    glClearColor( 1, 1 , 1 ,  1 );//SET THE SCREEN COLOUR
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
    DrawRoundRect(-10,-10,1040,20,colors[BLACK]);
    DrawRoundRect(-10,-10,20,850 ,colors[BLACK]) ;
    DrawRoundRect(-10,830,1040,20,colors[BLACK]);
    DrawRoundRect(1010,-10,20,870,colors[BLACK]);
	DrawString( 150,690, "USER GUIDELINE:                          ", colors[DARK_RED]);
	DrawString( 150,600, "MOVEMENT                               ", colors[DARK_RED]);  
    DrawString( 150,560, "Press and Drag the Mouse to make Match    ", colors[BLACK]);
    DrawString( 150,530, "Find Match of three or More Candies to Distory   ", colors[BLACK]);
    DrawString( 150,500, "If you Find trouble, You can get Hint by Pressing H  ", colors[BLACK]);
  
    DrawString( 150,460, " ABOUT GAME      ", colors[DARK_RED]); 
    DrawString( 150,420, "This game have infinite Levels        ", colors[BLACK]); 
    DrawString( 150,390, "There are Two mode in this Game  ", colors[BLACK]);
    DrawString( 150,330, "TIME TRIAL MODE:                          ", colors[DARK_RED]);  
    DrawString( 150,270, "You have to Reached the Target before Time Run Out        ", colors[BLACK]); 
    DrawString( 150,240, "You can make as many move as possible in that Time       ", colors[BLACK]);   
    
    DrawString( 150,200, " NORMAL MODE     ", colors[DARK_RED]);
    DrawString( 150,170, " You Have to Reached the Target  in Specific Moves       ", colors[BLACK]);   
    DrawString( 150,110, "PRESS B TO GO BACK                      ", colors[DARK_RED]);
    glutSwapBuffers();
    glutPostRedisplay();
}

//Manu displaying function. 
void Manu::ManuDisplay()
{
    glClearColor(1, 0, 0, 1);
    glClear (GL_COLOR_BUFFER_BIT);
    DrawRoundRect(-10,-10,1040,30,colors[BLACK]);
    DrawRoundRect(-10,-10,30,850,colors[BLACK]) ;
    DrawRoundRect(-10,820,1040,30,colors[BLACK]);
    DrawRoundRect(1000,-10,30,870,colors[BLACK]);
    static int x=100,state=0;static float* ptr=colors[ORANGE];
    int val;
    if(state==1)
    val=960-x+4;
    else
    val=x-4;
    DrawRectangle(x,20,45,50,ptr);
    DrawRectangle(20,752,val,70,colors[BLACK]);
    DrawString(300,770,"WELLCOME     TO     OPP      PROJECT ", colors[RED]);
    switch(state)
    {
        case 0:
        {   
            if(x<960)
            x+=5;
            else 
            {
                state=1;
                ptr=colors[BLUE_VIOLET];
            }
            break;
        }
        case 1:
        {
            if(x>10)
            x-=5;
            else
            {
                state=0;
                ptr=colors[ORANGE];
            }
            break;
        }
    }
    //C//Medium-voiled-red
    DrawLine(100,100,160,100,10,colors[DARK_BLUE]);
    DrawLine(160,200,100,200,10,colors[DARK_BLUE]);
    DrawLine(100,100,100,200,10,colors[DARK_BLUE]);
    //A
    DrawLine(180,100,220,200,10,colors[DARK_BLUE]);
    DrawLine(260,100,220,200,10,colors[DARK_BLUE]);
    DrawLine(200,140,240,140,10,colors[DARK_BLUE]);
    //N
    DrawLine(280,100,280,200,10,colors[DARK_BLUE]);
    DrawLine(350,100,280,200,10,colors[DARK_BLUE]);
    DrawLine(350,100,350,200,10,colors[DARK_BLUE]);
    //D
    DrawLine(370,100,370,200,10,colors[DARK_BLUE]);
    DrawLine(370,100,410,100,10,colors[DARK_BLUE]);
    DrawLine(410,200,370,200,10,colors[DARK_BLUE]);
    DrawLine(410,200,410,100,10,colors[DARK_BLUE]);
    //y
    DrawLine(430,200,450,130,10,colors[DARK_BLUE]);
    DrawLine(470,200,450,130,10,colors[DARK_BLUE]);
    DrawLine(450,80,450,130,10 ,colors[DARK_BLUE]);
    DrawLine(450,80,120,80,10  ,colors[DARK_BLUE]);
    //C
    DrawLine(530,100,590,100,10,colors[DARK_BLUE]);
    DrawLine(590,200,530,200,10,colors[DARK_BLUE]);
    DrawLine(530,100,530,200,10,colors[DARK_BLUE]);
    //R
    DrawLine(610,200,610,100,10,colors[DARK_BLUE]);
    DrawLine(640,150,610,150,10,colors[DARK_BLUE]); 
    DrawLine(610,200,640,200,10,colors[DARK_BLUE]); 
    DrawLine(640,150,640,202,10,colors[DARK_BLUE]); 
    DrawLine(660,100,610,150,10,colors[DARK_BLUE]);     
    //U
    DrawLine(680,100,680,200,10,colors[DARK_BLUE]); 
    DrawLine(720,200,720,100,10,colors[DARK_BLUE]);
    DrawLine(680,100,720,100,10,colors[DARK_BLUE]);  
    //S
    DrawLine(780,100,740,100,10,colors[DARK_BLUE]);  
    DrawLine(738,150,780,150,10,colors[DARK_BLUE]);  
    DrawLine(780,100,780,152,10,colors[DARK_BLUE]); 
    DrawLine(740,150,740,200,10,colors[DARK_BLUE]);
    DrawLine(780,200,740,200,10,colors[DARK_BLUE]);  
    //H
    DrawLine(800,100,800,200,10,colors[DARK_BLUE]);
    DrawLine(800,150,840,150,10,colors[DARK_BLUE]);      
    DrawLine(840,100,840,200,10,colors[DARK_BLUE]);      


    DrawRectangle(100,230,750,30,colors[BLACK]);
    DrawRectangle(100,700,750,30,colors[BLACK]);
    DrawRectangle(100,230,30,500,colors[BLACK]);
    DrawRectangle(840,230,30,500,colors[BLACK]);
    //Drawing Manu
    DrawRoundRect(150,630,500,40,colors[WHITE]);
    DrawString(160,640,"1) START NEW GAME       Press  S ", colors[BLACK]);
       
    DrawRoundRect(150,570,500,40,colors[WHITE]);
    DrawString(160,580,"2) RESUME                           Press  R ",colors[BLACK]);
      
    DrawRoundRect(150,510,500,40,colors[WHITE]);
    DrawString(160,520,"3) PLAYER INFO                  Press  I ",colors[BLACK]);
       
    DrawRoundRect(150,450,500,40,colors[WHITE]); 
    DrawString(160,460,"4) SELECT MODE                Press  M ",colors[BLACK]);
        
    DrawRoundRect(150,390,500,40,colors[WHITE]);
    DrawString(160,400,"5) HELP                                  Press H ",colors[BLACK]);
    DrawRoundRect(150,330,500,40,colors[WHITE]);
    DrawString(160,340,"6) EXIST                                Press Esc  ",colors[BLACK]); 
    
    glutSwapBuffers();
    glutPostRedisplay();
}


//Destructor for Manu classs
Manu::~Manu()
{}
#endif