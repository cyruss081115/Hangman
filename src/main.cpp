//
//  main.cpp
//  Hangman
//
//  Created by Cyrus Wong on 12/6/2022.
//

#include <iostream>
#include "Hangman.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string fname; int seed; char useDefault; string buffer;

    while (true) {
        cout << "Use default dictionary set? [y/n] ";
        cin >> useDefault;
        if (useDefault == 'y' || useDefault == 'n') {
            break;
        } 
        cin >> buffer;
    }

    if (useDefault == 'y') {
        fname = "words.txt";
    } else {
        cout << "Enter dictionary file name: ";
        cin >> fname;
    }

    while (true) {
        cout << "Enter seed: ";
        cin >> seed;
        if (seed >= 0) break;
        cout << "Please enter a non-negative integer." << endl;
    }
    Hangman hm(fname, (unsigned)seed);
    
    while (true) {
        char guess;
        string guessBuffer;
        int guessState;
        hm.printGame();
        
        // Input validation
        while (true) {
            cout << "Guess a letter: ";
            cin >> guessBuffer;
            guess = guessBuffer[0];

            // If guess is a letter
            if ((guess <= 'z' && guess >= 'a') || (guess <= 'Z' && guess >= 'A')) {
                // Convert to lower case letter
                guess = (guess <= 'Z' && guess >= 'A') ? guess - 'A' + 'a': guess;
                
                guessState = hm.guessLetter(guess);
                if (guessState == 2) {
                    cout << "Letter " << guess << " already tried. Enter again!" << endl;
                    continue;
                } else {break;}
                
            } else {
                cout << "It must be a letter. Enter again!" << endl;
            }
        }
        
        if (guessState == 0) {
            hm.printGame();
            cout << "You lose!" << " Secret word is: " << hm.getSecretWord() << endl;
            break;
        } else if (guessState == 1) {
            hm.printGame();
            cout << "Bingo!" << " Secret word is: " << hm.getSecretWord() << endl;
            break;
        }
        
    }
    return 0;
}
