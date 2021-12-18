/////////////////////////////////////////////////////////
//
// Wes O & Jacob B
// CS-171-2
// 12/1
// monopoly game
//
/////////////////////////////////////////////////////////

#include <iostream> // print out to the screen (cout)
using namespace std;

class Square
{ //class for each position on the board

public: //data to be stored in squares
    char playerPiece = '*';
    char playerPiece2 = '$';
    char defaultIcon = '0'; //show this if there is no player in the square
    int rent = 5; //non essential
    int buy = 100; //non essential
    int rentOnceBought = 50; //non essential

    Square()
    { //constructor
    }
};

class Player
{ //class for players

public: //stores how much money players have and where they are on the board
    int money;
    int boardPosition;

    Player()
    { //constructor
        money = 500; //players start in the first square, with $500
        boardPosition = 0;
    }

    int getMoney() //returns how much money player has
    { 
        return money;
    }

    void addMoney(int dollars) //add money (Non essential)
    { 
        money += dollars;
    }

    void subtractMoney(int dollars) //subtract money (Non essential)
    {
        money -= dollars;
    }

    int position(int roll) //move position
    {
        boardPosition += roll;
        if (boardPosition >= 16) //reset position from 0 once player passes square 16.
        {
            boardPosition = 0;
        }
        return boardPosition; //get back the updated position
    }
};
int main()
{

    string player1; //stores player names
    string player2;

    cout << "Welcome to Monoploy, enter name player 1: "; //players enter names
    cin >> player1;
    cout << endl;
    cout << "Enter name player 2: ";
    cin >> player2;
    cout << endl;
    cout << player1 << " is player 1, represented by a * " << endl; //"*" and "$" symbols represent players
    cout << player2 << " is player 2, represented by a $ " << endl;


    Player P1; //create two players from the class
    Player P2;

    Square S1; //create square object for each place on the board
    Square S2;
    Square S3;
    Square S4;
    Square S5;
    Square S6;
    Square S7;
    Square S8;
    Square S9;
    Square S10;
    Square S11;
    Square S12;
    Square S13;
    Square S14;
    Square S15;
    Square S16;

    Square array[16] = {S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15}; //array filled with "squares" on the board
    int x_axis[16] = {4, 3, 2, 1, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4};                     //array for x axis values
    int y_axis[16] = {0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 3, 2, 1};                     //array for y axis values

    char display[5][5] = {'*'}; //creates 2d array that's values will be updated later

    int userInput = 0; 
    int lastPosition1 = 0; //variable to store last position for player one
    int lastPosition2 = 0; //for player 2

    display[x_axis[0]][y_axis[0]] = array[0].playerPiece; //player starts on square one

    while (userInput < 6)
    {
        int player1Roll = rand() % 5 + 1;                                //variable to store the random roll
        cout << "Player 1 rolled a " << player1Roll << ". Enter roll: "; //prompt the user to enter what they rolled
        cin >> userInput;
        userInput = player1Roll; //update value

        int userInput2; //repeat for player 2
        int player2Roll;

        player2Roll = rand() % 5 + 1; //repeat for player 2
        cout << "Player 2 rolled a " << player2Roll << ". Enter roll: ";
        cin >> userInput2;
        cout << endl;
        userInput2 = player2Roll;

        int currentPosition1 = P1.position(player1Roll); //create a new variable for the current position of the player using the number they rolled
        int currentPosition2 = P2.position(player2Roll);

        for (int i = 0; i < 16; i++) //loop to manipulate the board
        {
            display[x_axis[i]][y_axis[i]] = array[i].defaultIcon;
            if (currentPosition1 == i) //if current position is i on the board
            {

                display[x_axis[i]][y_axis[i]] = array[i].playerPiece;

                if (lastPosition1 != currentPosition1) //change last position back to "empty" square after player has moved again
                {
                    display[x_axis[lastPosition1]][y_axis[lastPosition1]] = array[i].defaultIcon; //use last postition to index
                }

                lastPosition1 = currentPosition1;
            }
            if (P1.money <= 0) //checks if player 1 is bankrupt
            {
                cout << player1 << " is bankrupt, " << player2 << " wins! ";
                break;
            }

            //repeat everything for player 2
            if (currentPosition2 == i)
            {
                display[x_axis[i]][y_axis[i]] = array[i].playerPiece2;
            }

            if (lastPosition2 != currentPosition2)
            {
                display[x_axis[lastPosition2]][y_axis[lastPosition2]] = array[i].defaultIcon; //use last postition to index
            }

            lastPosition2 = currentPosition2;
        }
        if (P2.money <= 0) //checks if player 2 is bankrupt
        {
            cout << player2 << " is bankrupt, " << player1 << " wins! ";
            break;
        }

        for (int i = 0; i < 5; i++) //loop to print out the board
        {
            for (int j = 0; j < 5; j++)
            {
                cout << display[i][j] << " ";
            }
            cout << endl;
        }
    }
} //end main function


