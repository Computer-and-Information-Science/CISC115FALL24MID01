#include <iostream>
using namespace std;

int main() {
    cout << "The first 10 even positive integers in descending order are: ";
    for (int i = 20; i >= 2; i -= 2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
