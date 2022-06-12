//
//  Hangman.cpp
//  Hangman
//
//  Created by Cyrus Wong on 12/6/2022.
//

#include "Hangman.hpp"
using namespace std;


Hangman:: Hangman(string fname, unsigned s) {
    
    ifstream file(fname, ios::in);
    if (!file) {
        cout << "File not found: " << fname << endl;
        exit(1);
    }
    
    int word_count;
    file >> word_count;
  
    int k;
    srand(s);
    k = rand() % word_count;
    
    // Get the k-th word in file as secretWord
    string tmp;
    for (int i = 0; i <= k; i++) {
        file >> tmp;
    }
    secretWord = tmp;
    
    wordLength = (int)secretWord.length();
    // Initialize wordToGuess
    for (int i = 0; i < wordLength; i++) {
        wordToGuess += "_";
    }
    
    for (bool &element: triedLetters) {element = false;}
    chances = 6;
}

string Hangman:: getSecretWord() {
//    chances = 0;
    if (secretWord == wordToGuess || chances < 0) {return secretWord;}
    else {return "";}
}

void Hangman::printGame() {

    // Hangman diagram
    switch (chances) {
        case 6:
            cout << "+--+-" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 5:
            cout << "+--+-" << endl;
            cout << "|  O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 4:
            cout << "+--+-" << endl;
            cout << "|  O" << endl;
            cout << "|  |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 3:
            cout << "+--+-" << endl;
            cout << "| \\O" << endl;
            cout << "|  |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 2:
            cout << "+--+-" << endl;
            cout << "| \\O/" << endl;
            cout << "|  |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 1:
            cout << "+--+-" << endl;
            cout << "| \\O/" << endl;
            cout << "|  |" << endl;
            cout << "| /" << endl;
            cout << "|" << endl;
            break;
        case 0:
            cout << "+--+-" << endl;
            cout << "| \\O/" << endl;
            cout << "|  |" << endl;
            cout << "| / \\" << endl;
            cout << "|" << endl;
            break;
        default:
            cout << "Unexpected chances: " << chances << endl;
            break;
    }
    
    cout << "Word to guess: " << wordToGuess << endl;
    
    cout << "Failed letters: ";
    for (int i = 0; i < 26; i++)
        // Letter is tried and not found in secretWord
        if (triedLetters[i] == true && secretWord.find(i + 'a') == string::npos)
            printf("%c ", i + 'a');
 
    cout << endl;
    
    cout << "Chances left: " << chances << endl;
}

int Hangman:: guessLetter(char ch) {
    if (triedLetters[ch-'a'])
        return 2;
    
    bool notUpdated = true;
    triedLetters[ch-'a'] = true;
    for (int i = 0; i < wordLength; i++) {
        if (secretWord.at(i) == ch && wordToGuess.at(i) == '_') {
            wordToGuess.at(i) = ch;
            notUpdated = false;
        }
    }
    
    if (notUpdated) chances--;
    
    if (chances < 0) {
        return 0;
    } else if (wordToGuess == secretWord) {
        return 1;
    } else {
        return 3;
    }
}
