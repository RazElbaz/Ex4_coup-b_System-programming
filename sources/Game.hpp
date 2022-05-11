#include <vector>
#include <string>
using namespace std;
#include <iostream>

#pragma once
namespace coup{
    class Player;
    class Game{

    public:
        Game() {
            this->i=0;
            this->activeGame= false;
            this->TheGameStart= false;
        }
        bool activeGame;
        bool TheGameStart;
        size_t i;
        vector<string> Players;
        int Turn;
        vector<string> players();
        string winner();
        string turn();
        void RePlayer(string &player);
        void increaseTurn();
        void ReturnToGame(string &player, int index);
        void addPlayer(string &Name);
        ~Game(){};
    };
}