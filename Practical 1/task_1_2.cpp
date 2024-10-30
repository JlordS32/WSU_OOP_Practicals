#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Initiliase variable 
    int month, day;

    // Input user
    cout << "Welcome to your friendly weather program.\n" 
         << "Enter today's date as two integers for the month and the day :\n ";
    
    // Get user input
    cin >> month;
    cin >> day;

    // Seed
    srand(month * day);

    // Initialise prediction, ans variable
    int prediction;
    char ans;

    // Generate prediction
    cout << "Weather for today:\n";
    do
    {
        // Randomly choose number between 0 - 2 (inclusive)
        prediction = rand() % 3;
        
        // Output the prediction based on the random number.
        switch (prediction)
        {
        case 0:
            cout << "The day will be sunny!!\n";
            break;
        case 1:
            cout << "The day will be cloudy.\n";
            break;
        case 2:
            cout << "The day will be stormy!.\n";
            break;
        default:
            cout << "Weather program is not functioning properly.\n ";
        }

        // Ask user if they want the weather for the next day
        cout << "Want the weather for the next day?(y/n): ";
        
        // Update ans and validate to repeat
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    // Output
    cout << "That's it from your 24 hour weather program.\n";

    return 0;
}