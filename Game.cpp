#include "Game.hpp"
#define NULL __null

namespace coup{
    Game::Game() {
        this->i=0;
        this->activeGame= true;

    }
    vector<string> Game::players(){
        return this->Players;
    }
    string Game::winner(){
        //The method returns the name of the winner. If the game is still active, the method will throw an error
        if (this->activeGame){
            throw runtime_error("The game is still active");
        }
        if(this->Players.size()!=1){
            throw invalid_argument("There should be a single player left in the game and he is the winner");
        }
        this->activeGame= false;
        //The last player left has a winning role
        return this->Players.at(0);
    }
    string Game::turn(){
        if(this->Players.empty()){
            throw runtime_error("There are no active players in the game");
        }
        if(this->i>=this->Players.size()){
            this->i=0;
        }
        return this->Players.at(this->i);
    }

    void Game::RePlayer(string player){
        int k=0;
        for (int j = 0; j < this->Players.size(); ++j) {
            if(this->Players.at((size_t)j)==std::string (player)){
                this->Players.erase(this->Players.begin()+j);
            }
        }

    }
    void Game::increaseTurn(){
        this->i++;
        if(this->Players.size()==this->i){
            this->i=0;
        }
    }

    Game::~Game() {}
};
