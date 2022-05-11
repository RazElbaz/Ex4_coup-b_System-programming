#include "Assassin.hpp"
int const maxNumber=7;
int const minNumber=3;
    coup::Assassin::Assassin(Game &Game, string Name): Player(Game,Name){}
    void coup::Assassin::coup(Player &player) {
        if(this->getGameName()->turn()!=this->Name){
            throw runtime_error("It's not Assassin turn");
        }
        if(!this->getGameName()->activeGame){
            throw runtime_error("The game not active");
        }
        if (!player.isAlive() || !this->isAlive()) {
            throw runtime_error("The player is dead");
        }
        if(this->getGameName()!=player.getGameName()){
            throw runtime_error("The player is from another game");
        }
        if (this->Coins < minNumber) {
            throw runtime_error("The player does not have enough money to oust the opposing player");
        }
        player.Alive = false;
        if (this->Coins >= minNumber&&this->Coins<=maxNumber) {
            this->Coins -= minNumber;
            this->YouCanLock= true;
            this->copedPlayer=player.Name;
            for (size_t k = 0; k < GameName->Players.size(); ++k) {
                if (this->GameName->Players.at(k) == player.Name) {
                    this->ReturnTO = k;
//                    cout<<player.ReturnTO<<player.role()<<endl;
                }
            }
        } else {
            this->Coins -= maxNumber;
            this->YouCanLock= false;

        }
        this->getGameName()->RePlayer(player.Name);

        this->LastAction = "coup";
        player.Alive = false;
        this->getGameName()->increaseTurn();

    }
    string coup::Assassin::role() {
        return "Assassin";
    }
    coup::Assassin::~Assassin() {}

