#ifndef GRID_CPP_
#define GRID_CPP_
#include"Grid.h"
Grid::Grid():Manu(),gamemode()
{
    gridsize =8 ;
    ptr   = new shapes*[gridsize];
    for(int i=0 ;i <gridsize ; i++ )
    {
        ptr[i]= new shapes[gridsize];
    }
    SetRandom();
    SetCoordinates();
    for(int i=0; i<8  ; i++ )
    {
        for(int j=0; j<8; j++)
        {
            cout<<ptr[i][j].getx()<<","<<ptr[i][j].gety()<<"    ";
        }
        cout<<endl;
    }
}
void Grid::checkCondition()
{
    if(getMode())
    {

        if(getMove()>=0 && getscore()>=gettarget())  
        { 
            setscore(0);
            int x= gettarget();
            x+=1000;
            settarget(x);
            if(getlevel()<5)
            x=GetRandInRange(40,60);
            else
            x=GetRandInRange(30,50);
            setMove(x);
            x=getlevel();
            setLevel(++x);
            ShowProgressBar(1);  
            ShowMoveTimebar(1);
            clearscreen(); 
            for(int i=0; i<400; i++ )
            {
                Display(6);
                CheckRandomMakedMatches(6);
            }        
        }
        else if(getMove()==0 && getscore()<gettarget() && getlife()!=0)
        {    
            int x;
            x=getlife();
            setlife(--x);
            if(getlife()==0)
            return;
            setscore(0); 
            if(getlevel()<5)
            x=GetRandInRange(40,60);
            else
            x=GetRandInRange(30,50);
            setMove(x); 
            ShowProgressBar(1);  
            ShowMoveTimebar(1);
            clearscreen(); 
            for(int i=0; i<400; i++ )
            {
                Display(7);
                CheckRandomMakedMatches(7);
            }   
        }
    }
    else
    {
        if(gettime()>=0 && getscore()>=gettarget())  
        {
            setscore(0);
            int x= gettarget();
            x+=1000;
            settarget(x);
            x=gettime();
            if(x<60)
            x+=GetRandInRange(20,40);
            else
            x-=5;
            settime(x);
            x=getlevel();
            setLevel(++x);
            ShowProgressBar(1);  
            ShowMoveTimebar(1);
            clearscreen(); 
            for(int i=0; i<400; i++ )
            {
                Display(6);
                CheckRandomMakedMatches(6);
            } 
        }
        else if(gettime()<0 && getscore()<gettarget() && getlife()!=0)
        {
            setscore(0);int x;
            x=GetRandInRange(100,120);
            settime(x);
            x=getlife();
            setlife(--x);
            if(getlife()==0)
            return;
            ShowProgressBar(1);  
            ShowMoveTimebar(1);
            clearscreen(); 
            for(int i=0; i<400; i++ )
            {
                Display(7);
                CheckRandomMakedMatches(7);
            } 
        }
    }
    glutPostRedisplay();
}
void Grid::gameOverScreen()
{
    glClearColor( 0 , 0 , 0 ,  0 );
	glClear (GL_COLOR_BUFFER_BIT);
    DrawString( 250 , 360 , " G A M E      O V E R           ", colors[WHITE]);
    DrawString( 250 , 330 , " press 's' to continue          ", colors[DARK_RED]);
    DrawString( 250 , 300 , " press 'esc' to exit              ", colors[DARK_RED]);
    glutSwapBuffers();
    glutPostRedisplay();
}
void Grid::SetCoordinates()
{
    int index1=0;
    int index2=0;
    for(float i=200 ;  ; i+=80)
    {  
        index1=0;
        for(float j=100+(gridsize-1)*80 ;  ; j-=80 )
        {
            ptr[index1][index2].setx(i);
            ptr[index1][index2].sety(j);
            index1++;
            if(index1==gridsize)
            break;
        }
        index2++;
        if(index2==gridsize)
        break;
    }
}

