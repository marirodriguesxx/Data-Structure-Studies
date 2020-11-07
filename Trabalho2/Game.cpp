#include"Game.h"

Game::Game(int altura, int largura, int tamSnake){
    //chamamos os construtores de tais classes
    tela(altura, largura);
    cobra(tamSnake);
}

Screen Game::getScreen(){
    return tela;
}

void Game::addFood(int r,int c,int ttl){
    
}