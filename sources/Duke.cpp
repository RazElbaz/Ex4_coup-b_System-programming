#include "Duke.hpp"
int const maxNumber=7;
int const minNumber=3;
namespace coup{
    Duke::Duke(Game &Game, string Name) : Player(Game, Name){}
    void Duke::block(Player &player) {
        if (!this->isAlive() || !player.isAlive()) { throw runtime_error("The players are not alive"); }
        if (!this->getGameName()->activeGame) { throw runtime_error("The game not active"); }
        if (player.YouCanLock && player.LastAction == "foreign aid") {
            player.YouCanLock = false;
            player.Coins -= 2;
        } else {
            throw runtime_error("Cannot be Blocked!");
        }

    }
    void Duke::tax() {
        if(!this->getGameName()->TheGameStart){
            this->getGameName()->TheGameStart= true;
        }
        if(!this->getGameName()->activeGame){
            throw runtime_error("The game not active");
        }
        if(!this->isAlive()){
            throw runtime_error("This player is not alive");
        }
        if(this->getGameName()->turn()!=this->Name){
            throw runtime_error("It's not Duke turn");
        }
        this->Coins+=minNumber;
        this->getGameName()->increaseTurn();
        this->YouCanLock= false;
        this->LastAction="tax";
    }
    string Duke::role() {
        return "Duke";
    }

    Duke::~Duke() {}
}