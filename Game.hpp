#include <vector>
#include <string>
using namespace std;
#include <iostream>

#pragma once
namespace coup{
    class Player;
    class Game{

    public:
        Game();
        bool activeGame;
        size_t i;
        vector<string> Players;
        int Turn;
        vector<string> players();
        string winner();
        string turn();
        void RePlayer(string player);
        void increaseTurn();
        ~Game();
    };
}