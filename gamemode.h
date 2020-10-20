#ifndef GAMEMODE_H
#define GAMEMODE_H
#include"util.h"
class gamemode
{
    private:
    int mode,score,time;
    int target,levels,Move,life;
    public:
    gamemode();
    void settarget(int);
    int  gettarget()const;
    void setMove(int);
    int  getMove()const;
    void setlife(int);
    int  getlife()const;
    void settime(int);
    int  gettime()const;
    void setscore( int );
    int  getscore()const;
    void setLevel(int);
    int getlevel()const;
    void setMode(int t);
    void ShowProgressBar(int);
    void ShowMoveTimebar(int);
    int  getMode()const;
    void selectmode();
    ~gamemode();
};
#endif