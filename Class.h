//
// Created by Joachim Sonigo on 3/2/2023.
//
using namespace std;
#include <iostream>
#ifndef HOMEWORKCPP3FINAL_CLASS_H
#define HOMEWORKCPP3FINAL_CLASS_H
/*
class homeroom:public student{
private:
student classroom[40];
student sortedclass[40];
float gpa;
static int N;

public:
homeroom();
homeroom(student,student,float);
virtual ~homeroom();


//void disp_class();
};
homeroom::homeroom() {classroom[N]=student(),sortedclass[N]=student();N++;}
void homeroom::disp_class() {
    cout<<"Class"<<endl;
    for (int i = 0; i < N; ++i) {
        cout<<classroom[i]<<endl;
    }
}
*/

#include <vector>
#include <algorithm>
#include "Student.h"

class myclass {
private:
    vector<student> students;
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
};

myclass::myclass() {}
myclass::~myclass() {}

void myclass::add_student(student s) {
    students.push_back(s);
}

void myclass::remove_student(int index) {
    students.erase(students.begin() + index);
}

void myclass::display_students() {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i] << endl;
    }
}

double myclass::calculate_class_average() {
    double sum = 0.0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].calculate_average();
    }
    return sum / students.size();
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
#endif //HOMEWORKCPP3FINAL_CLASS_H
