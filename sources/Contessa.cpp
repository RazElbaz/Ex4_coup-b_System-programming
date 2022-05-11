#include "Contessa.hpp"
namespace coup{
    Contessa::Contessa(Game &Game, string Name): Player(Game, Name){}
    void Contessa::block(Player &player) {
        if(!this->getGameName()->TheGameStart){
            this->getGameName()->TheGameStart= true;
        }
        if(!this->getGameName()->activeGame){
            throw runtime_error("The game not active");
        }
        if(!(this->isAlive()) || !(player.isAlive())){
            throw runtime_error("The players are not alive");
        }
        if(player.role() != "Assassin"){
            throw runtime_error("A contessa can block the assassin operation");
        }
        if(player.LastAction!="coup"){
            throw runtime_error("A contessa can block the assassin coup");
        }
        if(!player.YouCanLock){
            throw runtime_error("You cant block this player");

        }

        player.ReturnToGame(player.copedPlayer,player.ReturnTO);
    }

    string Contessa::role(){
        return "Contessa";
    }
    Contessa::~Contessa(){}
}