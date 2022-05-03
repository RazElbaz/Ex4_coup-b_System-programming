#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Contessa.hpp"
#include "Captain.hpp"
#include "Duke.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "doctest.h"
#include "iostream"
using namespace std;
using namespace coup;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Game game{};
Duke duke{game, "Moshe"};
Assassin assassin{game, "Yossi"};
Ambassador ambassador{game, "Meirav"};
Captain captain{game, "Reut"};
Contessa contessa{game, "Gilad"};

TEST_CASE ("Players") {
    vector <string> Players = game.players();
            CHECK(Players.at(0)=="Moshe");
            CHECK(Players.at(1)== "Yossi");
            CHECK(Players.at(2)== "Meirav");
            CHECK(Players.at(3)== "Reut");
            CHECK(Players.at(4)== "Gilad");
}
TEST_CASE("Bad Players"){
    vector <string> Players = game.players();
            CHECK_THROWS(Players.at(1)="Moshe");
            CHECK_THROWS(Players.at(0)= "Yossi");
            CHECK_THROWS(Players.at(4)= "Meirav");
            CHECK_THROWS(Players.at(1)= "Reut");
            CHECK_THROWS(Players.at(2)= "Gilad");
}
TEST_CASE("Coins"){
            CHECK_EQ(ambassador.coins(),0);
            CHECK_EQ(captain.coins(),0);
            CHECK_EQ(assassin.coins(),0);
            CHECK_EQ(duke.coins(),0);
            CHECK_EQ(contessa.coins(),0);
}

TEST_CASE("There is no mistake in the list of the names"){
    vector <string> Players_check={"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
    CHECK_EQ(game.players(),Players_check);
}

TEST_CASE("Bad Coins"){
    for(int i=1; i<100; i++) {
                CHECK_FALSE(ambassador.coins() ==i);
                CHECK_FALSE(captain.coins() ==i);
                CHECK_FALSE(assassin.coins() == i);
                CHECK_FALSE(duke.coins() == i);
                CHECK_FALSE(contessa.coins()== i);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Game game2{};
Duke duke2{game2, "Raz"};
Assassin assassin2{game2, "Gal"};
Ambassador ambassador2{game2, "Benny"};
Captain captain2{game2, "Elbar"};
Contessa contessa2{game2, "Yehudit"};


TEST_CASE ("Players") {
    vector <string> Players = game2.players();
            CHECK(Players.at(0)=="Raz");
            CHECK(Players.at(1)== "Gal");
            CHECK(Players.at(2)== "Benny");
            CHECK(Players.at(3)== "Elbar");
            CHECK(Players.at(4)== "Yehudit");
}
TEST_CASE("Bad Players"){
    vector <string> Players = game2.players();
    CHECK_THROWS(Players.at(1)="Raz");
    CHECK_THROWS(Players.at(0)= "Gal");
    CHECK_THROWS(Players.at(4)= "Benny");
    CHECK_THROWS(Players.at(1)= "Elbar");
    CHECK_THROWS(Players.at(2)= "Yehudit");
}
TEST_CASE("Coins"){
            CHECK_EQ(ambassador2.coins(),0);
            CHECK_EQ(captain2.coins(),0);
            CHECK_EQ(assassin2.coins(),0);
            CHECK_EQ(duke2.coins(),0);
            CHECK_EQ(contessa2.coins(),0);
}

TEST_CASE("There is no mistake in the list of the names"){
    vector <string> Players_check={"Raz", "Gal", "Benny", "Elbar", "Yehudit"};
            CHECK_EQ(game2.players(),Players_check);
}

TEST_CASE("Bad Coins"){
    for(int i=1; i<100; i++) {
                CHECK_FALSE(ambassador2.coins() ==i);
                CHECK_FALSE(captain2.coins() ==i);
                CHECK_FALSE(assassin2.coins() == i);
                CHECK_FALSE(duke2.coins() == i);
                CHECK_FALSE(contessa2.coins()== i);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Game game3{};
Duke duke3{game3, "Raz1"};
Assassin assassin3{game3, "Gal1"};
Ambassador ambassador3{game3, "Benny1"};
Captain captain3{game3, "Elbar1"};
Contessa contessa3{game3, "Yehudit1"};
Duke duke4{game3, "Raz2"};
Assassin assassin4{game3, "Gal2"};
Ambassador ambassador4{game3, "Benny2"};
Captain captain4{game3, "Elbar2"};
Contessa contessa4{game3, "Yehudit2"};


TEST_CASE ("Players") {
    vector <string> Players = game3.players();
            CHECK(Players.at(0)=="Raz1");
            CHECK(Players.at(1)== "Gal1");
            CHECK(Players.at(2)== "Benny1");
            CHECK(Players.at(3)== "Elbar1");
            CHECK(Players.at(4)== "Yehudit1");
}
TEST_CASE("Bad Players"){
    vector <string> Players = game3.players();
    CHECK_THROWS(Players.at(1)="Raz2");
    CHECK_THROWS(Players.at(0)= "Gal2");
    CHECK_THROWS(Players.at(4)= "Benny2");
    CHECK_THROWS(Players.at(1)= "Elbar2");
    CHECK_THROWS(Players.at(2)= "Yehudit2");
}
TEST_CASE("Coins"){
            CHECK_EQ(ambassador3.coins(),0);
            CHECK_EQ(captain3.coins(),0);
            CHECK_EQ(assassin3.coins(),0);
            CHECK_EQ(duke3.coins(),0);
            CHECK_EQ(contessa3.coins(),0);
            CHECK_EQ(ambassador4.coins(),0);
            CHECK_EQ(captain4.coins(),0);
            CHECK_EQ(assassin4.coins(),0);
            CHECK_EQ(duke4.coins(),0);
            CHECK_EQ(contessa4.coins(),0);
}

TEST_CASE("There is no mistake in the list of the names"){
    vector <string> Players_check={"Raz1", "Gal1", "Benny1", "Elbar1", "Yehudit1","Raz2", "Gal2", "Benny2", "Elbar2", "Yehudit2"};
            CHECK_EQ(game3.players(),Players_check);
}

TEST_CASE("Bad Coins"){
    for(int i=1; i<100; i++) {
                CHECK_FALSE(ambassador3.coins() ==i);
                CHECK_FALSE(captain3.coins() ==i);
                CHECK_FALSE(assassin3.coins() == i);
                CHECK_FALSE(duke3.coins() == i);
                CHECK_FALSE(contessa3.coins()== i);
                CHECK_FALSE(ambassador4.coins() ==i);
                CHECK_FALSE(captain4.coins() ==i);
                CHECK_FALSE(assassin4.coins() == i);
                CHECK_FALSE(duke4.coins() == i);
                CHECK_FALSE(contessa4.coins()== i);
    }
}