#include "Assassin.hpp"
constexpr auto coins_coup=3;

namespace coup{
    Assassin::Assassin(Game &Game, string Name): Player(Game,Name){}
    void Assassin::coup(Player &player){
        if(this->Coins<3){
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
    string Assassin::role() {
        return "Assassin";
    }
    Assassin::~Assassin() {}
    }
