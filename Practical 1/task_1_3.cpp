#include <iostream>

/*
    Write a program that includes two functions. The first function asks the user to input a
    value in double that represents the dollar value of daily sales of a salesperson. The
    function should return that value as function return. The second function takes the
    outcome of the first function and calculates the salesperson’s commission based on
    the following rates:

        Sales              Commission
        -----------------------------
        $0-$999             3%
        $1,000-$2,999       3.5%
        $3,000 - above      up 4.5%

    The function should return the value of commission. Call these two functions in the
    main function to demonstrate calculation of salesperson’s commission.
 */


using namespace std;

double query();
double calculateRate(double sales);

int main() {
    double sales = query();
    double commission = calculateRate(sales);

    cout << "Commission: $" << commission << endl;

    return 0;
}

double query() {
    double input;

    cout << "Input a number: ";
    cin >> input;

    return input;
}

double calculateRate(double sales) {
    double commission;

    if (sales <= 999) {
        commission = sales * 0.03;
    } else if (sales <= 2999) {
        commission = sales * 0.035;
    } else {
        commission = sales * 0.045;
    }

    return commission;
}