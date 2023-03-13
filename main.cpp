#include <iostream>
#include "Date.h"
#include "Grade.h"
#include "Student.h"
#include "Class.h"
using namespace std;

int main() {
student s;
s.display();
myclass Aero3;
Aero3.add_student(s);
Aero3.display_students();
return 0;
}