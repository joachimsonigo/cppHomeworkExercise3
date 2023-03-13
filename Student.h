//
// Created by Joachim Sonigo on 2/26/2023.
//
#include <iostream>
#include <string>
#ifndef HOMEWORKCPP3FINAL_STUDENT_H
#define HOMEWORKCPP3FINAL_STUDENT_H
using namespace std;
class student:public grade,date{
private:
    string name;
    string lname;
    date ddn;
    grade g1,g2,g3;
    double average;
public:
    //Constructors and Destructor
    student();
    student(string,string,date,grade,grade,grade);
    virtual ~student();
    //Setters and Getters
    void set_name(string);
    void set_lname(string);
    void set_ddn(date);
    void set_g1(grade);
    void set_g2(grade);
    void set_g3(grade);
    void set_average(double);
    string get_name() const;
    string get_lname() const;
    date get_ddn() const;
    grade get_g1() const;
    grade get_g2() const;
    grade get_g3() const;
    double get_average();

    //Method
    double calculate_average() const;
    void display();
    //Overloading Ops
    friend ostream& operator <<(ostream&,const student&);
    friend istream& operator >>(istream&,student&);

};
student::student() {name="no name";lname="no last name";ddn=date();g1=grade();g2=grade();g3=grade();average = 0;}
student::student(string n, string ln, date d, grade grade1, grade grade2, grade grade3) {name=n;lname=ln;ddn=d;g1=grade1;g2=grade2;g3=grade3;}
student::~student() {}

//Setters
void student::set_name(string n) {name = n;}
void student::set_lname(string ln) {lname=ln;}
void student::set_ddn(date d) {ddn = d;}
void student::set_g1(grade grade1) {g1=grade1;}
void student::set_g2(grade grade2) {g2=grade2;}
void student::set_g3(grade grade3) {g3=grade3;}
void student::set_average(double a) {average=a;}

//Getters
string student::get_name() const {return name;}
string student::get_lname() const {return lname;}
date student::get_ddn() const {return ddn;}
grade student::get_g1() const {return g1;}
grade student::get_g2() const {return g2;}
grade student::get_g3() const {return g3;}
double student::get_average() {return average;}

//Ops
ostream& operator <<(ostream&os,const student&s){os<<"Name: "<<s.name<<", last name: "<<s.lname<<", born :"<<s.ddn<<"with grades "<<s.g1<<s.g2<<s.g3<<endl;return(os);};
istream& operator >>(istream&is, student&s){cout<<"name:";is>>s.name;cout<<"last name :";is>>s.lname;cout<<"Birthdate :";is>>s.ddn;cout<<"Grades :";is>>s.g1;is>>s.g2;is>>s.g3;cout<<"Average :";is>>s.average;}

//Definition of Methods
double student::calculate_average() const {double a;a= ((g1.grade::get_n() * g1.grade::get_coef()) + (g2.grade::get_n() * g2.grade::get_coef()) + (g3.grade::get_n() * g3.grade::get_coef())) / (g1.grade::get_coef() + g2.grade::get_coef() + g3.grade::get_coef());return a;}
void student::display() {cout<<"The student is named : "<<name<<" "<<lname<<".\nThey are born on the "<<ddn.date::get_day()<<" of "<<ddn.date::get_month()<<" in the year "<<ddn.date::get_year()<<".\nThey've gotten the following grades: "<<g1.grade::get_n()<<" in "<<g1.grade::get_matter()<<" with a coefficient of "<<g1.grade::get_coef()<<".\n"<<endl;cout<<g2.grade::get_n()<<" in "<<g2.grade::get_matter()<<" with a coefficient of "<<g2.grade::get_coef()<<".\n"<<endl;cout<<g3.grade::get_n()<<" in "<<g3.grade::get_matter()<<" with a coefficient of "<<g3.grade::get_coef()<<"."<<endl;}
#endif //HOMEWORKCPP3FINAL_STUDENT_H
