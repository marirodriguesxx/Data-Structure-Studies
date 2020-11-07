
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen{
    public:
    const int  FOOD=1, SNAKE=2, EMPTY=0,  WALL=3;
    //Construtor da classe
    Screen(int altura, int largura);
    ~Screen();
    int getWidth(){return largura;}const;
    int getHeight(){return altura;}const;
    int get(const int r,const int c);
    void set(const int r,const int c,const int val);
    
    //metodos que serão auxiliares para a função set e que foram implementados no trabalho 1
    //a função sofreu algumas alterações para que fosse implementada nesse trabalho
    void resizeRow(const int pos,const int newcols); 

    private:
    int largura;
    int altura;
    int **data;
    int *dataHeight;
};

#endif