#include <iostream> // for cin and cout
#include <string> // for the prompt passed to getValidInput
#include <bitset> // for printing a value in binary
#include <limits> // for numeric_limits to guarantee fully clearing cin
using namespace std;

// validates each user-inputted integer for correct data type and range
int getValidInput(string prompt, int low, int high)
{
    int value; // create empty variable to hold the user's input
    cout << prompt; // prompt the user for an integer
    while (true) // loop until the user enters a valid integer
    {
        cin >> value; // read the user's input
        if (cin.fail()) // fails when the entry is not an integer
        {
            cin.clear(); // clears the stream's error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer of invalid input
            cout << "Incorrect data type!  Please try again: "; // reprompt the user and restart loop
        }
        else if (value < low || value > high) // fails when the entry is out of range
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

// prints a decimal value in binary
void printBinary(int value)
{
    cout << bitset<8>(value); // 8 bits covers the full 0 to 255 range
}

// returns whether a bit at a given index is 0 or 1
int getBitState(int dataValue, int index)
{
    return (dataValue >> index) & 1; // shift wanted bit to end and ignore the rest
}

// sets or clears a bit at a given index and returns the modified value
int setBitValue(int dataValue, int index, int state)
{
    if (state == 1) // sets the bit to 1
    {
        dataValue |= (1 << index); // OR with a 1 in that position
    }
    else // clears the bit to 0
    {
        dataValue &= ~(1 << index); // AND with a 0 in that position
    }

    return dataValue; // returns the modified value
}

// main function to run the program
int main()
{
    char again = 'y'; // initialize repeat program variable to 'y' to start the loop
    while (again == 'y' || again == 'Y') // loop until the user doesn't want to repeat
    {
        int number = getValidInput("Enter a decimal number from 0 to 255: ", 0, 255); // get and validate the number

        cout << number << " in binary is "; // label the binary output
        printBinary(number); // print the number in binary
        cout << endl;
        // read the state of a bit the user chooses
        int index = getValidInput("Enter a bit number from 0 to 7: ", 0, 7); // get and validate the bit to read
        cout << "Bit " << index << " is " << getBitState(number, index) << endl; // print that bit's state
        // set or clear a bit the user chooses
        int target = getValidInput("Enter a bit number from 0 to 7 to modify: ", 0, 7); // get and validate the bit to change
        char action; // holds the letter choosing set or clear
        cout << "Enter 's' to set that bit or 'c' to clear it: "; // prompt for set or clear
        cin >> action; // read the user's choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer for next input
        int state = (action == 's' || action == 'S') ? 1 : 0; // 1 sets the bit, 0 clears it
        int modified = setBitValue(number, target, state); // apply the change to the number
        cout << "The modified number " << modified << " in binary is "; // label the modified output
        printBinary(modified); // print the modified number in binary
        cout << endl;
        // prompt the user to repeat the program
        cout << endl << "Run the program again? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empties buffer for next input
        cout << endl;
    }

    cout << "Program terminated." << endl;
    return 0;
}
