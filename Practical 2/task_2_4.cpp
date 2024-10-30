#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

/* Task 2.4

    A power station is on one side of a river that is one-half kilometers wide, and a
    factory is eight kilometers downstream on the other side of the river (see the
    following figure). It costs $70 per meter to run power lines over land and $90 per
    meter to run them under water. Your objective is to determine the most economical
    path to lay the power line. That is, determine how long the power line should run
    under water and how long it should run over land to achieve the minimum total cost
    of laying the power line (the precision of length is set to 1 meter). 

    Write a program that prompts the user to enter:
        a. The width of the river
        b. The distance of the factory downstream on the other side of the river.
        c. The unit cost of laying the power line underwater.
        d. The unit cost of laying the power line overland.
        The program then outputs the length of the power line that should run under water
        and the length that should run overland so that the cost of constructing the power
    line is minimum. The program should also output the total cost of constructing the
    power line.

    HINT: Loop x from 0 to the distance of the factory (say 8000 meters) to find the
    minimal cost.
 */

int main() {
    double riverWidth, distanceDownstream, costUnderwater, costOverland;

    // USER INPUT
    cout << "Enter river width (in meters): ";
    cin >> riverWidth;

    cout << "Enter distance downstream (in meters): ";
    cin >> distanceDownstream;

    cout << "Enter cost of power line underwater: ";
    cin >> costUnderwater;

    cout << "Enter cost of power line overland: ";
    cin >> costOverland;

    // Initialize best cost to a large number and variables to store optimal distances
    double bestCost = numeric_limits<double>::max();
    double bestUnderwaterDistance = 0;
    double bestOverlandDistance = 0;

    // Loop through all possible overland distances
    for (int i = 0; i <= distanceDownstream; i++) {
        double overlandCost = costOverland * i;
        double riverDistance = sqrt(riverWidth * riverWidth + (distanceDownstream - i) * (distanceDownstream - i));
        double underwaterCost = costUnderwater * riverDistance;
        double totalCost = underwaterCost + overlandCost;

        // Check if this is the minimal cost
        if (totalCost < bestCost) {
            bestCost = totalCost;
            bestOverlandDistance = i;
            bestUnderwaterDistance = riverDistance;
        }
    }

    // OUTPUT
    cout << "Optimal underwater distance: " << bestUnderwaterDistance << " meters" << endl;
    cout << "Optimal overland distance: " << bestOverlandDistance << " meters" << endl;
    cout << "Minimum total cost: $" << bestCost << endl;


    return 0;
}