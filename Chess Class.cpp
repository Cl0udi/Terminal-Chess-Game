#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "Chess Class.h"
using namespace std;

Chess::Chess()
{
    //Constructor with some minor initializers.

    Player1Score = 0;
    Player2Score = 0;
    player = "Yin";

/*
******************************
Key:
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

    //Assign the name for each of the pieces
    YinPieces[0] = " ";
    YinPieces[1] = "Ninja";
    YinPieces[2] = "Monk";
    YinPieces[3] = "Samurai";
    YinPieces[4] = "Sumo";
    YinPieces[5] = "Princess";
    YinPieces[6] = "[-]";
    YinPieces[7] = "Emperor";

    YangPieces[0] = " ";
    YangPieces[1] = "Pawn";
    YangPieces[2] = "Bishop";
    YangPieces[3] = "Knight";
    YangPieces[4] = "Rook";
    YangPieces[5] = "Queen";
    YangPieces[6] = "[|]";
    YangPieces[7] = "King";
}

void Chess::ResetBoard()
{
    //Gives the basic chess board state.

    for(int i = 0; i < 14; i++)
        {
            //edges
            board[0][i]  = 6;
            board[1][i]  = 6;
            board[2][i]  = 6;
            board[11][i] = 6;
            board[12][i] = 6;
            board[13][i] = 6;
            board[i][0]  = 6;
            board[i][1]  = 6;
            board[i][2]  = 6;
            board[i][11] = 6;
            board[i][12] = 6;
            board[i][13] = 6;

            //black pawns
            if(i == 4)
            for(int j = 3; j < 11; j++)
            {board[j][i] = 1;}

            //white pawns
            if(i == 9)
            for(int j = 3; j < 11; j++)
            {board[j][i] = -1;}

            //empty space
            if(i > 4 && i < 9)
            for(int j = 3; j < 11; j++)
            {board[j][i] = 0;}
        }
        //Rooks
        board[3][3]   = 4;
        board[10][3]  = 4;
        board[3][10]  = -4;
        board[10][10] = -4;

        //Knights
        board[4][3]  = 3;
        board[9][3]  = 3;
        board[4][10] = -3;
        board[9][10] = -3;

        //Bishops
        board[5][3]  = 2;
        board[8][3]  = 2;
        board[5][10] = -2;
        board[8][10] = -2;

        //Queen and King
        board[6][3]  = 5;
        board[7][3]  = 7;
        board[6][10] = -5;
        board[7][10] = -7;
}

void Chess::ResetMoves()
{
    //Resets the value of the move array to 0.

    for(int i = 0; i < 14; i++)
        for(int j = 0; j < 14; j++)
            {moves[i][j] = 0;}

    //edges
    for(int i = 0; i < 14; i++)
    {
        moves[0][i]  = 7;
        moves[1][i]  = 7;
        moves[2][i]  = 7;
        moves[11][i] = 7;
        moves[12][i] = 7;
        moves[13][i] = 7;
        moves[i][0]  = 7;
        moves[i][1]  = 7;
        moves[i][2]  = 7;
        moves[i][11] = 7;
        moves[i][12] = 7;
        moves[i][13] = 7;
    }
}

void Chess::TestArray(string choice)
{
    //For development purposes. Displays the array you are working on.

        if(choice == "board")
        { int j = 0;
        for(int i = 0; i < 14; i++)
        {
            cout << setw(2) << j++ << "   ";
            for(int j = 0; j < 14; j++)
                {cout << setw(3) << board[j][i];}

            cout << endl;
        }
        j = 0;
        cout << endl << "     ";
        while(j < 14)
            cout << setw(3) << j++;
        }

        else
        { int j = 0;
        for(int i = 0; i < 14; i++)
        {
            cout << setw(2) << j++ << "   ";
            for(int j = 0; j < 14; j++)
                {cout << setw(3) << moves[j][i];}

            cout << endl;
        }
        j = 0;
        cout << endl << "     ";
        while(j < 14)
        cout << setw(3) << j++;
        }
}

void Chess::SwapPieces(string UserIn1, string UserIn2)
{
    const int X = UserIn1[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn1[1] - 46; //and + 2 eliminates the border difference.

    const int XX = UserIn2[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int YY = UserIn2[1] - 46; //and + 2 eliminates the border difference.

    int temp = board[X][Y];
    board[X][Y] = 0;
    board[XX][YY] = temp;
}

void Chess::DisplayBoard()
{

    //Time to display what we calculated on the console
    cout << endl
         << "         ";

    char display = 'a';

    for(int i = 1; i <= 8; i++)
    {
        if(i == 8)
        {cout << setw(8) << "(" << display++ << ")";}
        else
        cout << setw(8) << "(" << display++ << ")" << "   ";
    }
    cout << endl;

    int display2 = 1;

    for (int i = 0; i <= 7; i++)
    { if(i >= 1 && i <= 8)
        cout << "\n         - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    \n";
      else
      cout << endl;

        for (int j = 0; j <= 7; j++)
        {
            if (j == 0)
                cout << " (" << (display2++) << ")     ";
            if(j >= 0 && j <= 6)
            {
                if(board[j + 3][i + 3] == 0)
                {cout << setw(10) << " ";}
                else if(board[j + 3][i + 3] > 0)
                {cout << setw(10) << YinPieces[board[j + 3][i + 3]];}
                else if(board[j + 3][i + 3] < 0)
                {cout << setw(10) << YangPieces[(board[j + 3][i + 3]) * -1];}
                cout << " | ";
            }
            else
            {
                if(board[j + 3][i + 3] == 0)
                {cout << setw(10) << " ";}
                else if(board[j + 3][i + 3] > 0)
                {cout << setw(10) << YinPieces[board[j + 3][i + 3]];}
                else if(board[j + 3][i + 3] < 0)
                {cout << setw(10) << YangPieces[(board[j + 3][i + 3]) * -1];}
            }
        }
    }

    cout << endl << endl;

}

void Chess::ChangeBoard(const int X, const int Y, const int c)
{
    //For development purposes. Places a piece on the board.

    board[X][Y] = c;
}

string Chess::DisplayPiece(const int X)
{
    if(player == "Yin")
    {return YinPieces[X];}

    else
    {return YangPieces[X];}
}

int Chess::ChessMenu()
{
    int answer;
    bool looper = true;

    while(looper){

    cout << endl
         << "                                                   -------------------" << endl
         << "                                                   [[[[[|||||||||]]]]]" << endl
         << "                                                   ~~~~~Main Menu~~~~~" << endl
         << "                                                   [[[[[|||||||||]]]]]" << endl
         << "                                                   -------------------" << endl
         << "                                                   [[[[[|||||||||]]]]]" << endl
         << "                                                   [   1) New Game.  ]" << endl
         << "                                                   [   2) Exit.      ]" << endl
         << "                                                   [[[[[|||||||||]]]]]" << endl
         << "                                                   -------------------" << endl;

    cin >> answer;

    if (answer != 1 && answer != 2)
    {cout << "Please input a number to make a selection." << endl;}

    else
    {return answer;}
    }
}

void Chess::ChangeTurn(std::string player)
{
    //Changes who's turn it is.

    if(player == "Yin")
        player = "Yang";
    else
        player = "Yin";
}

void Chess::ConvertInput(string UserIn)
{
    column = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    row = UserIn[1] - 46; //and + 2 eliminates the border difference.
}



bool Chess::CheckInput(string UserIn)
{
    //Checks for user input: 1) lenght = 2
    //                       2) first char = lowercase letter
    //                       3) second char = digit

    if(UserIn.length() != 2)
        {cout << "Input must be 2 characters long."; return false;}

    if(!islower(UserIn[0]))
       {cout << "First character must be a lowercase letter."; return false;}

    if(!isdigit(UserIn[1]))
       {cout << "Second character must be a number."; return false;}

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.

    if(board[X][Y] < -7 || board[X][Y] > 7 || board[X][Y] == 6)
    {cout << "Selection not in board."; return false;}

    return true;

}



void Chess::ScanBoard(string player)
{
    //Scans the board for friendly pieces, moves cannot be made on top of them.

    if(player == "Yin")
    {
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            if(board[j][i] == 6)
            {moves[j][i] = 7;}
            else if(board[j][i] >= 0 && board[j][i] != 6)
            {moves[j][i] = 1;}

        }
    }
    }

    else
    {
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            if(board[j][i] == 6)
            {moves[j][i] = 7;}
            else if(board[j][i] <= 0)
            {moves[j][i] = 1;}

        }
    }
    }

}

void Chess::PawnScan(string player, string UserIn)
{
    //Scans for a Pawn's possible moves.

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.

    // Checks if possible pawn moves do not run into other friendly pieces
    //or off the board.

    if(board[X][Y] == 1 || board[X][Y] == -1)
    {
    if(player == "Yang")
    {
        //Account for double skip in first move
        if(Y == 4 && board[X][Y + 1] == 0 && board[X][Y + 2] == 0)
        {moves[X][Y + 2] = 1;}

        //Move forward
        if(board[X][Y + 1] == 0)
        {moves[X][Y + 1] = 1;}

        //Eat Pieces diagonally to the right, != 6 is redundant but consistency
        if(board[X + 1][Y + 1] < 0 && board[X + 1][Y + 1] != 6)
        {moves[X + 1][Y + 1] = 1;}

        //Eat Pieces diagonally to the left
        if(board[X - 1][Y + 1] < 0 && board[X - 1][Y + 1] != 6)
        {moves[X - 1][Y + 1] = 1;}
    }
    else
    {
        //Account for double skip in first move
        if(Y == 9 && board[X][Y - 1] == 0 && board[X][Y - 2] == 0)
        {moves[X][Y - 2] = 1;}

        //Move forward
        if(board[X][Y - 1] == 0)
        {moves[X][Y - 1] = 1;}

        //Eat Pieces diagonally to the right
        if(board[X + 1][Y - 1] > 0 && board[X + 1][Y - 1] != 6)
        {moves[X + 1][Y - 1] = 1;}

        //Eat Pieces diagonally to the left
        if(board[X - 1][Y - 1] > 0 && board[X - 1][Y - 1] != 6)
        {moves[X - 1][Y - 1] = 1;}
    }
    }
    else
    cout << "Attempted to select a Pawn but not detecting a Pawn." << endl << endl;
}

void Chess::RookScan(string player, string UserIn)
{
    //Scans for a Rook's possible moves.

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.

    // Checks if possible rook moves do not run into other friendly pieces
    //or off the board.

    //Any direction is fine as long as it does not run into
    //a friendly piece or the edge. Also it must stop after its
    //first encounter with a piece it can attack

    if(board[X][Y] == 4 || board[X][Y] == -4 ||
       board[X][Y] == 5 || board[X][Y] == -5 )
    {
    if(player == "Yang")
    {
        int i = 1;
        bool loop = true;

        while(moves[X + i][Y] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y] < 0 && board[X + i][Y] != 6)
            {moves[X + i][Y] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y] == 0)
            {moves[X + i][Y] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X - i][Y] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y] < 0 && board[X - i][Y] != 6)
            {moves[X - i][Y] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y] == 0)
            {moves[X - i][Y] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X][Y + i] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X][Y + i] < 0 && board[X][Y + i] != 6)
            {moves[X][Y + i] = 1; loop = false;}

            //Check if space is empty
            else if(board[X][Y + i] == 0)
            {moves[X][Y + i] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X][Y - i] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X][Y - i] < 0 && board[X][Y - i] != 6)
            {moves[X][Y - i] = 1; loop = false;}

            //Check if space is empty
            else if(board[X][Y - i] == 0)
            {moves[X][Y - i] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }
    }

    else
        {
        int i = 1;
        bool loop = true;

        while(moves[X + i][Y] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y] > 0 && board[X + i][Y] != 6)
            {moves[X + i][Y] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y] == 0)
            {moves[X + i][Y] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X - i][Y] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y] > 0 && board[X - i][Y] != 6)
            {moves[X - i][Y] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y] == 0)
            {moves[X - i][Y] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X][Y + i] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X][Y + i] > 0 && board[X][Y + i] != 6)
            {moves[X][Y + i] = 1; loop = false;}

            //Check if space is empty
            else if(board[X][Y + i] == 0)
            {moves[X][Y + i] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        loop = true;

        while(moves[X][Y - i] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X][Y - i] > 0 && board[X][Y - i] != 6)
            {moves[X][Y - i] = 1; loop = false;}

            //Check if space is empty
            else if(board[X][Y - i] == 0)
            {moves[X][Y - i] = 1; i++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }
    }
}
    else
    cout << "Attempted to select a Rook but not detecting a Rook." << endl << endl;
}

void Chess::BishopScan(string player, string UserIn)
{
    //Scans for a Bishop's possible moves.

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.


    // Checks if possible bishop moves do not run into other friendly pieces
    //or off the board.

    //Any direction is fine as long as it does not run into
    //a friendly piece or the edge. Also it must stop after its
    //first encounter with a piece it can attack

    if(board[X][Y] == 2 || board[X][Y] == -2 ||
       board[X][Y] == 5 || board[X][Y] == -5 )
    {
    if(player == "Yang")
    {
        int i = 1;
        int j = 1;
        bool loop = true;

        while(moves[X + i][Y + j] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y + j] < 0 && board[X + i][Y] != 6)
            {moves[X + i][Y + j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y + j] == 0)
            {moves[X + i][Y + j] = 1; i++; j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X + i][Y - j] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y - j] < 0 && board[X + i][Y - j] != 6)
            {moves[X + i][Y - j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y - j] == 0)
            {moves[X + i][Y - j] = 1; i++; j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X - i][Y + j] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y + j] < 0 && board[X - i][Y + j] != 6)
            {moves[X - i][Y + j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y + j] == 0)
            {moves[X - i][Y + j] = 1; i++;j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X - i][Y - j] <= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y - j] < 0 && board[X - i][Y - j] != 6)
            {moves[X - i][Y - j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y - j] == 0)
            {moves[X - i][Y - j] = 1; i++;j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }
    }

    else
        {
        int i = 1;
        int j = 1;
        bool loop = true;

        while(moves[X + i][Y + j] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y + j] > 0 && board[X + i][Y] != 6)
            {moves[X + i][Y + j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y + j] == 0)
            {moves[X + i][Y + j] = 1; i++; j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X + i][Y - j] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X + i][Y - j] > 0 && board[X + i][Y - j] != 6)
            {moves[X + i][Y - j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X + i][Y - j] == 0)
            {moves[X + i][Y - j] = 1; i++; j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X - i][Y + j] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y + j] > 0 && board[X - i][Y + j] != 6)
            {moves[X - i][Y + j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y + j] == 0)
            {moves[X - i][Y + j] = 1; i++;j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }

        i = 1;
        j = 1;
        loop = true;

        while(moves[X - i][Y - j] >= 0 && loop)
        {
            //Check if it can eat a piece
            if(board[X - i][Y - j] > 0 && board[X - i][Y - j] != 6)
            {moves[X - i][Y - j] = 1; loop = false;}

            //Check if space is empty
            else if(board[X - i][Y - j] == 0)
            {moves[X - i][Y - j] = 1; i++;j++;}

            //Otherwise exit loop
            else
            {loop = false;}
        }
        }
    }
    else if(board[X][Y] == 5 || board[X][Y] == -5)
    cout << "Attempted to select a Queen but not detecting a Queen." << endl << endl;

    else
    cout << "Attempted to select a Bishop but not detecting a Bishop." << endl << endl;
}

void Chess::KnightScan(string player, string UserIn)
{
    //Scans for a Knight's possible moves.

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.

    // Checks if possible Knight moves do not run into other friendly pieces
    //or off the board.

    //Knight can only move in L shaped patterns, therefore a maximum number of
    //8 possible moves at any point is what has to be checked

    if(board[X][Y] == 3 || board[X][Y] == -3)
    {
    if(player == "Yang")
    {
        if(board[X + 1][Y + 2] <= 0)
        {moves[X + 1][Y + 2] = 1;}

        if(board[X + 2][Y + 1] <= 0)
        {moves[X + 2][Y + 1] = 1;}

        if(board[X + 2][Y - 1] <= 0)
        {moves[X + 2][Y - 1] = 1;}

        if(board[X + 1][Y - 2] <= 0)
        {moves[X + 1][Y - 2] = 1;}

        if(board[X - 1][Y - 2] <= 0)
        {moves[X - 1][Y - 2] = 1;}

        if(board[X - 2][Y - 1] <= 0)
        {moves[X - 2][Y - 1] = 1;}

        if(board[X - 2][Y + 1] <= 0)
        {moves[X - 2][Y + 1] = 1;}

        if(board[X - 1][Y + 2] <= 0)
        {moves[X - 1][Y + 2] = 1;}
    }

    else
        {
        if(board[X + 1][Y + 2] >= 0 && board[X + 1][Y + 2] != 6)
        {moves[X + 1][Y + 2] = 1;}

        if(board[X + 2][Y + 1] >= 0 && board[X + 2][Y + 1] != 6)
        {moves[X + 2][Y + 1] = 1;}

        if(board[X + 2][Y - 1] >= 0 && board[X + 2][Y - 1] != 6)
        {moves[X + 2][Y - 1] = 1;}

        if(board[X + 1][Y - 2] >= 0 && board[X + 1][Y - 2] != 6)
        {moves[X + 1][Y - 2] = 1;}

        if(board[X - 1][Y - 2] >= 0 && board[X - 1][Y - 2] != 6)
        {moves[X - 1][Y - 2] = 1;}

        if(board[X - 2][Y - 1] >= 0 && board[X - 2][Y - 1] != 6)
        {moves[X - 2][Y - 1] = 1;}

        if(board[X - 2][Y + 1] >= 0 && board[X - 2][Y + 1] != 6)
        {moves[X - 2][Y + 1] = 1;}

        if(board[X - 1][Y + 2] >= 0 && board[X - 1][Y + 2] != 6)
        {moves[X - 1][Y + 2] = 1;}
        }
    }
    else
    cout << "Attempted to select a Knight but not detecting a Knight." << endl << endl;

}

void Chess::KingScan(string player, string UserIn)
{
    //Scans for a King's possible moves.

    const int X = UserIn[0] - 94;//Because it's a char. -96, - 48 resets ASCII value
    const int Y = UserIn[1] - 46; //and + 2 eliminates the border difference.

    // Checks if possible King moves do not run into other friendly pieces
    //or off the board.

    //King can move in any direction one space. The max number of moves it can
    //have is 8 (just like the knight!)

    if(board[X][Y] == 7 || board[X][Y] == -7)
    {
    if(player == "Yang")
    {
        if(board[X][Y + 1] <= 0)
        {moves[X][Y + 1] = 1;}

        if(board[X][Y - 1] <= 0)
        {moves[X][Y - 1] = 1;}

        if(board[X + 1][Y] <= 0)
        {moves[X + 1][Y] = 1;}

        if(board[X - 1][Y] <= 0)
        {moves[X - 1][Y] = 1;}

        if(board[X + 1][Y + 1] <= 0)
        {moves[X + 1][Y + 1] = 1;}

        if(board[X + 1][Y - 1] <= 0)
        {moves[X + 1][Y - 1] = 1;}

        if(board[X - 1][Y + 1] <= 0)
        {moves[X - 1][Y + 1] = 1;}

        if(board[X - 1][Y - 1] <= 0)
        {moves[X - 1][Y - 1] = 1;}
    }

    else
        {
        if(board[X][Y + 1] >= 0 && board[X][Y + 1] != 6)
        {moves[X][Y + 1] = 1;}

        if(board[X][Y - 1] >= 0 && board[X][Y - 1] != 6)
        {moves[X][Y - 1] = 1;}

        if(board[X + 1][Y]>= 0 && board[X + 1][Y] != 6)
        {moves[X + 1][Y] = 1;}

        if(board[X - 1][Y] >= 0 && board[X - 1][Y] != 6)
        {moves[X - 1][Y] = 1;}

        if(board[X + 1][Y + 1] <= 0 && board[X + 1][Y + 1] != 6)
        {moves[X + 1][Y + 1] = 1;}

        if(board[X + 1][Y - 1] <= 0 && board[X + 1][Y - 1] != 6)
        {moves[X + 1][Y - 1] = 1;}

        if(board[X - 1][Y + 1] <= 0 && board[X - 1][Y + 1] != 6)
        {moves[X - 1][Y + 1] = 1;}

        if(board[X - 1][Y - 1] <= 0 && board[X - 1][Y - 1] != 6)
        {moves[X - 1][Y - 1] = 1;}
        }
    }
    else
    cout << "Attempted to select a King but not detecting a King." << endl << endl;

}

bool Chess::GameOver(std::string player)
{
    if(player == "Yang")
    {
        for(int i = 0; i < 14; i++)
        {for(int j = 0; j < 14; j++)
        {   if(board[i][j] == 7)
            {return false;}
        }
        }
    }

    else
    {
        for(int i = 0; i < 14; i++)
        {for(int j = 0; j < 14; j++)
        {   if(board[i][j] == -7)
            {return false;}
        }
        }
    }

    return true;
}









