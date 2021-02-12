//cpp
#include "tic_tac_toe.h"
#include <cmath>

using std::string; using std::cout;

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    
    return false;
}

void TicTacToe::start_game(string first_player)
{
    if (!(first_player == "X" || first_player == "O"))
    {
        throw Error("Player must be X or O.");
    }
    
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    if (position < 1 || (position > 9 && pegs.size() == 9))
    {
        throw Error("Position must be 1 to 9.");
    }
    else if(position < 1 || (position > 16 && pegs.size() == 16))
    {
        throw Error("Position must be 1 to 16.");
    }
    else if (player == "")
    {
        throw Error("Game must start first.");
    }
    
    pegs[position - 1] = player;
    set_next_player();
    
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else if (player == "O")
    {
        player = "X";
    }
    else
    {
        throw Error("Player Unknown.");
    }
}

bool TicTacToe::check_board_full()
{
    for (std::size_t i = 0; i < pegs.size(); ++i)
    {
        if (pegs[i] == " ")
        {
            return false;
        }
    }

    return true;
}

void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}

std::ostream & operator<<(std::ostream & out, const TicTacToe & t)
{
    for (std::size_t i = 0; i < t.pegs.size(); i += sqrt(t.pegs.size()))
    {
        out << t.pegs[i] << "|" << t.pegs[i + 1] << "|" << t.pegs[i + 2];

        if (t.pegs.size() == 16)
        {
            out << "|" << t.pegs[i + 3];
        }

        out << "\n";
    }

    return out;
}

std::istream & operator>>(std::istream & in, TicTacToe & t)
{
    int pos;
    cout << "Enter position: ";
    in >> pos;
    t.mark_board(pos);

    return in;
}
