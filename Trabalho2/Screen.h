
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen{
    public:
    static const int  FOOD=1, SNAKE=2, EMPTY=0,  WALL=3;
    //Construtor da classe
    Screen(int altura_, int largura_);
    ~Screen();
    int getWidth()const{return largura;};
    int getHeight()const{return altura;};
    int get(const int r,const int c)const;
    void set(const int r,const int c,const int val);
    
    //metodos que serão auxiliares para a função set e que foram implementados no trabalho 1
    //a função sofreu algumas alterações para que fosse implementada nesse trabalho
    void resizeCol(const int pos,const int newrows); 

    private:
    int largura;
    int altura;
    int **data;
    int *dataHeight ;
};


#endif