//h
#include <vector>
#include "tic_tac_toe.h"
#include<memory>
#include<fstream>
#include<string>
using std::string; using std::vector;
using std::unique_ptr; using std::make_unique;


#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData {

public:
    void save_games(const vector<unique_ptr<TicTacToe>>& games);
    vector<unique_ptr<TicTacToe>> get_games();
    
private:
    const string file_name{ "tictactoe.dat" };
};

#endif // !TIC_TAC_TOE_DATA_H
