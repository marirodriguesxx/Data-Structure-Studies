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
        tela->set(linha,coluna,0);
        comida[NumFood-1].foodrow=0;
        comida[NumFood-1].foodcol=0;
        comida[NumFood-1].lifetime=0;
        NumFood --;
        return true;
    }
    else 
        return false;
}
void Game::reduceTtl(){
    for(int i=0;i<getNumFood();i++){
        if(comida[i].lifetime!=0){
            comida[i].lifetime--;
        }
        else{
            tela->set(comida[i].foodrow,comida[i].foodcol,0);
        }
    }
}

bool Game::step(const int dr,const int dc){
    int linha_ = dr;
    int coluna_ = dc;
    // if(oldH!=0 && oldH!=dc)
    //     coluna_ = oldH;
    // if(oldV!=0 && oldV!=dr)
    //     linha_ = oldV;
    if(tela->get(cobra->getNextrow(dr),cobra->getNextcol(dc))==Screen::WALL 
    || tela->get(cobra->getNextrow(dr),cobra->getNextcol(dc))==Screen::SNAKE ){
        //cout<<"PAREEEEED\n";
        return false;
    }
    else{
        cobra->draw(*tela,Screen::EMPTY);
        cobra->move(linha_,coluna_,eating(linha_,coluna_));
        reduceTtl();
        cobra->draw(*tela,Screen::SNAKE);
        return true;
    }
    // oldH = dc;
    // oldV= dr;

}

void Game::addFood(const int r,const int c,const int ttl){
    if(tela->get(r,c) == 0){
    comida[NumFood].foodrow = r;
    comida[NumFood].foodcol = c;
    comida[NumFood].lifetime = ttl;
    // cout<<"Comida na linha: "<<comida[NumFood].foodrow<<endl;
    // cout<<"Comida na coluna: "<<comida[NumFood].foodcol<<endl;

    tela->set(r, c, 1);
    // cout<<"tela nessa linha e nessa coluna: "<<tela->get(r,c)<<endl;
    NumFood ++;
    }
}