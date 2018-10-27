// KeyWords2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	// Display Title of program to user
	cout << "Welcome to the Code Breaker Training Simulation Program: Keywords II\n";

	// Ask the recruit to login using thier name
	cout << "Please enter in your name: ";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name = "";
	cin >> name;
	cout << endl;

	// Display an overview of what Keywords II is to the recruit 
	cout << "Hello " << name << ", Keywords II is a training simulation the tests your ability to guess secret code words.\n";
	cout << "You will be given multiple guesses to guess the letters in the hidden code words. If you guess them all, you win.\n" << endl;

	// Display an directions to the recruit on how to use Keywords
	cout << "Type in a letter to guess. Correct guesses will fill in the blanks, and incorrect guesses will be displayed above.\n" << endl;

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("DoubleOSeven");
	words.push_back("Bond");
	words.push_back("Agent");
	words.push_back("FemmeFatale");
	words.push_back("Compromised");
	words.push_back("Espionage");
	words.push_back("Spy");
	words.push_back("Detective");
	words.push_back("Crime");
	words.push_back("Defector");

	// Create an int var to count the number of simulations being run starting at 1
	int simulationNumber = 1;
	
	// Display the simulation # is staring to the recruit. 
	cout << "----------------------------------------------------------------------------------------------------\n" << endl;
	cout << "Starting Simulation #" << simulationNumber << ".\n" << endl;

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 

	srand(static_cast<unsigned int>(time(0)));	//Seed the random number generator
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	const int MAX_WRONG = 8;
	int wrong = 0;
	string soFar(THE_WORD.size(), '_');
	string used = "";

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

	//     Tell recruit how many incorrect guesses he or she has left

	//     Show recruit the letters he or she has guessed

	//     Show player how much of the secret word he or she has guessed

	//     Get recruit's next guess

	//     While recruit has entered a letter that he or she has already guessed

	//          Get recruit ’s guess

	//     Add the new guess to the group of used letters

	//     If the guess is in the secret word

	//          Tell the recruit the guess is correct

	//          Update the word guessed so far with the new letter

	//     Otherwise

	//          Tell the recruit the guess is incorrect

	//          Increment the number of incorrect guesses the recruit has made

	// If the recruit has made too many incorrect guesses

	//     Tell the recruit that he or she has failed the Keywords II course.

	// Otherwise

	//     Congratulate the recruit on guessing the secret words

	// Ask the recruit if they would like to run the simulation again

	// If the recruit wants to run the simulation again

	//     Increment the number of simiulations ran counter

	//     Move program execution back up to // Display the simulation # is staring to the recruit. 

	// Otherwise 

	//     Display End of Simulations to the recruit

	//     Pause the Simulation with press any key to continue
}
