#ifndef GRID_H_
#define GRID_H_
#include<fstream>
#include"shapes.h"
#include"Manu.h"
#include"gamemode.h"

class Grid:public Manu,public gamemode
{
    private:
    shapes** ptr;
    int gridsize;
    public:
    Grid();
    void PouseScreen();
    void checkCondition();
    void SetCoordinates();
    void Swapposition(int , int );
    void ShowMouseMovement(int ,int);
    int* GetIndex(int x, int y);
    void SetRandom();
    void removeCandies(int,int,int,int,int);
    void Display(int i);
    void PrivideHint();
    bool identifyMatch(int,int , int , int );
    void CheckRandomMakedMatches(int);
    void UpdateID();
    void clearscreen();
    void gameOverScreen();
    ~Grid();
};
#endif