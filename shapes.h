#ifndef SHAPES_H
#define SHAPES_H
#include"util.h"
#include<string>
class shapes
{
    protected:
    float x;
    float y;
    int id;
    public:
    shapes();
    void  setid(int);
    int   getid()const;
    void  setx(float X);
    float getx();
    float gety();
    void  sety(float Y);
    ~shapes();
};
#endif