void Grid::Swapposition(int x , int y)
{
   static int flag=0,x1,y1;
   flag++;
   if(flag==1)
   {
       x1=x;
       y1=y;
   }
   else if(flag==2)
   {
       flag=0;
       int x2,y2;
       x2=x; y2=y;
       int  temp1, temp2, *ptr1,*ptr2;
       if(x1>60 && x1<1040 && y1>60 && y1< 940 )
       {
           if(y1>60 && y1<300)
           y1-=60;
           if(y2>60 && y2<300)
           y2-=60;
           ptr1= GetIndex( x1,y1 );
           ptr2= GetIndex( x2,y2 );
           cout<<"Index1    "<<ptr1[0]<<"    "<<ptr1[1]<<endl;
           cout<<"Index2    "<<ptr2[0]<<"    "<<ptr2[1]<<endl;

           if(ptr1[0]!=-1 &&  ptr2[0]!=-1 )
           {
               if( ( ptr1[0]== ptr2[0] && ((ptr1[1]==ptr2[1]+1 ) || (ptr1[1]==ptr2[1]-1) ) ) ||  ( ptr1[1] == ptr2[1] && ( (ptr1[0]==ptr2[0]+1) || (ptr1[0]==ptr2[0]-1) ) ))
               {
                    temp1 = ptr[ptr1[0]][ptr1[1]].getid();
                    temp2 = ptr[ptr2[0]][ptr2[1]].getid();
                    ptr[ptr1[0]][ptr1[1]].setid(temp2);
                    ptr[ptr2[0]][ptr2[1]].setid(temp1);
                    bool x=identifyMatch(ptr1[0],ptr1[1],ptr2[0],ptr2[1]);
                    if(x)
                    {
                        int tem7=getMove();
                        setMove(--tem7);
                    }
                    else
                    {
                        temp1 = ptr[ptr1[0]][ptr1[1]].getid();
                        temp2 = ptr[ptr2[0]][ptr2[1]].getid();
                        ptr[ptr1[0]][ptr1[1]].setid(temp2);
                        ptr[ptr2[0]][ptr2[1]].setid(temp1);
                    }
               }
           }
           delete []ptr1;
           delete []ptr2;
        }
    } 
    glutPostRedisplay();
	glutSwapBuffers();     
}

