#include <iostream>
#include "Date.h"
#include "Grade.h"
#include "Student.h"
#include "Class.h"
using namespace std;

int main() {
    grade g1("harmonic",12,2),g2("pig",14,3),g3("cpp",13,3),g4(g2),g5(g1),g6("cpp",3,4);
    date dj(20,05,1993);
    student s,s1("John","Guerilla",dj,g1,g2,g3),s2("Giov","Doe",dj,g4,g5,g6);
    myclass Aero3;
    Aero3.add_student(s);
    Aero3.add_student(s1);
    Aero3.add_student(s2);
    Aero3.display_students();
    Aero3.display_class_average();
    cout<<s.calculate_average()<<endl;
    return 0;
}