#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_NAMES = 25; // To set maximun name limit

// To sort names alphabetically
void sortNames(string names[], int count) {
    sort(names, names + count);
}

// Searches for a specific name provided by the user
bool searchName(const string names[], int count, const string& target) {
    for (int i = 0; i < count; i++) {
        if (names[i] == target) {
            return true;
        }
    }
    return false;
}

// Function to find the longest name
string findLongestName(const string names[], int count) {
    string longest = names[0];
    for (int i = 1; i < count; i++) {
        if (names[i].length() > longest.length()) {
            longest = names[i];
        }
    }
    return longest;
}

// Function to count vowels in all names
int countVowelsInList(const string names[], int size) {
    const string vowels = "aeiouAEIOU";
    int totalVowels = 0;
    for (int i = 0; i < size; i++) {
        for (char c : names[i]) {
            if (vowels.find(c) != string::npos) {
                totalVowels++;
            }
        }
    }
    return totalVowels;
}

int main() {
    int numberOfNames;

    cout << "Enter the number of names (max " << MAX_NAMES << "): ";
    cin >> numberOfNames;
    cin.ignore(); 

    if (numberOfNames > MAX_NAMES) {
        cout << "Error: Maximum allowed number of names is " << MAX_NAMES << "." << endl;
        return 1;
    }

    // Declare an array to store the names
    string names[MAX_NAMES];

    // Input names
    cout << "Enter " << numberOfNames << " names:" << endl;
    for (int i = 0; i < numberOfNames; i++) {
        cout << "Name " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    // Sort names
    sortNames(names, numberOfNames);

    // Display sorted names
    cout << "\nSorted list of names:" << endl;
    for (int i = 0; i < numberOfNames; i++) {
        cout << names[i] << endl;
    }

    // Search for a name
    string nameToSearch;
    cout << "\nEnter a name to search: ";
    getline(cin, nameToSearch);
    if (searchName(names, numberOfNames, nameToSearch)) {
        cout << "The name \"" << nameToSearch << "\" founded in the list." << endl;
    } else {
        cout << "The name \"" << nameToSearch << "\" not founded in the list." << endl;
    }

    // Function to find the longest name
    string longestName = findLongestName(names, numberOfNames);
    cout << "\nLongest name: " << longestName << endl;

    // Count vowels in all names
    int vowelCount = countVowelsInList(names, numberOfNames);
    cout << "Total number of vowels in all names: " << vowelCount << endl;

    return 0;
}
