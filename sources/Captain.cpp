#include "Captain.hpp"
int const maxNumber=2;
int const minNumber=1;
namespace  coup{
    Captain::Captain(Game &Game, std::string Name) : Player(Game,Name){
        this->YouCanLock=true;
    }
    void Captain::block(Player &player) {
        //checking the game roles and the players roles
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if(!this->getGameName()->activeGame){throw runtime_error("The game not active");}
        if(!(this->isAlive()) || !(player.isAlive())){throw runtime_error("The players are not alive");}
        if(player.role()!="Captain"){throw runtime_error("Only the action of captain players can be prevented");}
        if(player.LastAction!="steal"){throw runtime_error("Captain can block steal action");}
        player.YouCanLock= false;
    }
    void Captain::steal(Player &player) {
        //checking the game roles and the players roles
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if(!this->getGameName()->activeGame){throw runtime_error("The game not active");}
        if(this->getGameName()->turn()!=this->Name){throw runtime_error("It's not Captain turn");}
        if(!(this->isAlive()) || !(player.isAlive())){throw runtime_error("The players are not alive");}
        //the captain stole how much he can
        if(player.Coins>=maxNumber){
            this->Coins+=maxNumber;
            player.Coins-=maxNumber;
            this->Stolen_coins=maxNumber;
        }
        else if(player.Coins==minNumber){
            this->Coins+=minNumber;
            player.Coins-=minNumber;
           this->Stolen_coins=minNumber;
        }
        //increase the game index playing
        this->getGameName()->increaseTurn();
        //remember the last action of this player
        this->LastAction="steal";
        //remember from who is stolen
        this->StolenFrom=&player;
    }
    string Captain::role() {return "Captain";}
    Captain::~Captain() {}
}