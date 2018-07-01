bool movePiece(Chess alpha, string userIn1, string userIn2)
{
    //Assigning piece values so that I can easily replace the state of the board
    alpha.ConvertInput(userIn1);
    alpha.piece1 = alpha.board[alpha.column][alpha.row];
    alpha.ConvertInput(userIn2);
    alpha.piece2 = alpha.board[alpha.column][alpha.row];

    //Check for trivial case of player selecting an empty slot
    if (alpha.piece1 == 0)
    {cout << "No piece selected.\n"; return false;}

    //Start with all possible selections for top player
    if(alpha.piece1 == 1 || alpha.piece1 == -1)
    {
        //Check if move is possible
        alpha.PawnScan(alpha.player, userIn1);
        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }

    if(alpha.piece1 == 2 || alpha.piece1 == -2)
    {
        //Check if move is possible
        alpha.BishopScan(alpha.player, userIn1);
        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }

    if(alpha.piece1 == 3 || alpha.piece1 == -3)
    {
        //Check if move is possible
        alpha.KnightScan(alpha.player, userIn1);
        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }

    if(alpha.piece1 == 4 || alpha.piece1 == -4)
    {
        //Check if move is possible
        alpha.RookScan(alpha.player, userIn1);
        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }

    if(alpha.piece1 == 5 || alpha.piece1 == -5)
    {
        //Check if move is possible, Queen = Bishop + Rook
        alpha.RookScan(alpha.player, userIn1);
        alpha.BishopScan(alpha.player, userIn1);

        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }

    if(alpha.piece1 == 7 || alpha.piece1 == -7)
    {
        //Check if move is possible, Queen = Bishop + Rook
        alpha.KingScan(alpha.player, userIn1);
        if(alpha.moves[alpha.column][alpha.row] == 1)
        {return true;}

        //Else ask user to input again.
        else
        {cout << "Not a valid move.\n"; return false;}
    }


}
