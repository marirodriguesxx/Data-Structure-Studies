//
// Created by okabe2008 on 10/30/20.
//
#include <iostream>
#include "Screen.h"
#include "Snake.h"
#include "Game.h"

using namespace std;

void print(const Screen &s) {
    for (int j = 0; j < s.getWidth() + 2; j++) {
        if(j == 0 || j== s.getWidth() + 1)
            cout << "*";
        else
            cout << "-";
    }
    cout << endl;
    for (int i = 0; i < s.getHeight(); i++) {
        cout << "|";
        for (int j = 0; j < s.getWidth(); j++) {
            if (s.get(s.getHeight() - 1 - i, j) == Screen::EMPTY) cout << " ";
            else if (s.get(s.getHeight() - 1 - i, j) == Screen::SNAKE) cout << "x";
            else cout << "•";
        }
        cout << "|" << "\n";
    }
      for (int j = 0; j < s.getWidth() + 2; j++) {
        if(j == 0 || j== s.getWidth() + 1)
            cout << "*";
        else
            cout << "-";
    }
    cout << "\n\n";
}

int main() {
    int height = 5;
    int width = 7;
    int snakeSize = 5;
    Game game(height, width, snakeSize);
    print(game.getScreen());

    // game.addFood(0,4,1);
    // print(game.getScreen());
    // cout<<"Número de comidas:"<<game.getNumFood()<<endl;

    // game.addFood(2,2,10);
    // print(game.getScreen());
    // cout<<"Número de comidas:"<<game.getNumFood()<<endl;

    cout<<"Move 1 para direita\n";
    game.step(0,1);
    print(game.getScreen());

    cout<<"Move 1 para direita\n";
    game.step(0,1);
    print(game.getScreen());

    cout<<"Move 1 para direita\n";
    game.step(0,1);
    print(game.getScreen());

//     game.addFood(4,4,10);
//     print(game.getScreen());
//     cout<<"Número de comidas:"<<game.getNumFood()<<endl;

//     cout<<"Move 1 para cima\n";
//     game.step(1,0);
//     print(game.getScreen());
//     cout<<"Move 1 para cima\n";
//     game.step(1,0);
//     print(game.getScreen());

//    cout<<"h: "<<game.getScreen().getHeight()<<" ";
//    cout<<"w: "<<game.getScreen().getWidth()<<"\n";
//    print(game.getScreen());

//    game.addFood(0,4,2);
//    game.addFood(2,2,10);
//    print(game.getScreen());
//    game.step(0,1);
//    print(game.getScreen());
//    game.step(0,1);
//    print(game.getScreen());


    return 0;
}