bool Grid::identifyMatch(int i1, int j1, int i2, int j2)
{
    //For horizontal match identification after a move.
    for(int i=0; i<2 ; i++ )
    {
        if(i1-2>=0 && ptr[i1][j1].getid()==ptr[i1-1][j1].getid() && ptr[i1][j1].getid()==ptr[i1-2][j1].getid() )
        return true;
        else if(i1+2<gridsize && ptr[i1][j1].getid()==ptr[i1+1][j1].getid() && ptr[i1][j1].getid()==ptr[i1+2][j1].getid() )
        return true; 
        else if(j1-2>=0 && ptr[i1][j1].getid()==ptr[i1][j1-1].getid() && ptr[i1][j1].getid()==ptr[i1][j1-2].getid() )
        return true;
        else if(j1+2<gridsize && ptr[i1][j1].getid()==ptr[i1][j1+1].getid() && ptr[i1][j1].getid()==ptr[i1][j1+2].getid() )
        return true; 
        else if(i1-1>=0 && i1+1<gridsize && ptr[i1][j1].getid()==ptr[i1-1][j1].getid() && ptr[i1][j1].getid()==ptr[i1+1][j1].getid())
        return true;
        else if(j1-1>=0 && j1+1<gridsize && ptr[i1][j1].getid()==ptr[i1][j1-1].getid() && ptr[i1][j1].getid()==ptr[i1][j1+1].getid())
        return true;
        i1=i2;
        i2=j2;
    }
    return false;
}
void Grid::CheckRandomMakedMatches(int con)
{
    int count1,temp1;
    for(int i=0 ; i<gridsize ; i++ )
    {
        temp1=0; count1=0;
        for(int j=0 ; j<gridsize ; j++ )
        {
            if(j==temp1)
            temp1++;
            if(count1==2)
            {
                if(j+2<gridsize && ptr[i][j].getid()==ptr[i][j+1].getid() && ptr[i][j].getid()==ptr[i][j+2].getid())
                removeCandies(i,j+2,count1+2,0,con);
                else if(j+1<gridsize && ptr[i][j].getid()==ptr[i][j+1].getid())
                removeCandies(i,j+1,count1+1,0,con);
                else
                removeCandies(i,j,count1, 0,con);
            }
            if(ptr[i][temp1].getid()==ptr[i][j].getid())
            count1++;
            else 
            {
                if(count1!=0)
                temp1+=count1;
                else 
                temp1++;  
                count1=0;              
            }
        }
    }
    // For vertical Match
    int temp2, count2;
    for(int i=0 ; i<gridsize ; i++ )
    {
        temp2=0; count2=0;
        for(int j=0 ; j<gridsize ; j++ )
        {
            if(j==temp2)
            temp2++;
            if(count2==2)
            {
                if(j+2<gridsize && ptr[j][i].getid()==ptr[j+1][i].getid() && ptr[j][i].getid()==ptr[j+2][i].getid())
                removeCandies( j+2, i ,count2+2,1,con);
                else if(j+1<gridsize && ptr[j][i].getid()==ptr[j+1][i].getid())
                removeCandies(j+1,i,count2+1,1,con);
                else
                removeCandies(j,i,count2, 1,con);
            }
            if(temp2>gridsize-1)
            break;
            if(ptr[temp2][i].getid()==ptr[j][i].getid())
            count2++;
            else 
            {
                temp2++;  
                count2=0;              
            }
        }
    }
}
void Grid::removeCandies(int i1, int j1, int count , int hori_vertical, int condition)
{
    if(condition!=6 && condition!=7)
    {
        int flagi=getscore();
        flagi+=100;
        setscore(flagi);
    }
    if(hori_vertical==0)
    {
        j1-=count;int x,temp1,temp2;
        for(int i=i1 ;i>=0 ; i--)
        {
            for(int j=j1; j<=j1+count; j++ )
            {
                if(i>0)
                {
                    temp1=ptr[i][j].gety();
                    temp2=ptr[i-1][j].gety();
                    while(temp2>temp1)
                    {
                        temp2-=10;
                        ptr[i][j].sety(temp2);
                        if(temp2>=temp1)
                        ptr[i][j].setid(ptr[i-1][j].getid());
                        else
                        ptr[i][j].setid(-1);
                        Display(condition);
                    }
                }
                else if(i==0)
                {
                    x=GetRandInRange(0,5);
                    ptr[i][j].setid(x);     
                }
            }
        }
    }
    else if(hori_vertical==1)
    {
        int x,temp1, temp2;
        for(int i=i1 ; i>=0 ; i-- )
        {
            if(i-count-1>=0)
            {
                for(int j=i; j>i-count-1 ; j-- )
                {
                    ptr[j][j1].setid(-1);
                }
                temp1= ptr[i][j1].gety();
                temp2= ptr[i-count-1][j1].gety();
                while(temp2>temp1)
                {
                    temp2-=10;
                    ptr[i][j1].sety(temp2);
                    if(temp2>=temp1)
                    ptr[i][j1].setid(ptr[i-count-1][j1].getid());
                    else
                    ptr[i][j1].setid(-1);
                    Display(condition);
                }
            }
            else if(i!=0)
            { 
                x=GetRandInRange(0,5);
                int count1=0,temp=i;
                while(temp>0)
                {
                    count1++;temp--;
                }
                ptr[i-count1][j1].setid(x);
                for(int j=i; j>i-count1 ; j-- )
                {
                    ptr[j][j1].setid(-1);
                }
                temp1= ptr[i][j1].gety();
                temp2= ptr[i-count1][j1].gety();
                while(temp2>temp1)
                {
                    temp2-=10;
                    ptr[i][j1].sety(temp2);
                    if(temp2>=temp1)
                    ptr[i][j1].setid(ptr[i-count1][j1].getid());
                    else
                    ptr[i][j1].setid(-1);
                    Display(condition);
                }
            }
            else
            {
                x=GetRandInRange(0,5);
                Display(condition);
            }
            
        }
    } 
}

