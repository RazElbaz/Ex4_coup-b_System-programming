#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin: public Player{
    public:
        Assassin(Game &Game, string Name);
        void coup(Player &player);
        string role();
        ~Assassin();
    };
}