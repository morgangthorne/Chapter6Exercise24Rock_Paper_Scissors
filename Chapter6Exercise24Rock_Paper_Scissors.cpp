/* 
Filename: Chapter6Exercise24Rock_Paper_Scissors.cpp
Programmer: Morgan Thorne
Date: April 2025
Requirements:
-Write a program that produces a random number between 1-3 to take place as rock, paper, and scissors
-Allow user to enter their choice
-display computers choice (random number)
-display whether user won or lost based off user and computer answer

*/

#include <iostream>
#include <random>

using namespace std;

//Function Prototype
int GetRandomNumber();
bool Get_Repeat_Info();
void Rock_Paper_Scissor(int Number);


int main()
{

    bool User_Repeat;

    do {

        int Number = GetRandomNumber();

        Rock_Paper_Scissor(Number);

        User_Repeat = Get_Repeat_Info();


    }

    while (User_Repeat); {
        cout << "Thank you for using the program";
        return 0;
    }

}


//Creates a random number from 1-3 to simulate rock, paper, scissors
int GetRandomNumber() {
    random_device x;
    uniform_int_distribution<int> randomInt(1, 3);

    int Number = randomInt(x);

    return Number;
}

//Allows user to choose whether they want to repeat program or end it
bool Get_Repeat_Info() {
    char choice;
    cout << "Play another game? Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

//Uses do-while loop to run answer validation. Also assigns a string to numeric value of user's and computer choice
//Displays whether the user won or lost and displays both users and computers choices
void Rock_Paper_Scissor(int Computer_Choice) {
    int User_Choice;

    string Player_Choice;

    string Computer_Choice_String;

    
    do {

        cout << "Choose Rock (1), Paper (2), or Scissors(3): ";

        cin >> User_Choice;

        cout << "--------------------------------------------\n";

        if (User_Choice < 1 || User_Choice > 3) {
            cout << "Enter the numbers 1 - 3: ";
            
        }
    } while (User_Choice < 1 || User_Choice > 3);
        
        //Gives user's and computer's numeric values their respective strings for their choice
        string Choice[] = { "Rock", "Paper", "Scissors" };
        Player_Choice = Choice[User_Choice - 1];
        Computer_Choice_String = Choice[Computer_Choice - 1];

        cout << "You chose: " << Player_Choice << endl;
        cout << "Computer chose: " << Computer_Choice_String << endl;
        cout << "--------------------------------------------\n";

        //Answer Validation
        if (User_Choice == Computer_Choice) {
            cout << "Draw!\n";
        }
        else if ((User_Choice == 1 && Computer_Choice == 3) || (User_Choice == 2 && Computer_Choice == 1) || (User_Choice == 3 && Computer_Choice ==2)) {
            cout << "You won! " << Player_Choice << " beats " << Computer_Choice_String << "!\n";
        }
        else {
            cout << "You lost! " << Computer_Choice_String << " beats " << Player_Choice << "!\n";
        }
    

}