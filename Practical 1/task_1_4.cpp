#include <iostream>

using namespace std;

/*  Task 1.4:
    
    Write a nested for loop that prints out a multiplication table for the integers 1 through
    10.
*/

int main() {
    for (int i = 1; i <= 10; i++)  {
        for (int j = 1; j <= 10; j++) {
            cout << "\t" << i * j;
        }

        cout << endl;
    }

    return 0;
}