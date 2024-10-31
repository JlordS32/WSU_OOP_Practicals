#ifndef ONEDARRAY_H
#define ONEDARRAY_H

#include <iostream>

using namespace std;

class OneDArray
{
private:
    int *arr;
    int size;
    int numberUsed;

public:
    OneDArray(int s)
    {
        arr = new int[s];
        size = s;
    }
    ~OneDArray()
    {
        delete[] arr;
    }

    void fillArray()
    {
        cout << "Enter up to " << size 
             << " nonnegative integers.\n" 
             << "Mark the end of the list with a negative number.\n";

        int next, index = 0;

        cin >> next;
        while ((next >= 0) && (index < size))
        {
            this->arr[index] = next;
            index++;
            cin >> next;
        }

        this->numberUsed = index;
    }

    int search(int target)
    {
        int index = 0;
        bool found = false;

        // Add your code here for Task 3.1
        while ((index < this->numberUsed) && (!found))
        {
            if (this->arr[index] == target)
                found = true;
            else
                index++;
        }

        if (found)
            return index;
        else
            return -1;
    }
};

#endif