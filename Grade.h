//
// Created by Joachim Sonigo on 2/26/2023.
//
using namespace std;
#include <iostream>
#include <string>
#ifndef HOMEWORKCPP3FINAL_GRADE_H
#define HOMEWORKCPP3FINAL_GRADE_H
class grade{
private:
    string matter;
    double n;
    int coef;
public:
    //Constructors and Destructor
    grade();
    grade(string, double,int);
    grade(const grade&);
    ~grade();

    //Setters and Getters
    void set_matter(string);
    void set_n(double);
    void set_coef(int);
    string get_matter();
    double get_n();
    int get_coef();

    //Overloading Ops
    friend ostream& operator <<(ostream&,const grade&);
    friend istream& operator >>(istream&,grade&);

};
//-------------------
//Definitions
//-------------------
grade::grade() {matter = "no matter";n=0;coef=0;}
grade::grade(string m, double nb, int c) {matter =m;n=nb;coef=c;}
grade::grade(const grade &g) {matter=g.matter;n=g.n;coef=g.coef;}
grade::~grade() {}

void grade::set_matter(string m) {matter=m;}
void grade::set_coef(int c) {coef=c;}
void grade::set_n(double nb) {n=nb;}

string grade::get_matter() {return matter;}
double grade::get_n() {return n;}
int grade::get_coef() {return coef;}

ostream& operator <<(ostream&os,const grade&g){os<<"Matter : "<<g.matter<<", grade : "<<g.n<<" and of coefficient :"<<g.coef<<endl;return(os);};
istream& operator >>(istream&is, grade&g){cout<<"Matter is :";is>>g.matter;cout<<"With a grade of :";is>>g.n;cout<<"And a coefficient of :";is>>g.coef;}
#endif //HOMEWORKCPP3FINAL_GRADE_H
