//h
#include "tic_tac_toe.h"
#ifndef TIC_TAC_TOE_4
#define TIC_TAC_TOE_4

#include<string>
#include<vector>
using std::string; using std::vector;

class TicTacToe4 : public TicTacToe
{
public:
    TicTacToe4() : TicTacToe(4) {}
    TicTacToe4(vector<string> p, string winner) : TicTacToe(p, winner) {};
private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif // !TIC_TAC_TOE_4
