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
    //Checker
    int checkdate(int,int,int);
    
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

int date::checkdate(int day,int month, int year){
    //check year
    if(year>=1900 && year<=9999)
    {
        //check month
        if(month>=1 && month<=12)
        {
            //check days
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)){
                printf("Date is valid.\n");
                return 1;}
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)) {
                printf("Date is valid.\n");
                return 1;}
            else if((day>=1 && day<=28) && (month==2)){
                printf("Date is valid.\n");
                return 1;}
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0))) {
                printf("Date is valid.\n");
                return 1;
            }
            else
                printf("Day is invalid.\n");
        }
        else
        {
            printf("Month is not valid.\n");
        }
    }
    else
    {
        printf("Year is not valid.\n");
    }
    return 0;
}
#endif //HOMEWORKCPP3FINAL_DATE_H
