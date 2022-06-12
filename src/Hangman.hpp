//
//  Hangman.hpp
//  Hangman
//
//  Created by Cyrus Wong on 12/6/2022.
//

#ifndef Hangman_hpp
#define Hangman_hpp

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;


class Hangman {
private:
    // String for storing the secret word for guessing in the game
    string secretWord;

    // A string for storing the current state of the word to guess.
    // Initially, it consists of all underscores ‘_’ of the same length as that of the secret word.
    // Throughout the game, the correctly guessed letters will be gradually unveiled in this string.
    string wordToGuess;
    
    int wordLength;
    // An array of Boolean values for storing whether letters a–z (indices 0–25 respectively) are already guessed by the player.
    // Value true means the letter was guessed; false means otherwise.
    bool triedLetters[26];

    // The number of remaining chances of the player. There are 6 chances initially
    int chances;
public:
    // Constructor that creates the game. The parameter fname denotes the name of a data file
    Hangman(string fname, unsigned s);
    
    string getSecretWord();
    void printGame();
    int guessLetter(char ch);

};
#endif
