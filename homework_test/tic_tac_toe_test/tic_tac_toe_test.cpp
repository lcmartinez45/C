#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include <tic_tac_toe_4.h>
#include <tic_tac_toe_manager.h>
#include<functional>

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    REQUIRE_THROWS_AS(board->mark_board(1), Error);
}

TEST_CASE("Test start game accepts only X or O")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    REQUIRE_THROWS_AS(board->start_game("Y"), Error);
}

TEST_CASE("Test set first player to X")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    board->start_game("X");

    REQUIRE(board->get_player() == "X");
}

TEST_CASE("Test set first player to O")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    board->start_game("O");

    REQUIRE(board->get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    board->start_game("X");
    REQUIRE(board->get_player() == "X");

    board->mark_board(4);
    REQUIRE(board->get_player() == "O");
}

TEST_CASE("Test win by first column", "[X wins first column]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
    
    unique_ptr <TicTacToeManager> manager{ new TicTacToeManager() };
    manager->save_game(board);
    REQUIRE(manager->get_x_wins() == 1);
    REQUIRE(manager->get_o_wins() == 0);
    REQUIRE(manager->get_ties() == 0);
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonal 1", "[X wins with 1 5 9]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonal 2", "[X wins with 3 5 7]")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    
    //X wins
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test tie")
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };

    board->start_game("X");
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//X
    
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C");

    //Testing manager
    unique_ptr <TicTacToeManager> manager{ new TicTacToeManager() };
    manager->save_game(board);
    REQUIRE(manager->get_x_wins() == 0);
    REQUIRE(manager->get_o_wins() == 0);
    REQUIRE(manager->get_ties() == 1);
}

//TicTacToe4
TEST_CASE("Check top left to bottom right diagional win and manager get_wins, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(11);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(12);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(16);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
    
    //Testing manager
    unique_ptr <TicTacToeManager> manager{ new TicTacToeManager() };
    manager->save_game(board);
    REQUIRE(manager->get_x_wins() == 1);
    REQUIRE(manager->get_o_wins() == 0);
    REQUIRE(manager->get_ties() == 0);
}

TEST_CASE("Check top right to bottom left diagional win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(4);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(10);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(12);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(13);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Check 1st column win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(15);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(13);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Check 2nd column win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(2);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(10);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(11);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(14);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Check 3rd column win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(3);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(9);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(11);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(13);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(15);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Check 4th column win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(4);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(10);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(12);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(16);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Check 1st row win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(1);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(11);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(4);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Check 2nd row win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(5);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(6);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(7);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(10);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(8);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Check 3rd row win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(9);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(10);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(11);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(15);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(12);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Check 4th row win, 4x4")
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

    board->mark_board(13);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(1);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(14);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(2);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(15);//X
    REQUIRE(board->game_over() == false);
    board->mark_board(3);//O
    REQUIRE(board->game_over() == false);
    board->mark_board(16);//X

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