void Grid::ShowMouseMovement(int x, int y)
{
    y=840-(y*825/655);int flag=0;
	for(int i=0 ; i<gridsize ; i++ )
	{
		for(int j=0 ; j<gridsize ; j++)
		{
			if(ptr[i][j].getx()>x-40 && ptr[i][j].getx()<=x+40 && ptr[i][j].gety()>y-40 && ptr[i][j].gety()<=y+40  ) 
            {flag=-1;break;}
        }
        if(i>=0 && i<gridsize-2)
        y+=10;
        if(flag==-1)
        break;
    }
	DrawCircle(x, y ,5 ,colors[BLUE_VIOLET]); 
}

int* Grid::GetIndex(int x, int y)
{
    cout<<"x1    "<<x<<"     y1    "<<y<<endl;
    int *ptr1=new int[2],flag=0;
    ptr1[0]=-1;ptr1[1]=-1;
    for(int i=0 ; i<gridsize ;i++ )
    {
        for(int j=0 ; j<gridsize ; j++ )
        {
            if(ptr[i][j].getx()>x-40 && ptr[i][j].getx()<=x+40 && ptr[i][j].gety()>y-40 && ptr[i][j].gety()<=y+40) 
            {
                ptr1[0]=i;ptr1[1]=j;
                flag=-1;
                break;
            }
        }
        if(i>=0 && i<gridsize-2)
        y+=10;
        if(flag==-1)
        break;
    }
    return ptr1;
}
void Grid::PouseScreen()
{
    Display(0);
    DrawRectangle(100,200,700,500,colors[RED]);
    DrawRectangle(120,220,660,460,colors[BLACK]);
    DrawString(200,600,"Screen is  Paused     ", colors[RED]);
    DrawString(200,560,"Press R to Resume     ", colors[RED]);
    glutSwapBuffers();
    glutPostRedisplay();
}
//this function will clear the screen
void Grid::clearscreen()
{
    for(int i=0; i<gridsize ; i++ )
    for(int j=0; j<gridsize ; j++ )
    ptr[i][j].setid(-1);
}
    
