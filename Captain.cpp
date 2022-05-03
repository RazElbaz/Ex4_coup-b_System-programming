#include "Captain.hpp"
constexpr auto coins_coup=7;
namespace  coup{
    Captain::Captain(Game &Game, std::string Name) : Player(Game,Name){
        this->canSteal=true;
    }
    void Captain::block(Player &player) {
        if(!(this->isAlive()) || !(player.isAlive())){
            throw runtime_error("The players are not alive");
        }
        if(player.role()!="Captain"){
            throw runtime_error("Only the action of captain players can be prevented");
        }
        if(player.LastAction!="steal"){
            throw runtime_error("Captain can block steal action");
        }
        player.canSteal= false;
    }
    void Captain::steal(Player &player) {
        if(!(this->isAlive()) || !(player.isAlive())){
            throw runtime_error("The players are not alive");
        }
        if(this->canSteal== false){
            throw runtime_error("This player cannot steal");
        }
        if(player.Coins>=2){
            this->Coins+=2;
            player.Coins-=2;
        }
        else if(player.Coins>=1){
            this->Coins+=1;
            player.Coins-=1;

        }
        this->LastAction="steal";
        this->GameName->increaseTurn();

    }
    string Captain::role() {
        return "Captain";
    }
    void Captain::coup(Player &player) {
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
    Captain::~Captain() {}
}