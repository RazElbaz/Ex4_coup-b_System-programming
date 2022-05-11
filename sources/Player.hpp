#include "Game.hpp"
#include <string>
using namespace std;
#pragma once
int const two=2;
namespace coup {
    class Player {
    protected:
        Game *GameName;

    public:
        ///constructor
        Player(Game &Game, string &Name) {
            this->Name=Name;
            this->GameName=&Game;
            this->Coins=0;
            this->Alive= true;
            this->GameName->addPlayer(this->Name);
            this->YouCanLock=false;
            this->Stolen_coins=0;
            //The number of players must be above 2 for the game to be active
            if (this->getGameName()->Players.size()>=2){
                this->getGameName()->activeGame = true;}
        }
        ~Player(){};
        //////////////////////////////////////////////////
        string Name;
        string LastAction;
        string Role;
        string copedPlayer;
        int Coins;
        int ReturnTO;
        bool Alive;
        bool YouCanLock;
        int Stolen_coins;
        vector<string> Players;
        Player *StolenFrom;
        //////////////////////////////////////////////////
        void income();
        void foreign_aid();
        int coins() const;
        virtual void coup(Player &player);
        virtual string role();
        bool isAlive();
        void releaseBlockage(string player, int index);
        coup::Game* getGameName() const;
        void ReturnToGame(string &Name, int place);
        void ReturnStolenCoins();

};}