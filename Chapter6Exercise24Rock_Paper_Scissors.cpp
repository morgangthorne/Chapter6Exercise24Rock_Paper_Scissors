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
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//Function Prototype
int GetRandomNumber();
void Show_Menu();
void Display_Sessions();
void Delete_Sessions();
bool Rock_Paper_Scissor(int Number);

int main()
{
    string Do_Again;
    int Menu_Choice;
    int wins = 0;
    bool running = true;

    while (running) {
        Show_Menu();
        cin >> Menu_Choice;
        cin.ignore();

        switch (Menu_Choice) {
        case 1: {
            Display_Sessions();
            break;
        }

        case 2: {
            string Player_Name;
            cout << "Enter your name: ";

            getline(cin, Player_Name);

            do {
                int Number = GetRandomNumber();
                bool Did_Player_Win = Rock_Paper_Scissor(Number);
                if (Did_Player_Win) {
                    wins++;
                }

                cout << "You have " << wins << " win(s)!\n";
                cout << "Would you like to play again? Yes/No: ";
                cin >> Do_Again;
            } while (Do_Again == "Yes" || Do_Again == "yes");

            ofstream outFile("RockPaperScissors.txt", ios::app);
            if (outFile.is_open()) {
                outFile << Player_Name << " won " << wins << " time(s)!\n";
                outFile.close();
                cout << "Session saved!\n";
            }
            else {
                cout << "Error: Could not save session.\n";
            }

            wins = 0;  // Reset wins for the next player/session
            break;
        }
        case 3: {
            Delete_Sessions();
            break;
        }

        case 4: {
            running = false;
            cout << "Thank you for using the program." << endl;
            break;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;

}


//Creates a random number from 1-3 to simulate rock, paper, scissors
int GetRandomNumber() {
    random_device x;
    uniform_int_distribution<int> randomInt(1, 3);

    int Number = randomInt(x);

    return Number;
}

//Simply displays menu
void Show_Menu() {
    cout << "\n-------- MAIN MENU --------" << endl;
    cout << "1. Display Existing Sessions" << endl;
    cout << "2. Play a New Session" << endl;
    cout << "3. Delete Previous Sessions" << endl;
    cout << "4. Exit the Program" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter your choice: ";
}










//Uses do-while loop to run answer validation. Also assigns a string to numeric value of user's and computer choice
//Displays whether the user won or lost and displays both users and computers choices
bool Rock_Paper_Scissor(int Computer_Choice) {
    int User_Choice;

    int Wins = 0;

    string Player_Choice;

    string Computer_Choice_String;

    
    do {

        cout << "Choose Rock (1), Paper (2), or Scissors(3): ";

        cin >> User_Choice;

        

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

        //Answer Validation
        if (User_Choice == Computer_Choice) {
            cout << "Draw!\n";
            return false;
        }
        else if ((User_Choice == 1 && Computer_Choice == 3) || (User_Choice == 2 && Computer_Choice == 1) || (User_Choice == 3 && Computer_Choice ==2)) {
            cout << "You won! " << Player_Choice << " beats " << Computer_Choice_String << "!\n";
            
            return true;
        }
        else {
            cout << "You lost! " << Computer_Choice_String << " beats " << Player_Choice << "!\n";
            return false;
        }
        
  

        
}

//Displays all previous sessions, if no sessions found will display no sessions found
void Display_Sessions() {
    ifstream inFile("RockPaperScissors.txt");

    if (!inFile) {
        cout << "No sessions found.\n";
        return;
    }

    string line;
    cout << "\n--- Previous Sessions ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

//Deletes all previous sessions
void Delete_Sessions() {
    ofstream outFile("sessions.txt", ios::trunc);
    if (outFile.is_open()) {
        outFile.close();
        cout << "All sessions have been deleted.\n";
    }
    else {
        cout << "Error: Could not delete sessions.\n";
    }
}