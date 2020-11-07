
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

class Screen{
    public:
<<<<<<< HEAD
    const int  FOOD=1, SNAKE=2, EMPTY=0,  WALL=3;
=======
    const int  FOOD, SNAKE, EMPTY,  WALL;
>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb
    //Construtor da classe
    Screen(int altura, int largura);
    ~Screen();
    int getWidth(){return largura;}const;
    int getHeight(){return altura;}const;
<<<<<<< HEAD
    int get(const int r,const int c);
    void set(const int r,const int c,const int val);
    
    //metodos que serão auxiliares para a função set e que foram implementados no trabalho 1
    //a função sofreu algumas alterações para que fosse implementada nesse trabalho
    void resizeRow(const int pos,const int newcols); 

    private:
    int largura;
    int altura;
=======
    int get(int r,int c);
    void set(int r,int c,int val);

    private:
    int larguraTela;
    int alturaTela;
>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb
    int **data;
    int *dataHeight;
};

#endif