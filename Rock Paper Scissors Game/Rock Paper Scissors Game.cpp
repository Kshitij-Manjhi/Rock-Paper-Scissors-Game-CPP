// Rock Paper Scissors Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    string input;
    cout << "--- WELCOME TO ROCK PAPER SCISSORS GAME!! ---\n";
    cout << "\nType to start or type /help for help...\n";
    cin >> input;
    cout << "\nYou typed " << input << endl;
    do{
        cout << "\nYour turn...\n";
        cin >> input;
        cout << "You typed " << input << endl;
    }while (input != "exit");
    return 0;
}