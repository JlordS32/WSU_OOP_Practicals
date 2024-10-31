#include <iostream>

using namespace std;

#include "OneDArray.h"

const int DECLARED_SIZE = 10;

int main()
{
    OneDArray array = OneDArray(DECLARED_SIZE);

    array.fillArray();

    int target, result;
    cout << "Enter a number to search for: ";
    cin >> target;

    result = array.search(target);
    if (result == -1)
        cout << target << " is not on the list.\n";
    else
        cout << target << " is stored in array position "
             << result << endl
             << "(Remember: The first position is 0.)\n";

    return 0;
}