void Grid::SetRandom()
{
    int x;
    for(int i=0 ; i<gridsize ; i++ )
    {
        for(int j=0 ; j<gridsize ; j++ )
        {
            x=GetRandInRange(0,5);
            ptr[i][j].setid(x);
        }
    }
}
void Grid::Display(int con)
{
    glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0.0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); // DrawRoundRect(-20,0,1060,840,colors[BLACK],20); //Update the colors

    //UpperBOder
    DrawRoundRect(-10,-10,1040,20,colors[RED]);
    DrawRoundRect(-10,-10,20,850 ,colors[RED]) ;
    DrawRoundRect(-10,830,1040,20,colors[RED]);
    DrawRoundRect(1010,-10,20,870,colors[RED]);
    //GAMEBOARD
    DrawRoundRect(150,50,700,780,colors[BLACK],20);
    //Drawing boder
    DrawRectangle(10,728,1002,105,colors[WHITE]);
    DrawRectangle(10,780,1002,53,colors[BLACK]);
    DrawRectangle(10,75,180,655,colors[DARK_VIOLET]);
    DrawRectangle(740,75,271,655,colors[DARK_VIOLET]);
    DrawRectangle(10,10,1000,73,colors[WHITE]);
    //Drawingnameofproject
    DrawString(100,790, "CANDY    CRUSH      GAME"    , colors[WHITE]);
    DrawString(700,790, "PRESS    'H'    FOR    HINT"    , colors[WHITE]);
        
    //Score
    string Score=Num2Str(getscore());
    DrawString(220,740, "SCORE::" , colors[BLACK]);
    DrawString(320,740, Score    , colors[RED]);
    //Drawing strings target+progressbar
    Score=Num2Str(gettarget());
    DrawString(15,740,"TARGET::",colors[BLACK]);
    DrawString(130,740,Score    ,colors[RED]);
    //levels
    Score=Num2Str(getlevel());
    DrawString(470,740, "LEVELS::" , colors[BLACK]);
    DrawString(570,740, Score    , colors[RED]);
    //Move or Time bar drawing 
    //this will show remaining move or time depending upoon mode
    //lifes
    Score=Num2Str(getlife());
    DrawString(700,740, "LIFE::" , colors[BLACK]);
    DrawString(800,740, Score    , colors[RED]);
    //Lower strings gamemode, playername and unique id printing
    int x1=700;
    DrawString(x1-190,30,"PLAYER :: ",colors[BLACK]);
    DrawString(x1-660,30,"GAME MODE  :: ",colors[BLACK]);
    if(getMode())
    DrawString(x1-480,30,"NORMAL    MODE",colors[RED]);
    else
    DrawString(x1-480,30,"TIME    TRIAL",colors[RED]);
    DrawString(x1+130,30,"Unique ID::",colors[BLACK]);
    int xm=getUnique_ID();
    string c= Num2Str(xm);
    DrawString(x1+247,30,c,colors[RED]);
    for(int i=0 ; i<size ; i++)
    {
        if(player::p[i]!='0')
        {
            string s="a";
            s[0]=p[i];
            DrawString(x1-75,30,s,colors[RED]);  
            x1+=16;       
        }
        else 
        break;   
    }
    //Formation of grid;
    int temp1=0,temp2=0;int v=0;
    for(int i=90; temp1<gridsize; i+=80 )
    {
        temp2=0;
        for(int j=190 ;temp2<gridsize; j+=80)
        {
            if(v==2)
            v=0;
            if(v==0)
            {
                if(temp2%2==0)
                DrawRoundRect(j,i,82,80,colors[GRAY]);
                else
                DrawRoundRect(j,i,82,80,colors[BLACKO]);
            }
            else 
            {
                if(temp2%2==1)
                DrawRoundRect(j,i,82,80,colors[GRAY]);
                else
                DrawRoundRect(j,i,82,80,colors[BLACKO]);
            }
            
            temp2++;
        }
        v++;
        temp1++;
    }

    float x;
    float y;
    int random;
    for(int i=0 ; i<gridsize ; i++ )
    {
        for(int j=0 ; j<gridsize ; j++ )
        {
            random=ptr[i][j].getid();
            x= ptr[i][j].getx();
            y= ptr[i][j].gety(); 

            if(random==0)
            DrawCircle(x+24, y+24 ,26 ,colors[RED]);
            else if(random==1)
            DrawRectangle(x,y, 45 , 40 , colors[ORANGE]);
            else if(random==2)  
            DrawTriangle( x , y ,x+60, y, x+30, y+60 , colors[BLUE_VIOLET]);
            else if(random==3)
            DrawRoundRect(x,y,55,40,colors[DARK_BLUE],16);  
            else if(random==4)
            {
                DrawRoundRect(x,y,50,30,colors[GREEN]);
                DrawTriangle(x,y,x+50,y,x+25,y+50,colors[GREEN]);
                DrawString(x,y+5," | | |", colors[WHITE]);
            } 
        }
    }
    int j=0;
    for(int i=190;j<=gridsize ;i+=80 )
    {
        DrawLine(i,82,i,727,4,colors[MEDIUM_VIOLET_RED]);
        j++;
    }
    j=0;
    for(int i=85;j<=gridsize ;i+=80 )
    {
        DrawLine(190,i,830,i,4,colors[MEDIUM_VIOLET_RED]);
        j++;
    }
    if(con!=6 && con!=7)
    {
        ShowMoveTimebar(0);
        ShowProgressBar(0); 
    }
    else if(con== 6 )
    {
        DrawRectangle(200,200,550,400,colors[RED]);
        DrawRectangle(220,220,510,360,colors[BLACK]);
        DrawString(230,400,"LEVEL COMPLETED ", colors[RED]);
        DrawString(230,360,"PLEASE WIGHT WHILE WE RESET GERMs", colors[RED]);
    }
    else if(con== 7 )
    {
        DrawRectangle(200,200,550,400,colors[RED]);
        DrawRectangle(220,220,510,360,colors[BLACK]);
        DrawString(230,400,"LEVEL FAILED ", colors[RED]);
        DrawString(230,360,"YOU STILL HAVE           RAMINING LIFE", colors[RED]);
        int i=getlife();
        Score=Num2Str(i);
        DrawString(440,360,Score, colors[RED]);
        DrawString(230,320,"PLEASE WIGHT WHILE WE RESET GERM ", colors[RED]);
    }
    if(con)
    {
        glutSwapBuffers();
        glutPostRedisplay();
    }
}

