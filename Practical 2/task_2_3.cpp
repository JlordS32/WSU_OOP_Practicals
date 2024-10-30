#include <iostream>

using namespace std;

/* Task 2.3
    Write a function named sort that takes three integer parameters by reference. The
    function should rearrange the parameter values so that the first parameter gets set to
    the smallest value, the second parameter gets set to the second smallest value, and the
    third parameter gets set to the largest value. For example, given the variable
    assignments a=30; b=10; c=20; then the function call sort(a,b,c) should result in a
    10, b=20, and c=30. Write also a main function to take input of three integers, call 
    the function with the input and output the results of the function.
*/

void sort(int &a, int &b, int &c);

int main() {
    int a = 30;
    int b = 10;
    int c = 20;

    sort(a, b, c);
    cout << a << " " << b << " " << c;

    return 0;
}

void sort(int &a, int &b, int &c) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    } 
    
    if (b < c) {
        int temp = b;
        b = c;
        c = temp;
    } 
    
    if (c < a) {
        int temp = c;
        c = a;
        a = temp;
    }
}