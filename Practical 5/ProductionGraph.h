#ifndef PRODUCTIONGRAPH_H
#define PRODUCTIONGRAPH_H

#include <iostream>

using namespace std;

class ProductionGraph
{
private:
    int *production;
    int size;

    void getTotal(int &amount);
    void printAsterisks(int n);
public:
    ProductionGraph(int size)
    {
        this->production = new int[size];
        this->size = size;
    }

    ~ProductionGraph()
    {
        delete[] production;
    }

    void inputData();
    void graph();
};

void ProductionGraph::inputData()
{
    for (int i = 1; i <= this->size; i++)
    {
        cout << endl
             << "Enter production data for plant number "
             << i << endl;
        getTotal(this->production[i - 1]);
    }
}

void ProductionGraph::getTotal(int &amount)
{
    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n"
         << endl;
    cin >> amount;
    while (!(amount < 0 && amount > 20))
    {
        cout << "ERROR: Input again!" << endl;
        cin >> amount;
    }
}

void ProductionGraph::graph()
{
    cout << "\nUnits produced in units:\n";
    for (int i = 1; i <= this->size; i++)
    {
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void ProductionGraph::printAsterisks(int n)
{
    for (int count = 1; count <= n; count++)
        cout << "*";
}

#endif