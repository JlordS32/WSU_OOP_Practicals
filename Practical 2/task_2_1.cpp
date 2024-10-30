#include <iostream>

using namespace std;

/*  Task 2.1

    Given the following function definition:

        void testDefaultArg(int day = 1, string month= "Jan",
            int year = 2023) {
            cout << "Today is " << day <<" "
            << month << " " << year << endl;
        }

    Write a main function with the following function calls. 
    Explain the outcome to your tutor.

        testDefaultArg();
        testDefaultArg(10);
        testDefaultArg(10, "Jul");
        testDefaultArg(10, "Jul", 2023);
*/


void testDefaultArg(int day = 1, string month = "Jan", int year = 2023);
 
int main()
{
    testDefaultArg(); // This function will print with all the default values
    // Output: Today is 1 Jan 2023
    testDefaultArg(10); // This function call will print with day = 10, and everything default. 
    // Output: Today is 10 Jan 2023
    testDefaultArg(10, "Jul"); // This function call will print with day = 10, month = "Jul", and everything default.
    // Output: Today is 10 Jul 2023
    testDefaultArg(10, "Jul", 2023); // This function call will print with day = 10, month = "Jul", year = 2023
    // Output: Today is 1 Jan 2023

    return 0;
}

void testDefaultArg(int day, string month, int year)
{
    cout << "Today is " << day << " "
         << month << " " << year << endl;
}