//Providing hint functionality in the game
void Grid::PrivideHint()
{
    int p1[4];p1[3]=-5;
    for(int i=0 ; i<gridsize ; i++ )
    {
        for(int j=0 ; j< gridsize-1 ; j++ )
        {
            if(ptr[i][j].getid()==ptr[i][j+1].getid())
            {
                if(j-2>=0 && ptr[i][j].getid()==ptr[i][j-2].getid())
                {
                    p1[0]=i;p1[1]=j-2;
                    p1[2]=i;p1[3]=j-1;
                }
                else if(j-1>=0 && i-1>=0 && ptr[i][j].getid()==ptr[i-1][j-1].getid())
                {
                    p1[0]=i-1;p1[1]=j-1;
                    p1[2]=i;p1[3]=j-1;
                }
                else if(i+1<gridsize && j-1>=0 && ptr[i][j].getid()==ptr[i+1][j-1].getid())
                {
                    p1[0]=i+1;p1[1]=j-1;
                    p1[2]=i;p1[3]=j-1;
                } 
                else if(j+3<gridsize && ptr[i][j].getid()==ptr[i][j+3].getid())
                { 
                    p1[0]=i;p1[1]=j+2;
                    p1[2]=i;p1[3]=j+3;
                }
                else if(j+2<gridsize && i-1>=0 && ptr[i][j].getid()==ptr[i-1][j+2].getid())
                {
                    p1[0]=i-1;p1[1]=j+2;
                    p1[2]=i;p1[3]=j+2;
                }
                else if(i+1<gridsize && j+2<gridsize && (ptr[i][j].getid()==ptr[i+1][j+2].getid()))
                {
                    p1[0]=i+1;p1[1]=j+2;
                    p1[2]=i;p1[3]=j+2;
                } 
            }   
        }
    }
    if(p1[3]!=-5)
    {
        DrawRectangle(ptr[p1[0]][p1[1]].getx()-5,ptr[p1[0]][p1[1]].gety()-6,77,80,colors[ORANGE]);
        DrawRectangle(ptr[p1[2]][p1[3]].getx()-5,ptr[p1[2]][p1[3]].gety()-6,80,80,colors[ORANGE]);
    }
    glutSwapBuffers();
    glutPostRedisplay();
}

Grid::~Grid()
{
    for(int i=0 ; i<gridsize ; i++ )
    delete []ptr[i];
    delete []ptr;
}
#endif