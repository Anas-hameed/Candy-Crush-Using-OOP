#ifndef GAMEMODE_CPP_
#define GAMEMODE_CPP_
#include"gamemode.h"
gamemode::gamemode()
{
    target=2000;mode=1;score=0;
    time=80;Move=40;life=3;levels=1;
}
void gamemode::settarget(int t)
{
    target=t;
}
int  gamemode::gettarget()const
{
    return target;
}
void gamemode::setMove(int m)
{
    Move=m;
}
int gamemode::getMove()const
{
    return Move;
}
void gamemode::setlife(int l)
{
    life=l;
}
int gamemode::getlife()const
{
    return life;
}
void gamemode::settime(int t)
{
    time=t;
}
int  gamemode::gettime()const
{
    return time;
}
void gamemode::setLevel(int l)
{
    levels=l;
}
void gamemode::setscore( int s )
{
    score=s;
}
int gamemode::getscore()const
{
    return score;
}
int gamemode::getlevel()const
{
   return levels; 
}
void gamemode::setMode(int M)
{
    mode=M;
}
int gamemode::getMode()const
{
    return mode;
}
void gamemode::selectmode()
{
    glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0.0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
    //Boder
    DrawRoundRect(-10,-10,1040,30,colors[BLACK]);
    DrawRoundRect(-10,-10,30,850,colors[BLACK]) ;
    DrawRoundRect(-10,820,1040,30,colors[BLACK]);
    DrawRoundRect(1000,-10,30,870,colors[BLACK]);
    //Center rectangle
    DrawRectangle(100,200,700,500,colors[RED]);
    DrawRectangle(120,220,660,460,colors[BLACK]);
    //Drawing Option
    DrawString(200,600,"PRESS   T    TO   SELECT   TIME  TRIAL   MODE", colors[RED]);
    DrawString(200,560,"PRESS   N    TO   SELECT       NORMAL     MODE", colors[RED]);
    DrawString(200,520,"PRESS   E    TO   GO BACK  TO    MAIN    MANU     ", colors[RED]);
    DrawRectangle(190,307,350,50,colors[WHITE]);
    DrawString(200,320,"CURRENT SELECTED MODE", colors[RED]);
    if(mode==1)
    {
       // DrawRectangle(190,300,300,60,colors[WHITE]);
        DrawString(200,250,"NORMAL MODE           ", colors[RED]);
    }
    else
    {
        DrawString(200,280,"TIME TRIAL MODE", colors[RED]);
       // DrawRectangle(190,300,300,60,colors[WHITE]);
    }
    glutSwapBuffers();
    glutPostRedisplay(); 
}

void gamemode::ShowMoveTimebar(int reset)
{
    static int y=0;
    if(reset)
    y=0;
    if(mode==1)
    {
        static int val=Move,temp2=(600/Move);
        if(reset)
        {
            val=Move;
            temp2=(600/Move);
        }
        string c=Num2Str(Move);
        DrawString(870,740, "MOVE:: " , colors[BLACK]);
        DrawString(960,740, c    , colors[RED]);
        if(val!=Move )
        {
            if(val>0)
            {
                y-=temp2;
                val=Move;
            }
        } 
        DrawRoundRect(870,100,90,600,colors[RED]);
        DrawRectangle(870,700,91,y,colors[BLACK]); 
    }
    else 
    {
        static int val=time,temp2=(600/time);
        if(reset)
        {
            val=time;
            temp2=(600/time);   
        }
        string c=Num2Str(time);
        DrawString(870,740, "TIME:: " , colors[BLACK]);
        DrawString(960,740, c    , colors[RED]);
        if(val!=time)
        {
            if(val>0)
            {
                y-=temp2;
                val=time;
            }
        } 
        DrawRoundRect(870,100,90,600,colors[RED]);
        DrawRectangle(870,700,91,y,colors[BLACK]); 
    }
}

void gamemode::ShowProgressBar(int reset)
{
    static int y=0, val=score;
    if(reset)
    {
        y=0;val=score;
    }
    if(val!=score)
    {
        if(val<=target)
        {
            float val2=(target/100);
            y+=600/val2;
            val=score;
        }
    }
    DrawRoundRect(50,100,90,600,colors[BLACK]);
    DrawRoundRect(50,100,90,y  ,colors[RED]);
}

gamemode::~gamemode()
{
}
#endif