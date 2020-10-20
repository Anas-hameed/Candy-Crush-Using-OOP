#ifndef ShAPES_CPP_
#define SHAPES_CPP_
#include"shapes.h"
shapes::shapes()
{
}
void shapes::setid(int i)
{
    id=i;
}
int shapes::getid()const
{
    return id;
}   
void shapes::setx(float X)
{
    x=X;
}
float shapes:: getx()
{
    return x;
}
float shapes::gety()
{
    return y;
}
void shapes::sety(float Y)
{
    y=Y;
}
shapes::~shapes()
{}
#endif