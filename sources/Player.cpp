#include "Game.hpp"
#include "Player.hpp"
using namespace std;
int const maxNumber=10;
int const seven=7;
int const minNumber=3;
namespace coup{
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Player::income() {
        if(!this->getGameName()->activeGame){throw runtime_error("The game not active");}
        if (this->GameName->turn()!=this->Name){throw runtime_error("It's not your turn");}
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if(this->Coins>=maxNumber){throw runtime_error("You have passed the coin quota in the game");}
        if(!this->isAlive()){throw runtime_error("This player is not in the game");}
        this->Coins+=1;
        this->YouCanLock= false;
        this->LastAction="income";
        this->getGameName()->increaseTurn();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int Player::coins() const  {
        return this->Coins;}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string Player::role() {
        return this->Role;}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Player::foreign_aid() {
        if(!this->getGameName()->activeGame){throw runtime_error("The game not active");}
        if(!this->getGameName()->TheGameStart){this->getGameName()->TheGameStart= true;}
        if (this->getGameName()->turn()!=this->Name){throw runtime_error("It's not your turn");}
        if(this->Coins>=maxNumber){throw runtime_error("You have passed the coin quota in the game");}
        if(!this->isAlive()){throw runtime_error("This player is not in the game");}
        this->Coins+=2;
        this->YouCanLock= true;
        this->LastAction="foreign aid";
        this->getGameName()->increaseTurn();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Player::ReturnStolenCoins() {
        this->Coins-=this->Stolen_coins;
        this->StolenFrom->Coins=this->StolenFrom->coins()+this->Stolen_coins;
        this->YouCanLock=false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool Player::isAlive() {
        for (size_t i = 0; i <this->GameName->Players.size() ; ++i) {
         if(this->getGameName()->Players.at(i)==this->Name){
             return true;
         }
        }
        return false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    coup::Game* Player::getGameName() const{
        return this->GameName;}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Player::coup(Player &player) {
        //checking the game roles and the players roles
        if (!this->getGameName()->TheGameStart) { this->getGameName()->TheGameStart = true; }
        if (!this->getGameName()->activeGame) { throw runtime_error("The game is not active"); }
        if (!this->isAlive() || !player.isAlive()) { throw runtime_error("One or both of the players is not active"); }
        if (this->getGameName()->turn() != this->Name) { throw runtime_error("Its not your turn to play"); }
        if (this->Coins < seven) { throw runtime_error("You do not have enough coins to make a coup"); }
        //saving the index of the couped player
        for (size_t k = 0; k < GameName->Players.size(); ++k) {
            if (this->GameName->players().at(k) == player.Name) {
                this->ReturnTO = k;
//                cout<<player.ReturnTO<<player.role()<<endl;
               }}

                this->getGameName()->increaseTurn();
             //remember the last action of this player
                this->LastAction = "coup";
                this->Coins -= seven;
                //now you can't block this player
                this->YouCanLock = false;
                //this player is dead
                player.Alive = false;
                //delete this player from the game
                this->getGameName()->RePlayer(player.Name);
            }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Player::ReturnToGame(string &Name, int place) {
                //return the couped player to his index in the game
                this->getGameName()->ReturnToGame(this->copedPlayer, this->ReturnTO);
                //checking the index and adding a queue respectively
                if (this->getGameName()->i > place) { this->getGameName()->increaseTurn(); }
            }
        }

