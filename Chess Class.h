#ifndef CHESS_CLASS_H_INCLUDED
#define CHESS_CLASS_H_INCLUDED
/*
******************************
Key:
    player1 = Yin
    player2 = Yang
    empty = 0
    pawn = 1
    bishop = 2
    knight = 3
    rook = 4
    queen = 5
    edge = 6
    king = 7
******************************
*/

class Chess
{
private:

    std::string YinPieces[8];
    std::string YangPieces[8];

public:
    Chess();
    int moves[14][14];
    int board[14][14];
    int column;
    int row;
    int piece1;
    int piece2;
    int Player1Score;
    int Player2Score;
    int ChessMenu();
    bool CheckInput(std::string UserIn);
    bool GameOver(std::string player);

    std::string player;
    std::string DisplayPiece(const int X);

    void ResetBoard();
    void ResetMoves();
    void DisplayBoard();
    void SwapPieces(std::string UserIn1, std::string UserIn2);
    void ConvertInput(std::string UserIn);
    void TestArray(std::string choice);//For Development
    void ChangeBoard(const int X, const int Y, const int c); //For Development
    void ChangeTurn(std::string player);
    void DisplayPlayer(){std::cout << player;}
    void ScanBoard(std::string player);//
    void PawnScan(std::string player, std::string UserIn);
    void RookScan(std::string player, std::string UserIn);
    void KnightScan(std::string player, std::string UserIn);
    void BishopScan(std::string player, std::string UserIn);
    void KingScan(std::string player, std::string UserIn);
};

#endif // CHESS_CLASS_H_INCLUDED
