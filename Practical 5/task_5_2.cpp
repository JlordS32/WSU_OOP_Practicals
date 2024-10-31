#include <iostream>

using namespace std;

#include "Student.h"

int main() {

    Student student = Student("John", 3);
    student.addUnit();
    student.display();
    
    return 0;
}