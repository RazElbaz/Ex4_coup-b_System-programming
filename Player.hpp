#include "Game.hpp"
#include <string>
using namespace std;
#pragma once

namespace coup {
    class Player {
    protected:

        Game *GameName;


    public:
        string Name;
        string LastAction;
        string Role;
        string copedPlayer;
        int Coins;
        int ReturnTO;
        bool Alive;
        bool canSteal;
        vector<string> Players;
        Player(Game &Game, string &Name);
        void income();
        void foreign_aid();
        int coins();
        void coup(Player &player);
        virtual string role();
        bool isAlive();
        string getName() const;
        void releaseBlockage(string player, int index);
        coup::Game* getGameName() const;
        ~Player();
};}