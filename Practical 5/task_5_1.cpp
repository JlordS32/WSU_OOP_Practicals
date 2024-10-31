//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>

using namespace std;

const int NUMBER_OF_PLANTS = 4;
#include "ProductionGraph.h"

int main( )
{
    ProductionGraph graph(NUMBER_OF_PLANTS);

    graph.inputData();
    graph.graph();

    return 0;
}
