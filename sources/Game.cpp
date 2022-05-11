#include "Game.hpp"
int const maxNumber=7;
int const minNumber=2;
namespace coup{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<string> Game::players() {
        vector<string> ans;
        for (size_t j = 0; j < this->Players.size(); ++j) {
            ans.push_back(this->Players.at(j));}
        return ans;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    string Game::winner(){
        //The method returns the name of the winner. If the game is still active, the method will throw an error
        if(this->Players.size()!=1||!this->activeGame){throw invalid_argument("There should be a single player left in the game and he is the winner");}
        this->activeGame= false;
        //The last player left has a winning role
        return this->Players.at(0);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    string Game::turn(){
        if(this->i>=this->Players.size()){
            this->i=0;
        }
//    cout<<"i:"<<this->i<<endl;
        return this->Players.at(this->i);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Game::addPlayer(string &Name){
        this->Players.push_back(Name);
        if (this->Players.size() >= maxNumber){throw runtime_error("You have exceeded the quota of players");}
        if (this->TheGameStart){throw runtime_error("You cannot add new players in the middle of a game");}

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Game::RePlayer(string &player){
        for (int j = 0; j < this->Players.size(); ++j) {
            if(this->Players.at((size_t)j)==std::string (player)){
                this->Players.erase(this->Players.begin()+j);
                //We will subtract from the index of game 1 as long as it is smaller than the number of players
                if(j<i){this->i-=1;}
                }}}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Game::increaseTurn(){
        this->i++;
        i =i%(size_t)players().size();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Game::ReturnToGame(string &player, int index) {
        this->Players.insert(this->Players.begin()+index,player);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};
