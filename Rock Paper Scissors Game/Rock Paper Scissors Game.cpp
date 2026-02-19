// Rock Paper Scissors Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

// rock(0) paper(1) scissors(2)

int generateChoice() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(0, 2);
    return dist(gen);
}

bool checkWin(string input,int compChoice) {
    if ((input == "rock" || input == "r") && compChoice == 2) {
        return true;
    }
    else if ((input == "paper" || input == "p") && compChoice == 0) {
        return true;
    }
    else if ((input == "scissors" || input == "s") && compChoice == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    string input; int score = 0; int playTime = 0;

    string options[3] = {"rock","paper","scissors"};

    cout << "--- WELCOME TO ROCK PAPER SCISSORS GAME!! ---\n";
    cout << "\nType to start or type /help for help...\n";
    //cin >> input;
    //cout << "\nYou typed " << input << endl;
    do{
        cout << "\nYour turn...\n";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        //cout << "You typed " << input << endl;

        if (input == "/help" || input == "/h") {
            cout << "\nYou are in help section\n";
            continue;
        }
        else if (input == "/score" || input == "/s") {
            cout << "\n- Score: \t" << score << endl;
            cout << "- Round(s): \t" << playTime << endl;
        }
        else if (input == "/exit" || input == "/e") {
            cout << "- EXITING...\n";
            break;
        }
        else if (input == "rock" || input == "r" || input == "paper" || input == "p" || input == "scissors" || input == "s"){
            int compChoice = generateChoice();
            bool win = checkWin(input, compChoice);

            cout << "Computer Choose: " << options[compChoice] << endl;

            if (win) {
                score++;
                playTime++;
                cout << "- You WIN!!\n";
            }
            else {
                playTime++;
                cout << "- You Loose!!\n";
            }
        }
        else
        {
            cout << "- Invalid Input...\n";
        }
    }while (input != "exit" || input != "e");
    return 0;
}