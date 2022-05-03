#include "Player.hpp"
namespace coup{
    class Contessa: public Player{
    public:
        Contessa(Game &Game, string Name);
        void block(Player &player);
        string role();
        void coup(Player &player);
        ~Contessa();
    };
}