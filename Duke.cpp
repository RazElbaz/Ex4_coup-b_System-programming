#include "Duke.hpp"
constexpr auto coins_coup=7;

namespace coup{
    Duke::Duke(Game &Game, string Name) : Player(Game, Name){}
    void Duke::block(Player &player) {
        if(!(this->isAlive()) || !(player.isAlive())){
            throw runtime_error("The players are not alive");
        }
        if(player.LastAction=="foreign aid"){
            player.Coins-=2;
            this->GameName->increaseTurn();
        }

    }
    void Duke::tax() {
        this->Coins+=3;
        this->GameName->increaseTurn();
        this->LastAction="tax";
    }
    string Duke::role() {
        return "Duke";
    }
    void Duke::coup(Player &player) {
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
        this->copedPlayer=player.getName();

    }
    Duke::~Duke() {}
}