#include "Game.hpp"
#include "Player.hpp"
using namespace std;

namespace coup{
    Player::Player(Game &Game, string &Name) {
        this->Name=Name;
        this->GameName=&Game;
        this->Coins=0;
        this->Alive= true;
        Game.Players.push_back(Name);
        this->Role=Player::role();
        this->canSteal=false;
    }
    void Player::income() {
        if (this->GameName->turn()!=this->getName())
        {

            throw runtime_error("It's not your turn");
        }
        this->Coins+=1;
        this->LastAction="income";
        this->GameName->increaseTurn();
    }
    int Player::coins() {
        return this->Coins;
    }

    void Player::foreign_aid() {
        if (this->GameName->turn()!=this->getName())
        {
            cout<<this->GameName->i<<endl;
            throw runtime_error("It's not your turn");
        }
        this->Coins+=2;
        this->LastAction="foreign aid";
        this->GameName->increaseTurn();


    }
    bool Player::isAlive() {
        return this->Alive;
    }
    string Player::getName() const{
        return this->Name;
    }
    coup::Game* Player::getGameName() const{
        return this->GameName;
    }
    void Player::releaseBlockage(string player, int index){
        this->GameName->Players.insert(this->GameName->Players.begin()+index,player);

    }
    string Player::role() {
       return "";
    }
    Player::~Player() {}
}