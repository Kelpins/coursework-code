#include <iostream> // for cin and cout
#include <cmath> // for pow
#include <algorithm> // for max
#include <limits> // for numeric_limits to guarantee fully clearing cin
using namespace std;

// validates each user-inputted integer for correct data type and range
int getValidInput()
{
    int value; // create empty variable to hold the user's input
    cout << "Enter an integer between 0 and 15: "; // prompt the user for an integer
    while (true) // loop until the user enters a valid integer
    {
        cin >> value; // read the user's input
        if (cin.fail()) // fails when the entry is not an integer
        {
            cin.clear(); // clears the stream's error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer of invalid input
            cout << "Incorrect data type! Please try again: "; // reprompt the user and restart loop
        }
        else if (value < 0 || value > 15) // fails when the entry is out of range
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer of invalid input
            cout << "Value is out of range! Try again: "; // reprompt the user and restart loop
        }
        else // passes both checks and returns validated integer
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer for next input
            return value; // returns the validated integer
        }
    }
}

// main function to run the program
int main()
{
    char again = 'y'; // initialize repeat program variable to 'y' to start the loop
    while (again == 'y' || again == 'Y') // loop until the user doesn't want to repeat
    {
        int first  = getValidInput(); // get and validate the first integer
        int second = getValidInput(); // get and validate the second integer

        cout << endl;
        cout << "Decimal Values:     " << dec << first << ", " << second << endl;
        cout << "Hexadecimal Values: " << hex << first << ", " << second << endl;
        cout << "Octal Values:       " << oct << first << ", " << second << endl;
        cout << dec;
        cout << endl;
        // raise first integer to the power of second
        cout << first << " raised to the power of " << second << " is "
             << pow(first, second) << endl;
        // maximum of the two integers
        cout << "The maximum of " << first << " and " << second << " is " << max(first, second) << endl;
        // prompt the user to repeat the program
        cout << endl << "Run the program again? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer for next input
        cout << endl;
    }

    cout << "Program terminated." << endl;
    return 0;
}
