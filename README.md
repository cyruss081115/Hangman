# Hangman
___
### About Hangman
This is a Hangman game implemented in C++. In a Hangman game, there will be a secret word which the player tries to guess it. When the guess is wrong, one stroke on the diagram of Hangman is drawn. If the guess is correct, no stroke will be drawn and all occurance of that letter will be unveiled. Player will have 6 chances for guessing the word. When 6 chances are used up, the player loses. If player unveils all letters, the player wins.

### How to run game
In the project directory, execute the following command in terminal
>make
>./play

### Sample Run
>Use default dictionary set? [y/n] y
>Enter seed: 6
>+--+-
>|
>|
>|
>Word to guess: __________
>Failed letters: 
>Chances left: 6
>Guess a letter: 1
>It must be a letter. Enter again!
>Guess a letter: 3
>It must be a letter. Enter again!
>Guess a letter: g
>+--+-
>|  O
>|
>|
>|
>Word to guess: __________
>Failed letters: g 
>Chances left: 5
>Guess a letter: a
>+--+-
>|  O
>|
>|
>|
>Word to guess: _______a__
>Failed letters: g 
>Chances left: 5
>Guess a letter: d
>+--+-
>|  O
>|
>|
>|
>Word to guess: _____d_a__
>Failed letters: g 
>Chances left: 5
>Guess a letter: c
>+--+-
>|  O
>|  |
>|
>|
>Word to guess: _____d_a__
>Failed letters: c g 
>Chances left: 4
>Guess a letter: s
>+--+-
>|  O
>|  |
>|
>|
>Word to guess: s____d_a__
>Failed letters: c g 
>Chances left: 4
>Guess a letter: t
>+--+-
>|  O
>|  |
>|
>|
>Word to guess: s____dta__
>Failed letters: c g 
>Chances left: 4
>Guess a letter: w
>+--+-
>| \O
>|  |
>|
>|
>Word to guess: s____dta__
>Failed letters: c g w 
>Chances left: 3
>Guess a letter: k
>+--+-
>| \O/
>|  |
>|
>|
>Word to guess: s____dta__
>Failed letters: c g k w 
>Chances left: 2
>Guess a letter: e
>+--+-
>| \O/
>|  |
>|
>|
>Word to guess: s__e_dta__
>Failed letters: c g k w 
>Chances left: 2
>Guess a letter: n
>+--+-
>| \O/
>|  |
>| /
>|
>Word to guess: s__e_dta__
>Failed letters: c g k n w 
>Chances left: 1
>Guess a letter: i
>+--+-
>| \O/
>|  |
>| /
>|
>Word to guess: s_ie_dtai_
>Failed letters: c g k n w 
>Chances left: 1
>Guess a letter: l
>+--+-
>| \O/
>|  |
>| /
>|
>Word to guess: s_ieldtail
>Failed letters: c g k n w 
>Chances left: 1
>Guess a letter: h
>Bingo! Secret word is: shieldtail

Reference: CUHK CSCI1520, Spring 2021/22 Asm6 