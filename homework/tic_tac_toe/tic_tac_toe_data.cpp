//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <string>

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    std::ofstream file_out(file_name, std::ios_base::trunc);

    for (auto& g : games)
    {
        for (auto pegs : g->get_pegs())
        {
            file_out << pegs;
        }
        file_out << g->get_winner() << "\n";
    }

    file_out.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{

    vector<std::unique_ptr<TicTacToe>> boards;
    std::ifstream read_file(file_name);
    
    vector<std::string> pegs;
    string line;

    while (read_file.is_open())
    {
        while (std::getline(read_file, line)) {}
        {
            for (int i = 0; i < line.size() - 1; i++)
            {
                string istring(1, line[i]);
                pegs.push_back(istring);
            }
            string winner = pegs[-1];
            unique_ptr<TicTacToe> game;

            if (pegs.size() == 9)
            {
                game = make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16)
            {
                game = make_unique<TicTacToe4>(pegs, winner);
            }

            boards.push_back(move(game));
        }
        read_file.close();
    }
    return boards;
}
