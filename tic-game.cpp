#include <bits/stdc++.h>
using namespace std;
void board(int *square)
{
    cout << endl;
    cout << "\t<-----Tic Toc Toe Game----->\t\t" << endl;
    cout << endl
         << endl;
    cout << "\tPlayer 1->(1)\t Player 0->(0)\t" << endl;
    cout << endl
         << endl;
    cout << "\t\t     |     |   " << endl;
    cout << "\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "\t\t-----|-----|---" << endl;
    cout << "\t\t     |     |    " << endl;
    cout << "\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "\t\t-----|-----|---" << endl;
    cout << "\t\t     |     |    " << endl;
    cout << "\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
}
bool is_Win(int *square)
{
    if (square[1] == square[2] && square[2] == square[3])
        return true;
    else if (square[4] == square[5] && square[5] == square[6])
        return true;
    else if (square[7] == square[8] && square[8] == square[9])
        return true;
    else if (square[1] == square[4] && square[4] == square[7])
        return true;
    else if (square[2] == square[5] && square[5] == square[8])
        return true;
    else if (square[3] == square[6] && square[6] == square[9])
        return true;
    else if (square[1] == square[5] && square[5] == square[9])
        return true;
    else if (square[3] == square[5] && square[5] == square[7])
        return true;
    else if (square[1] != 1 && square[2] != 2 && square[3] != 3 &&square[4] != 4 && square[5] != 5 && square[6] != 6 && square[7] != 7 && square[8] != 8 &square[9] != 9)
               return false;
        else 
         return false;
}
int main()
{
    int player = 1, j, choice, value;
    int square[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool Win;
    do
    {
        //fill the board initial values
        board(square);
        //select the player
        player = (player % 2) ? 1 : 0;
        cout << endl;
        //fill the turn to your board
        cout << "Player: " << player << " fill your cell choice > ";
        cin >> choice;
        //select the player's value whether it is 0 or 1
        value = (player == 1) ? 1 : 0;
        //iterate over all cells which one is matched
        for (j = 1; j <= 9; j++)
        {
            if (choice == j && square[j] == j)
            {
                square[j] = value;
                break;
            }
        }
        if (j == 10)
        {
            cout << "Please Enter correct place number again!! ";
            player--;
            cin.ignore();
            cin.get();
        }
        Win = is_Win(square);
        player++;
    } while(Win==false);
    board(square);
    if (Win == true)
    {
        cout << endl << "\t\tPlayer: " << --player << " won the game!! ";
    }
    else
    {
        cout << "\t\tGame Draws!!";
        cin.ignore();
        cin.get();
    }
    return 0;
}