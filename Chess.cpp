/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
*/

#include "Chess Class.cpp"
#include "Chess Functions.cpp"

using namespace std;
bool movePiece(Chess cat, string userIn1, string userIn2);

int main()
{
    //Defining all placeholders.
    Chess alpha;

    //Initializing variables
    string player1 = "Yang",
           player2 = "Yin",
           userIn1 = "z9",
           userIn2 = "z9";

    alpha.player   = player1;


    int menuChoice = 0;

    while (true)
    {
            menuChoice = alpha.ChessMenu();
            if(menuChoice == 2)
            {break;}
            else
            {alpha.ResetBoard(); alpha.ResetMoves();}

            while (true)
            {
                if(alpha.player == player1)
                {
                    //Check for Game Over
                    if (alpha.GameOver(alpha.player))
                    {
                        alpha.Player2Score++;
                        cout << "\n\nPlayer 2 has won!\n\n";
                        alpha.DisplayBoard();
                        break;
                    }

                    alpha.DisplayBoard();
                    cout << "\n\nPlayer 1's turn. Which piece would you like "
                         << "to move and where would you like to move it?\n";
                    cin  >> userIn1 >> userIn2;
                    if(alpha.CheckInput(userIn1) && alpha.CheckInput(userIn2))
                    {
                        //Check if move is valid
                        if(movePiece(alpha, userIn1, userIn2))
                        {
                            //Move pieces
                            alpha.SwapPieces(userIn1,userIn2);
                            //Reset available moves
                            alpha.ResetMoves();
                            //Change turns
                            alpha.player = player2;
                        }
                    }
                }

                else if(alpha.player == player2)
                {
                    //Check for Game Over
                    if (alpha.GameOver(alpha.player))
                    {
                        alpha.Player1Score++;
                        cout << "\n\nPlayer 1 has won!\n\n";
                        alpha.DisplayBoard();
                        break;
                    }

                    alpha.DisplayBoard();
                    cout << "\n\nPlayer 2's turn. Which piece would you like "
                         << "to move and where would you like to move it?\n";
                    cin  >> userIn1 >> userIn2;
                    if(alpha.CheckInput(userIn1) && alpha.CheckInput(userIn2))
                    {
                        //Check if move is valid
                        if(movePiece(alpha, userIn1, userIn2))
                        {
                            //Move pieces
                            alpha.SwapPieces(userIn1,userIn2);
                            //Reset available moves
                            alpha.ResetMoves();
                            //Change turns
                            alpha.player = player1;
                        }
                    }
                }
            }

    }

    //Final message
    cout << "\nFinal Scores: \n\n"
         << "Player1: " << alpha.Player1Score
         << "\nPlayer2: " << alpha.Player2Score;

    cout << "\n\nThank you for playing! \n"
         << "This game was created by Alfonso de la Morena while completing his "
         << "studies at Texas State University. \nIt is completely free to use "
         << "long as you give him credit for his work.\n"
         << "\nPress any key to exit the program!";

    system("PAUSE>NUL");
    return 0;
}
