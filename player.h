#ifndef PLAYER_H_
#define PLAYER_H_
#include<fstream>
#include"util.h"
class player
{
    public:
    char* p;
    int size;
    int Unique_ID;
    public:
    player();
    void setUnique_ID(int);
    int  getUnique_ID()const;
    void setName(char);
    void saveName();
    void TakeInputandDisplay();
    void DisplayPlayerInfo();
    ~player();
};
#endif