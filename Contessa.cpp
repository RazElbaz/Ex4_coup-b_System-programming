#include "Contessa.hpp"
constexpr auto coins_coup=7;

namespace coup{
    Contessa::Contessa(Game &Game, string Name): Player(Game, Name){}
    void Contessa::block(Player &player) {
        if(!(this->isAlive()) || !(player.isAlive())){
            throw runtime_error("The players are not alive");
        }
        if(player.role() != "Assassin" ){
            throw runtime_error("A contessa can block the assassin operation");
        }
        if(player.LastAction!="coup"){
            throw runtime_error("A contessa can block the assassin coup");
        }
        player.releaseBlockage(player.getName(),player.ReturnTO);
    }

    string Contessa::role(){
        return "Contessa";
    }

    void Contessa::coup(Player &player) {
        if(this->Coins<coins_coup){
            throw runtime_error("The player does not have enough money to oust the opposing player");
        }
        for (size_t k = 0; k <GameName->Players.size() ; ++k) {
            if(this->GameName->Players.at(k)==player.getName()){
                player.ReturnTO=k;
            }
        }
        this->GameName->RePlayer(player.getName());
        this->Coins-=coins_coup;
        this->GameName->increaseTurn();
        this->LastAction="coup";
    }
    Contessa::~Contessa(){}
}