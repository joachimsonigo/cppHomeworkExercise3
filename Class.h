//
// Created by Joachim Sonigo on 3/2/2023.
//
using namespace std;
#include <iostream>
#ifndef HOMEWORKCPP3FINAL_CLASS_H
#define HOMEWORKCPP3FINAL_CLASS_H

#include <vector>
#include <algorithm>
#include "Student.h"

class myclass {
private:
    vector<student> students;
    static int N ;
public:
    //Constructor and Destructor
    myclass();
    virtual ~myclass();
    //Methods
    void add_student(student);
    void remove_student(int);
    void display_students();
    double calculate_class_average();
    void display_class_average();
    void display_class_rankings();

    friend ostream& operator <<(ostream&,const myclass&);
    friend istream& operator >>(istream&,myclass&);
};

myclass::myclass() {}
myclass::~myclass() {N--;}

void myclass::add_student(student s) {
    students.push_back(s);
    N++;
}
int myclass::N = 0;

void myclass::remove_student(int index) {
    students.erase(students.begin() + index);
    N--;
}

void myclass::display_students() {
    for (int i = 0; i < N; i++) {
        cout << students[i] << endl;
    }
}

double myclass::calculate_class_average() {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        if (students[i].calculate_average()>0)
            sum += students[i].calculate_average();
        else
            sum=sum;
    }
    return sum / N;
}

void myclass::display_class_average() {
    cout << "The class average is: " << calculate_class_average() << endl;
}

void myclass::display_class_rankings() {
    vector<double> averages;
    for (int i = 0; i < students.size(); i++) {
        averages.push_back(students[i].calculate_average());
    }
    sort(averages.begin(), averages.end(), greater<double>());
    for (int i = 0; i < averages.size(); i++) {
        cout << "Rank " << i+1 << ": " << averages[i] << endl;
    }
}

ostream& operator <<(ostream& os, const myclass& c){
    os << "Class Information:" << endl;
    for(int i = 0; i < c.students.size(); i++){
        os << "Name: " << c.students[i].get_name() << ", Last Name: " << c.students[i].get_lname()
           << ", Birthdate: " << c.students[i].get_ddn() << ", Grades: " << c.students[i].get_g1()
           << " " << c.students[i].get_g2() << " " << c.students[i].get_g3() << ", Average: " << c.students[i].calculate_average() << endl;
    }
    return os;
}

istream& operator >>(istream& is, myclass& c){
    string name, last_name, birthdate,m1,m2,m3;
    double grade_1, grade_2, grade_3;
    int co1,co2,co3,dd,mm,yy;
    cout << "Enter student information:" << endl;
    cout << "Name: "<<endl;
    is >> name;
    cout << "Last Name: "<<endl;
    is >> last_name;
    cout << "Birthdate (Enter day then month then year): "<<endl;
    is >> dd>>mm>>yy;
    cout<<"Name of each grade matter (three of them seperated by spaces)"<<endl;
    is >> m1 >> m2 >>m3;
    cout << "Grades (three grades separated by spaces): "<<endl;
    is >> grade_1 >> grade_2 >> grade_3;
    cout<<"Coefficients of the grades (three coef separated by spaces)"<<endl;
    is >> co1 >> co2 >> co3;
    student s(name, last_name, date(dd,mm,yy), grade(m1,grade_1,co1), grade(m2,grade_2,co2), grade(m3,grade_3,co3));
    c.add_student(s);
    return is;
}

#endif //HOMEWORKCPP3FINAL_CLASS_H
