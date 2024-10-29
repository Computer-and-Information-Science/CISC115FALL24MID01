#include <iostream> //Shorter than the other programs, but it will loop descending until the value is less than 2
using namespace std;

int main (){
    for (int i = 20; i >= 2; i -= 2){
        cout<<i<<" ";
    }
    return 0;
}