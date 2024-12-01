#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void sortNames (vector<string>& names) {
    sort(names.begin(), names.end());
}

bool searchName (const vector<string>& names, const string& target) {
    for (const auto& name : names) {
        if (name == target) {
            return true;
        }
    }
    return false;
}

string findLongestNames (const vector<string>& names) {
    string longest = names[0];
    for (const auto& name : names) {
        if (name.length() > name.length()) {
            longest = name;
        }
    }
    return longest;
}

int countVowels (const vector<string>& names) {
    int vowelCount =0;
    for (const auto& name : names ) {
        for (char ch : name) {
            if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || 
                    ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' ) {
                    vowelCount++;
            }
        }
    }
    return vowelCount;
}

int main() {
    int n;

    cout << "Enter the number of names you would like to have listed:" <<endl;
    cin >> n;
    cin.ignore();

    vector<string> names(n);

    cout << "Enter the names:" <<endl;
    for (int i = 0; i < n; i++) {
        getline(cin, names[i]);
    }

    sortNames (names);

    cout << "\nSorted list of names:" <<endl;
    for (const auto& name : names) {
        cout << name << endl;
    }

    string target;
    cout << "\nEnter the name you wish to search:";
    getline(cin, target);
    if (searchName (names, target)) {
        cout << "The name '" << target << "' was found in the list." <<endl;
    } else {
            cout << "The name '" << target << "' was not found in the list." <<endl;
        }
    

    string longestName = findLongestNames (names);
    cout << "\nThe Longest name in the list was: " << longestName <<endl;

    int totalVowels = countVowels (names);
    cout << "The total number of vowels in the list was: " << totalVowels << endl;

    return 0;
}
