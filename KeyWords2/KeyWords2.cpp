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
	//Variables
	int simulationsFailed = 0;

	// Display Title of program to user
	cout << "Welcome to the Code Breaker Training Simulation Program: Keywords II\n";

	// Ask the recruit to login using thier name
	cout << "Please enter in your name: ";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name = "";
	cin >> name;
	cout << endl;

	// Display an overview of what Keywords II is to the recruit 
	cout << "Hello " << name << ", Keywords II is a training simulation that tests your ability to guess secret code words.\n";
	cout << "You will be given multiple guesses to guess the letters in the hidden code words. If you guess them all, you win.\n" << endl;

	// Display an directions to the recruit on how to use Keywords
	cout << "Type in a letter to guess. Correct guesses will fill in the blanks, and incorrect guesses will be displayed above.\n" << endl;

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("DOUBLEOSEVEN");
	words.push_back("BOND");
	words.push_back("AGENT");
	words.push_back("FEMMEFATALE");
	words.push_back("COMPROMISED");
	words.push_back("ESPIONAGE");
	words.push_back("SPY");
	words.push_back("DETECTIVE");
	words.push_back("CRIME");
	words.push_back("DEFECTOR");

	// Create an int var to count the number of simulations being run starting at 1
	int simulationNumber = 1;
	
	// Display the simulation # is staring to the recruit. 
	bool tryAgain = false;	//Do they want to try again
	do
	{

		cout << "----------------------------------------------------------------------------------------------------\n" << endl;
		cout << "Starting Simulation #" << simulationNumber << ".\n" << endl;
		bool failed = false;

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		for (int i = 0; i < 3; ++i)
		{

			if (!failed)	//If they haven't failed
			{

				cout << "\n\nWord #" << i + 1 << ":\n";

				srand(static_cast<unsigned int>(time(0)));	//Seed the random number generator
				random_shuffle(words.begin(), words.end());

				const string THE_WORD = words[0];		//Word to guess
				const int MAX_WRONG = 8;				//Max number of wrong guesses
				int wrong = 0;							//Number of wrong guesses
				string soFar(THE_WORD.size(), '-');		//Word guessed so far
				string used = "";						//Letters already used

				// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
				while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
				{
					//Tell recruit how many incorrect guesses he or she has left
					cout << "You have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n\n";
					//Show recruit the letters he or she has guessed
					cout << "You've used the following letters: " << used << endl;
					//Show player how much of the secret word he or she has guessed
					cout << "\nThe word is: " << soFar << endl;
					//Get recruit's next guess
					char guess;	//The users guess
					cout << "\nEnter your guess: ";
					cin >> guess;
					guess = toupper(guess);	//Make uppercase since secret word is in uppercase

				//While recruit has entered a letter that he or she has already guessed
					while (used.find(guess) != string::npos)
					{
						cout << "\nYou've already guessed " << guess << endl;
						//Get recruit ’s guess
						cout << "\nEnter your guess: ";	//Ask again
						cin >> guess;
						guess = toupper(guess);
					}

					//Add the new guess to the group of used letters
					used += guess;

					//If the guess is in the secret word
					if (THE_WORD.find(guess) != string::npos)
					{

						//Tell the recruit the guess is correct
						cout << "\nThat's right! " << guess << " is in the word.\n\n\n";

						//Update the word guessed so far with the new letter
						for (int i = 0; i < THE_WORD.length(); ++i)
						{
							if (THE_WORD[i] == guess)
							{
								soFar[i] = guess;
							}
						}
					}

					//Otherwise
					else
					{

						//Tell the recruit the guess is incorrect
						cout << "\nSorry, " << guess << " isn't in the word.\n\n\n";

						//Increment the number of incorrect guesses the recruit has made
						++wrong;
					}
				}
				//If the recruit has made too many incorrect guesses
				if (wrong == MAX_WRONG)
				{

					//Tell the recruit that he or she has failed the Keywords II course.
					cout << "You have failed Simulation #" << simulationNumber << " of the Keywords II program.";
					++simulationsFailed;
					failed = true;
				}

				// Otherwise
				else
				{

					//Congratulate the recruit on guessing the secret words
					cout << "You guessed the correct word.";
					cout << "\nThe word was " << THE_WORD << "\n" << endl;
				}
			}
		}

		// Ask the recruit if they would like to run the simulation again
		string answer;
		tryAgain = false;
		cout << "would you like to try again?\n";
		cout << "(Y): Yes	(N): No\n";
		cout << "Answer: ";
		cin >> answer;

		// If the recruit wants to run the simulation again
		if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes")
		{

			//Increment the number of simiulations ran counter
			++simulationNumber;

			//Move program execution back up to // Display the simulation # is staring to the recruit. 
			tryAgain = true;
		}
	} while (tryAgain);

	// Otherwise 
	cout << "You have completed the Keywords II training simulation.\n";

	//Display End of Simulations to the recruit
	cout << "You have failed " << simulationsFailed << " out of " << simulationNumber << " simulations.\n";
	//Pause the Simulation with press any key to continue
	return 0;

}
