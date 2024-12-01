//**********************************************************************
// Author: Raymond Castro
// Date: 1 Dec 2024
//
// Computer Science Coding Assignment 7 - Raymond Castro
//
// This C++ program demonstrates arrays and string manipulations
// (dynamic input) by performing various operations on an array of names
// and allowing the user to specify how many names to enter.
//**********************************************************************

// Header files
#include <iostream>
#include <iomanip>  // Header file used for input and output manipulators
#include <string>
#include <algorithm> // Header file used for algorithms, such as sort
#include <cctype> /* Header file used for functions which classify and
transform individual characters, such as tolower */
#include <set> // Header file that provides access to the set container

using namespace std;

string trim(const string& str) /* Creates a function which trims leading
and trailing spaces from a string */
{
    size_t start = str.find_first_not_of(" t\n\r"); /* Searches for the
    first character in a string that are not whitespace characters */
    size_t end = str.find_last_not_of (" t\n\r"); /* Searches for the
    last character in a string that are not whitespace characters */
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
    /* Returns an empty string if start or end are equal to string::npos,
    or returns the substring from start to end to trim leading or trailing
    whitespace characters */ 
}

void sortNames(string names[], int size) /* Creates a function which sorts
names alphabetically*/
{
    sort(names, names + size); // Sorts an array in ascending order
}

bool searchName(const string names[], int size, const string& target)
// Creates a function which performs a case-insensitive search for a specific names
{
    string lowerTarget = target;
    transform(lowerTarget.begin(), lowerTarget.end(), lowerTarget.begin(), ::tolower);
    /* Converts all characters in lowerTarget to lowercase to avoid discrepancies
    during string comparisons */


    for (int i = 0; i < size; ++i)
    {
        string lowerName = names[i];
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        /* Converts all characters in lowerName to lowercase to avoid discrepancies
        during string comparisons */
        
        if (lowerName == lowerTarget) /* Checks whether lowerName and lowerTarget are
        equal */
        {
            return true;
        }
    }
    return false;
}

string findLongestName(const string names[], int size) /* Creates a function which
searches for the longeest name in a list */
{
    string longest = names[0];
    for (int i = 1; i < size; ++i) // Finds the longest string in the array names[]
    {
        if (names[i].length() > longest.length()) /* Compares the length of each
        string with the current longest string */
        {
            longest = names[i];
        }
    }
    return longest;
}

int countVowels(const string names[], int size) /* Creates a function which counts
the total number of vowels in all names */
{
    int vowelCount = 0;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; /* Creates a set of vowels and
    initializes it with the respective characters, storing the elements in sorted
    order */

    for (int i = 0; i < size; ++i) /* Counts the total number of vowels in a list,
    iterating over each string */
    {
        for (char ch : names[i]) // Iterates over each character
        {
            ch = tolower(ch); // Converts each character to lowercase
            if (vowels.find(ch) != vowels.end()) /* Checks whether ch is a vowel by
            double-checking the vowels set */
            {
                ++vowelCount; // Increments vowelcount by 1
            }
        }
    }
    return vowelCount;
}

int main()
{
    int n; // Declares n in the int data type

    cout << "Computer Science I Coding Assignment 7 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Through the use of dynamic input, involving array and string "
         << "manipulation, this C++ program performs various operations "
         << "on an array of names, such as sorting in alphabetical\norder, "
         << "searching for a specific, case-sensitive name inputted by the "
         << "user, identifying the longest name in the list, and counting "
         << "the total number of vowels in the list. The\nprogram "
         << "lets the user specify the number of names and outputs the results "
         << "of the operations."
         << endl << endl; // Displays an explanation of the program

    while (true) /* Checks for input failure in n, then prompts the user
    repeatedly until the input is valid */
    {
        cout << "Enter the number of names: ";
        cin >> n;
        if (cin.fail() || n <= 0) // Checks whether the input for n is valid
        {
            cin.clear(); // Clears the input stream
            cin.ignore(100, '\n'); /* Ignores the invalid input and clears
            the buffer */
            cout << "Invalid number of names. Please try again." << endl;
            // Outputs a statement to the user to input the number of names again
        }
        else
        {
            break; // Breaks the while loop if the input is valid
        }
    }

    string* names = new string[n]; /* Dynamically allocates memory for an array of n
    string */

    cout << "Enter " << n << " names: " << endl;
    cin.ignore(); // Manages leftover characters in the input buffer
    for (int i = 0; i < n; ++i) /* Prints the assigned integer value of n, starting at 0,
    incrementing until i is less than n */
    {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, names[i]); /* Reads the inputted string, including
        whitespaces, then stores it in names[i] */
        names[i] = trim(names[i]); /* Uses the user-defined trim function to trim leading
        and trailing spaces from names[i] */
    }

    sortNames(names, n); /* Uses the user-defined sortNames function to sort the array
    names[] of n strings */

    cout << endl;
    cout << "Sorted List of Names: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << setw(15) << left << names[i] << endl; /* Prints the sorted list of names
        in alphabetical order left-aligned and at a set minimum width of 15 */
    }

    string target;
    cout << endl;
    cout << "Enter a name to search: ";
    getline(cin, target); /* Reads the inputted string, including whitespaces, then
    stores it in target */
    if (searchName(names, n, target)) /* Checks whether the string in target is in the list,
    then displays the result */
    {
        cout << target << " found in the list." << endl << endl;
    }
    else
    {
        cout << target << " not found in the list." << endl << endl;
    }

    string longestName = findLongestName(names, n); /* Stores the result of the
    user-defined function findLongestName into longestName */
    cout << "Longest Name: " << longestName << endl;

    int vowelCount = countVowels(names, n); /* Stores the result of the
    user-defined function countVowels into vowelCount */
    cout << "Total Vowel Count: " << vowelCount << endl;

    delete[] names; // Deallocates memory previously allocated dynamically using new[]

    return 0; // Terminates the program
}