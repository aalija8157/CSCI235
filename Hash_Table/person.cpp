#include <iostream>
#include "person.h"

person::person()
{
    first = "";
    last = "";
    title = "";
    salary = 0;
}
person::person(std::string first, std::string last)
{
    this->first = first;
    this->last = last;
    title = "";
    salary = 0;
}
person::person(std::string first, std::string last, double salary)
{
    this->first = first;
    this->last = last;
    title = "";
    this->salary = salary;
}

person::person(std::string first, std::string last, std::string title, double salary)
{
    this->first = first;
    this->last = last;
    this->title = title;
    this->salary = salary;
}
