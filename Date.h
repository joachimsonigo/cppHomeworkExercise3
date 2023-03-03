//
// Created by Joachim Sonigo on 2/26/2023.
//
#include <iostream>

using namespace std;
#ifndef HOMEWORKCPP3FINAL_DATE_H
#define HOMEWORKCPP3FINAL_DATE_H

class date{
    int day;
    int month;
    int year;
public:
    //Constructors&Destructor
    date();
    date(int,int,int);
    date(const date&);
    ~date();

    //Setters and Getters
    void set_day(int);
    void set_month(int);
    void set_year(int);
    int get_day();
    int get_month();
    int get_year();

    friend ostream& operator <<(ostream&,const date&);
    friend istream& operator >>(istream&,date&);
};

date::date() {day=0;month=0;year=0;}
date::date(int d, int m, int y) {day=d;month=m;year=y;}
date::date(const date &d) {day=d.day;month=d.month;year=d.year;}
date::~date() {}

void date::set_day(int d) {day=d;}
void date::set_month(int m) {month =m;}
void date::set_year(int y) {year =y;}
int date::get_day() {return day;}
int date::get_month() {return month;}
int date::get_year() {return year;}

ostream& operator <<(ostream&os,const date&d){os<<"day= "<<d.day<<", month: "<<d.month<<" and year :"<<d.year<<endl;return(os);};
istream& operator >>(istream&is, date&d){cout<<"Day:";is>>d.day;cout<<"Month :";is>>d.month;cout<<"Year :";is>>d.year;}

#endif //HOMEWORKCPP3FINAL_DATE_H
