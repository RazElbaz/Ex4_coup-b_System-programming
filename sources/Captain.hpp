#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain: public Player{
    public:

        Captain(Game &Game, std::string Name);
        void block(Player &player);
        void steal(Player &player);
        string role();
//        void coup(Player &player);
        ~Captain();
    };
}