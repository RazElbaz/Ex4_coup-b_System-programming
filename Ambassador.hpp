#include "Player.hpp"
#include "Game.hpp"
using namespace std;
namespace coup{
    class Ambassador: public Player{
    private:
        string Name;
        Game GameName;
    public:
        Ambassador(Game &Game, string Name);
        void transfer(Player &player1, Player &player2);
        void Prevent(Player &player);
        string role();
        void coup(Player &player);
        ~Ambassador();
    };
}