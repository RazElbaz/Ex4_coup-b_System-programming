#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &Game, string Name): Player(Game,Name){}
    void Ambassador::transfer(Player &player1, Player &player2){
        //checking the game roles and the players roles
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if(!this->getGameName()->activeGame){throw runtime_error("The game not active");}
        if (!player1.isAlive()||!player2.isAlive()){throw runtime_error("One of the players are not alive");}
        if(this->getGameName()!=player1.getGameName()){throw runtime_error("The player1 is from another game");}
        if(player2.getGameName()!=player1.getGameName()){throw runtime_error("The player1 is from another game");}
        if(this->getGameName()!=player2.getGameName()){throw runtime_error("The player2 is from another game");}
        if(player1.Coins<1){throw runtime_error("Player 1 does not have enough money to transfer to the other player");}

        player1.Coins-=1;
        player2.Coins+=1;
        this->LastAction="transfer";
        this->getGameName()->increaseTurn();
    }

    string Ambassador::role() { return "Ambassador";}
    void  Ambassador::block(Player &player) {
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if(!this->getGameName()->activeGame){throw runtime_error("THe game not active");}
        if(player.role()!="Captain"){throw runtime_error("Only the action of captain players can be prevented");}
        if(player.LastAction!="steal"||player.YouCanLock){throw runtime_error("There is no reason to prevent the theft of coins");}
        player.YouCanLock= false;
        player.ReturnStolenCoins();
    }
    Ambassador::~Ambassador(){}
}