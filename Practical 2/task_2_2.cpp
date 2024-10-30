#include <iostream>

using namespace std;

/*  Task 2.2
    
    Write a function that takes two integers, numerator and denominator, as input
    parameters and output their quotient and remainder. Use a main function test the
    function.

    Hint: Use call by reference to output the quotient and remainder as parameters (see an
    example for Code for Lecture 2 (TwoDigits.cpp). Use the following formula to
    calculate quotient and remainder:

    quotient = numerator / denominator;
    remainder = numerator % denominator;
 */


void calculate(int &qoutient, int &remainder, int numerator, int denominator);

int main()
{
    int numerator, denominator, qoutient, remainder;

    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    calculate(qoutient, remainder, numerator, denominator);

    // Output
    cout << "Quotient: " << qoutient << endl;
    cout << "Remainder: " << remainder << endl;

    return 0;
}

void calculate(int &qoutient, int &remainder, int numerator, int denominator) {
    qoutient = numerator / denominator;
    remainder = numerator % denominator;
}
