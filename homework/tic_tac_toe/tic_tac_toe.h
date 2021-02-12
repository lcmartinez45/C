//tic_tac_toe.h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include<iostream>
using std::string; using std::vector;

class TicTacToe
{
public:
    TicTacToe(vector<string> p, string win) : pegs{ p }, winner{ win }{};
    explicit TicTacToe(int size) : pegs(size*size, " ") {}
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const { return player; }
    string get_winner()const { return winner; }
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& t);
    friend std::istream& operator>>(std::istream& in, TicTacToe& t);
    vector<string> get_pegs() const { return pegs; }
    
protected:
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
    vector<string> pegs;

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();
    string player;
    string winner;
};

class Error
{
public:
    Error(string msg) : message{ msg } {};
    string get_message()const { return message; };
    
private:
    string message;
};

#endif // !TIC_TAC_TOE_H
