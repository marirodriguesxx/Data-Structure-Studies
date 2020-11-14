#include"Game.h"

Game::Game(const int altura,const int largura,const int tamSnake){
    //chamamos os construtores de tais classes
    tela = new Screen (altura,largura);
    cobra = new Snake(tamSnake);
}
Game::~Game(){
    delete tela;
    delete cobra;
}
const Screen &Game::getScreen()const{
    cobra->draw(*tela,2);
    return *tela;
}
// bool Game::eating (const int r, const int c) const{
//     //caso a cobra esteja comendo, devemos tornar EMPTY a proxima posição
//     //signifcando que a cobra comeu
//     if(tela.get(r,c) == 1){
//         tela.set(r,c) = 0;
//         numFood --;
//         return true;
//     }
//     else 
//         return false;
// }
// bool Game::step(const int dr,const int dc){


// }

void Game::addFood(const int r,const int c,const int ttl){
    if(tela->get(r,c) == 0){
    comida[NumFood].foodrow = r;
    comida[NumFood].foodcol = c;
    comida[NumFood].lifetime = ttl;
    cout<<"Comida na linha: "<<comida[NumFood].foodrow<<endl;
    cout<<"Comida na coluna: "<<comida[NumFood].foodcol<<endl;

    tela->set(r, c, 1);
    cout<<"tela nessa linha e nessa coluna: "<<tela->get(r,c)<<endl;
    NumFood ++;
    }
}
