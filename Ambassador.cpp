#include "Ambassador.hpp"
constexpr auto coins_coup=7;

namespace coup{
    Ambassador::Ambassador(Game &Game, string Name): Player(Game,Name){}
    void Ambassador::transfer(Player &player1, Player &player2){
        if (!player1.isAlive()||!player2.isAlive())
        {
            throw runtime_error("One of the players are not alive");
        }

        if(player1.Coins<1){
            throw runtime_error("Player 1 does not have enough money to transfer to the other player");
        }
        player1.Coins-=1;
        player2.Coins+=1;
        this->LastAction="transfer";
        this->GameName.increaseTurn();



    }
    string Ambassador::role() { return "Ambassador";}
    void  Ambassador::Prevent(Player &player) {
        if(player.role()!="Captain"){
            throw runtime_error("Only the action of captain players can be prevented");
        }
        if(player.LastAction!="steal"){
            throw runtime_error("There is no reason to prevent the theft of coins");
        }
        player.canSteal= false;
    }
    void Ambassador::coup(Player &player) {
        if(this->Coins<coins_coup){
            throw runtime_error("The player does not have enough money to oust the opposing player");
        }
        for (size_t k = 0; k <GameName.Players.size() ; ++k) {
            if(this->GameName.Players.at(k)==player.getName()){
                player.ReturnTO=k;
            }
        }
        this->GameName.RePlayer(player.getName());
        this->Coins-=coins_coup;
        this->GameName.increaseTurn();
        this->LastAction="coup";
        this->copedPlayer=player.getName();
    }
    Ambassador::~Ambassador(){}
}