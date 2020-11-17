#include"Game.h"

Game::Game(const int altura,const int largura,const int tamSnake){
    //chamamos os construtores de tais classes
    tela = new Screen (altura,largura);
    cobra = new Snake(tamSnake);
    cobra->draw(*tela,Screen::SNAKE);
}
Game::~Game(){
    delete tela;
    delete cobra;
}
const Screen &Game::getScreen()const{
    cobra->draw(*tela,Screen::SNAKE);
    return *tela;
}
bool Game::eating (const int dr, const int dc) {
    //caso a cobra esteja comendo, devemos tornar EMPTY a posição
    //signifcando que a cobra comeu
    int linha = cobra->getNextrow(dr);
    int coluna = cobra->getNextcol(dc);
    if(tela->get(linha,coluna) == Screen::FOOD){
        for(int i=0; i<10;i++){
            if(comida[i].foodrow==linha && comida[i].foodcol==coluna)
                comida[i].lifetime=0;
            }
        tela->set(linha,coluna,Screen::SNAKE);
        cobra->draw(*tela,Screen::EMPTY);
        cobra->draw(*tela,Screen::SNAKE);
        NumFood --;
        return true;
    }
    else 
        return false;
}
void Game::reduceTtl(){
    for(int i=0;i<10;i++){
        if(comida[i].lifetime >0)
        tela->set(comida[i].foodrow,comida[i].foodcol,Screen::FOOD);
        if (tempo == comida[i].lifetime){
            tela->set(comida[i].foodrow,comida[i].foodcol,Screen::EMPTY);
            comida[i].foodrow = 0;
            comida[i].foodcol = 0;
            comida[i].lifetime=0;
        }
    }
}

bool Game::step(const int dr,const int dc){
    int linha_ = dr;
    int coluna_ = dc;
    if(tela->get(cobra->getNextrow(dr),cobra->getNextcol(dc))==Screen::WALL 
    || tela->get(cobra->getNextrow(dr),cobra->getNextcol(dc))==Screen::SNAKE ){
        return false;
    }
    else{
        cobra->draw(*tela,Screen::EMPTY);
        cobra->move(linha_,coluna_,eating(linha_,coluna_));
        reduceTtl();
        tempo++;
        cobra->draw(*tela,Screen::SNAKE);
        return true;
    }

}

void Game::addFood(const int r,const int c,const int ttl){
    if(tela->get(r,c) == 0){
        for(int i=0;i<10;i++){
            if(comida[i].lifetime <= 0 ){
            comida[i].foodrow = r;
            comida[i].foodcol = c;
            comida[i].lifetime = ttl+tempo;
            tela->set(r, c, Screen::FOOD);
            NumFood ++;
            break;
            }
        }
    }
}