/*A simple C++ Project of the game TicTacToe.
It also includes the explanation of the code in the form of comments.

Coded by Siddique Ahmad Ryan...
https://github.com/iryansa
https://github.com/iamryan2923
https://www.linkedin.com/in/siddique-ahmad-ryan-909a4a247/
https://twitter.com/i_ryan_a
*/




//Including the input-output streaming library
#include <iostream>
//including the string library as string datatype has been used in the program
#include <string>
//using the standard namespace
using namespace std;

//The Board on which game is played
char game_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
//The player i.e. X or O (the first player is X)
char player = 'X';

//Function to draw the Game Board
void draw_board()
{
    //system("cls") clears all the data previously printed on the screen
    system("cls");
    //Welcome Screen
    cout << "______________________\nWelcome to TicTacToe!\n______________________\n";
    //Drawing the skeleton game board
    cout<<"     |     |     \n";
    cout<<"  "<<game_board[0][0]<<"  |  "<<game_board[0][1]<<"  |  "<<game_board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<game_board[1][0]<<"  |  "<<game_board[1][1]<<"  |  "<<game_board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<game_board[2][0]<<"  |  "<<game_board[2][1]<<"  |  "<<game_board[2][2]<<" \n";
    cout<<"     |     |     \n";
}

//Function to take input from the user (the function takes names of the players as parameters)
void user_input(string name1, string name2)
{
    //The user input
    int in;
//This "input:" is used here to later perform the goto operation
input:
    //X is for first player and O is for second player
    if (player == 'X')
        cout << "It\'s " << name1 << "\'s turn.\n";
    else if (player == 'O')
        cout << "It\'s " << name2 << "\'s turn.\n";

    cout << "Enter a number, where you want to plant your input: ";
    cin >> in;

    //Switch to fill the user-desired location (If the user input previously filled location, then the user will have to input his choice again)
    switch (in)
    {
    case 1:
        if (game_board[0][0] != 'X' && game_board[0][0] != 'O')
            game_board[0][0] = player;
        else
            goto input;
        break;
    case 2:
        if (game_board[0][1] != 'X' && game_board[0][1] != 'O')
            game_board[0][1] = player;
        else
            goto input;
        break;
    case 3:
        if (game_board[0][2] != 'X' && game_board[0][2] != 'O')
            game_board[0][2] = player;
        else
            goto input;
        break;
    case 4:
        if (game_board[1][0] != 'X' && game_board[1][0] != 'O')
            game_board[1][0] = player;
        else
            goto input;
        break;
    case 5:
        if (game_board[1][1] != 'X' && game_board[1][1] != 'O')
            game_board[1][1] = player;
        else
            goto input;
        break;
    case 6:
        if (game_board[1][2] != 'X' && game_board[1][2] != 'O')
            game_board[1][2] = player;
        else
            goto input;
        break;
    case 7:
        if (game_board[2][0] != 'X' && game_board[2][0] != 'O')
            game_board[2][0] = player;
        else
            goto input;
        break;
    case 8:
        if (game_board[2][1] != 'X' && game_board[2][1] != 'O')
            game_board[2][1] = player;
        else
            goto input;
        break;
    case 9:
        if (game_board[2][2] != 'X' && game_board[2][2] != 'O')
            game_board[2][2] = player;
        else
            goto input;
        break;
    //If the user inputs something out of the range
    default:
        cout << "Enter a valid number!\n";
        goto input;
    }
}

//Function to return the winning player (It checks if a user has won and if the match is drawn)
char win()
{
    //Rows
    if (game_board[0][0] == player && game_board[0][1] == player && game_board[0][2] == player)
        return player;
    if (game_board[1][0] == player && game_board[1][1] == player && game_board[1][2] == player)
        return player;
    if (game_board[2][0] == player && game_board[2][1] == player && game_board[2][2] == player)
        return player;
    //Columns
    if (game_board[0][0] == player && game_board[1][0] == player && game_board[2][0] == player)
        return player;
    if (game_board[0][1] == player && game_board[1][1] == player && game_board[2][1] == player)
        return player;
    if (game_board[0][2] == player && game_board[1][2] == player && game_board[2][2] == player)
        return player;
    //Diagonals
    if (game_board[0][0] == player && game_board[1][1] == player && game_board[2][2] == player)
        return player;
    if (game_board[2][0] == player && game_board[1][1] == player && game_board[0][2] == player)
        return player;

    //If any of the above possibility is not met, then it will return N, instead of X or Y
    return 'N';
}

//Main Driver Function
int main()
{

        //To clear the screen
        system("cls");
        //To store the names of the players
        string name1, name2;
        cout << "Welcome to TicTacToe!\n";
        cout << "Enter name of the first player (X): ";
        cin>>name1;
        cout << "Enter name of the second player (O): ";
        cin>>name2;
        //Calling the function to draw the main skeleton board
        draw_board();
        while ("true")
        {
            // Calling the function to take user input (with the user names as parameters)
            user_input(name1, name2);
            //Again calling the draw_board function to replace a location number according to the user input with the player's character
            draw_board();

            //If First Player wins
            if (win() == 'X')
            {
                cout << name1 << " wins!\n";
                break;
            }
            //If second player wins
            else if (win() == 'O')
            {
                cout << name2 << " wins!\n";
                break;
            }
            //If the match has been drawn (it will check if the win function returns N and the game board has completely been occupied)
            else if (win() == 'N' && game_board[0][0] != '1' && game_board[0][1] != '2' && game_board[0][2] != '3' && game_board[1][0] != '4' && game_board[1][1] != '5' && game_board[1][2] != '6' && game_board[2][0] != '7' && game_board[2][1] != '8' && game_board[2][2] != '9')
            {
                cout << "Match: Draw";
                break;
            }
            //For changing the turns between the players
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }


    //If the game ends, the game will not be shut down immediately, but it will ask the user to enter any key to close the game
    system("pause");

    return 0;
}
