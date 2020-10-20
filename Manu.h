#ifndef MANU_H_
#define MANU_H_
#include"player.h"
#include"util.h"
class Manu:public player
{
    private:
    int screen;
    public:
    Manu();
    void setscreen(int s);
    int  getscreen()const;
    void DisplayHelp();
    void ManuDisplay(); 
    ~Manu();
};
#endif