//************ TASK--1 *****************//

/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
    srand(time(nullptr));
    int target_number = rand() % 100 + 1;
    int guess = 0;
    int attempts =0;

    cout<<"Welcome to the Number Guessing Game"<<endl;

    while(true)
    {
        cout << "Guess the number (between 1 and 100)"<<endl;
        cin >> guess;
        attempts++;

        if (guess == target_number)
        {
            cout << "Congratulations! You guessed the number\n " << target_number << " correctly in " << attempts << " attempts." << endl;
            break;
        }
        else if(guess < target_number)
        {
            cout << "Too low. Try again" << endl;
        }
        else
        {
            cout << "Too high. Try again." << endl;
        }
    }
    return 0;
}

