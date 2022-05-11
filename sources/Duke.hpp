#include "Player.hpp"

using namespace std;
namespace coup {
    class Duke : public Player {
    public:
        Duke(Game &Game, string Name);
        void block(Player &player);
        void tax();
        string role();
//        void coup(Player &player);
        ~Duke();
    };
}