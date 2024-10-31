// Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayBoard(int board[][3])
{
    cout << "   1    2    3" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1;
        for (int j = 0; j < 3; j++)
        {
            char playerSymbol = ' ';
            if (board[i][j] == 1)
                playerSymbol = 'X';
            else if (board[i][j] == -1)
                playerSymbol = 'O';
            cout << setw(3) << playerSymbol;
            if (j != 2)
                cout << " |";
        }
        cout << endl;
        if (i != 2)
            cout << " ____|____|____" << endl
                 << "     |    |    " << endl;
    }
    cout << endl;
}

bool isValidMove(int board[][3], int x, int y)
{
    bool isValid;

    if (board[x][y] == 0) isValid = true;
    else isValid = false;

    return isValid;
}

bool getXOMove(int board[][3], int noOfMoves, int &x, int &y)
{

    if (noOfMoves >= 9)
        return false;

    int row, col;
    do
    {
        cin >> row >> col;
        cout << endl;
    } while (!isValidMove(board, row - 1, col - 1));
    x = row - 1;
    y = col - 1;

    return true;
}

void addMove(int board[][3], int x, int y, int player)
{
    board[x][y] = player;
}

int gameStatus(int board[][3], int &noOfMoves)
{
    // Write your code here to check if the game has been in a win status or a draw status
    // Check rows for a win

    // Check columns for a win
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0)
        return board[0][0];
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0)
        return board[1][0];
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0)
        return board[2][0];

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
        return board[0][2];

    // Check for rows
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0)
        return board[0][0];
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0)
        return board[0][1];
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0)
        return board[0][2];

    // Draw
    if (noOfMoves >= 9)
        return 2;

    return 0;
}

int main()
{
    int board[3][3];
    int noOfMoves;

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = 0;

    noOfMoves = 0;

    int player = 1;

    displayBoard(board);
    int done = 0;
    while (done == 0)
    {
        char playerSymbol = (player == 1) ? 'X' : 'O';
        cout << "Player " << playerSymbol << " enter move: ";
        int x, y;

        getXOMove(board, noOfMoves, x, y);

        addMove(board, x, y, player);
        noOfMoves++;
        displayBoard(board);

        done = gameStatus(board, noOfMoves);
        if (done == 1)
        {
            cout << "Player X wins!" << endl;
            return 0;
        }
        else if (done == -1)
        {
            cout << "Player O wins!" << endl;
            return 0;
        }
        else if (done == 2)
        {
            cout << "Draw game!" << endl;
            return 0;
        }

        if (player == 1)
            player = -1;
        else
            player = 1;
    }

    return 0;
}