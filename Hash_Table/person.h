#pragma once

class person
{
  public:
    person();
    person(std::string first, std::string last);
    person(std::string first, std::string last, double salary);
    person(std::string first, std::string last, std::string title, double salary);
    std::string last; // last name
    std::string first; // first name
    std::string title;
    double salary;

    bool operator==(const person& p)const {return (p.last == this->last) && (p.first == this->first) && (p.title == this->title) && (p.salary == this->salary);}
    // you can add public or private members as you need.
    // you can also make the above private if you prefer.
    // you can also change the data items from title and salary
    // if you want. Just make sure to use last and first name
    // as your keys.
};
