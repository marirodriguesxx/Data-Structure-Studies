
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen{
    public:
    const int  FOOD, SNAKE, EMPTY,  WALL;
    //Construtor da classe
    Screen(int altura, int largura);
    ~Screen();
    int getWidth(){return largura;}const;
    int getHeight(){return altura;}const;
    int get(int r,int c);
    void set(int r,int c,int val);

    private:
    int larguraTela;
    int alturaTela;
    int **data;
    int *dataHeight;
};

#endif