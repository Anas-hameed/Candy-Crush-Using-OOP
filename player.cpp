#include"player.h"
player::player()
{
    size=50;
    p=new char[size];
    for(int i=0; i<size ; i++ )
    p[i]='0';
}

void player::setUnique_ID(int i)
{
    Unique_ID=i;
}
int player::getUnique_ID()const
{
    return Unique_ID;
}
void player::setName(char A)
{
    for(int i=0; i<size ; i++)
    {
        if(p[i]=='0')
        {
            p[i]=A;
            return;
        }
    }
}   
void player::TakeInputandDisplay()
{  
    glClearColor( 1 , 1 , 1 , 1);
    glClear (GL_COLOR_BUFFER_BIT); 
    DrawRoundRect(-10,-10,1040,30,colors[BLACK]);
    DrawRoundRect(-10,-10,30,850,colors[BLACK]) ;
    DrawRoundRect(-10,820,1040,30,colors[BLACK]);
    DrawRoundRect(1000,-10,30,870,colors[BLACK]);
    int x1=385, y1=340;
    DrawRectangle(380,380,200,60,colors[BLACK]);
    DrawString(400,400, "ENTER NAME",colors[RED]);
    for(int i=0 ; i<size ; i++)
    {
        if(p[i]!='0')
        {
            string s="a";
            s[0]=p[i];
            DrawRectangle(x1-5,y1-20,30,60,colors[BLACK]);  
            DrawString(x1,y1,s,colors[RED]);
            x1+=22;       
        }
        else 
        break;
    }
    DrawRectangle(380,80,250,60,colors[BLACK]);
    DrawString(400,100, "ENTER '1' TO SAVE",colors[RED]);
    glutSwapBuffers();
    glutPostRedisplay(); 
}
void player::DisplayPlayerInfo()
{
    glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);   
    DrawRectangle(100,200,700,500,colors[RED]);
    DrawRectangle(120,220,660,460,colors[BLACK]);
    int x1=500;
    DrawString(200,600,"PLAYER NAMES:: ",colors[RED]);
    for(int i=0 ; i<size ; i++)
    {
        if(player::p[i]!='0')
        {
            string s="a";
            s[0]=p[i];
            DrawString(x1,600,s,colors[RED]);  
            x1+=16;       
        }
        else 
        break;   
    }
    DrawString(200,560,"UNIQUE ID ",colors[RED]);
    string c=Num2Str(Unique_ID);
    DrawString(500,560,c,colors[RED]);
    DrawString(200,300,"PRESS B TO BACK TO MANU ",colors[RED]);
    glutSwapBuffers();
    glutPostRedisplay();
}
// this will save name of player on each time a game is started
void player::saveName()
{
    Unique_ID = GetRandInRange(0,9999);
    ofstream Name("PlayerName.txt", ios::app);
    for(int i=0 ; i<size ; i++ ) 
    {
        if(p[i]!='0')
        { 
            Name<<p[i];
        }
        else 
        break;
    }
    Name<<endl;
    Name.close();
    return;
}
player::~player()
{
    delete []p;
}