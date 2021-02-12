//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include<vector>
#include<iostream>
#include<memory>
#include<string>

using std::string; using std::vector; using std::unique_ptr;

class TicTacToeManager
{
public:
    TicTacToeManager() = default;
    TicTacToeManager(TicTacToeData& data);
    void save_game(unique_ptr<TicTacToe>& game);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& m);
    void get_winner_totals(int& x, int& o, int& t);
    ~TicTacToeManager();
private:
    TicTacToeData data;
    vector<unique_ptr<TicTacToe>> games;
    void update_winner_count(std::string winner);
    int o_wins{ 0 }, x_wins{ 0 }, ties{ 0 };
};

#endif // !TIC_TAC_TOE_MANAGER_H
