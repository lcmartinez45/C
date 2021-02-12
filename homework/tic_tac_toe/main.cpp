#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<iostream>
#include<functional>
#include<memory>

using std::cout; using std::cin; using std::string;
using std::unique_ptr; using std::make_unique;

int main()
{
    unique_ptr<TicTacToeManager> manager{ new TicTacToeManager() };
    TicTacToeData data;
    string cont;

    do
    {
        unique_ptr<TicTacToe> games;
        int game_type;
        cout << "\nTictactoe 3 or 4?\n";
        cin >> game_type;
        
        if (game_type == 3)
        {
            games = make_unique<TicTacToe3>();
        }
        else if(game_type == 4)
        {
            games = make_unique<TicTacToe4>();
        }

        string player = "Y";

        while (!(player == "O" || player == "X"))
        {
            try
            {
                cout << "Enter player: 'X' or 'O'\n";
                cin >> player;

                games->start_game(player);
            }
            catch (Error e)
            {
                cout << e.get_message();
            }
        }

        int choice = 1;

        do
        {
            try
            {
                cin >> *games;
                cout << *games;
            }
            catch (Error e)
            {
                cout << e.get_message();
            }

        } while (!games->game_over());

        manager -> save_game(games);

        cout << "\nGame over, do you wish to play again?: Y = Yes or N = No."<<"\n";

        cin >> cont;
    
    } while (cont == "Y");

    cout << *manager;

    return 0;
}
