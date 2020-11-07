
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Snake.h"
#include "Screen.h"

using namespace std;
struct Food{
<<<<<<< HEAD
    int row;
    int col;
    int lifetime;
=======

>>>>>>> 0738e25a2dc91a8448bf2ec0466f71d8e3c47ddb
};

class Game{
    public:
    //Construtor da classe
    Game(int altura, int largura, int tamSnake);
    ~Game();
    //Método que retorna o estado atual do jogo  - deve ser const pois não modificará o objeto
    Screen getScreen()const;
    //Método indicando se o movimento foi realizado com sucesso (true) ou não (false) 
    bool step(int dr, int dc);
    // adiciona um alimento na posição (r,c) (linha, coluna) da tela. 
    //O terceiro argumento (ttl -- time to live) indica por quanto tempo (em termos de iterações) o alimento deve existir 
    void addFood(int r,int c,int ttl);
    //retorna um inteiro representando a quantidade de comida (ativa) atualmente no jogo.
    int getNumFood();
    private:
    Snake cobra;
    Screen tela;
    Food comida[10];
};

#endif