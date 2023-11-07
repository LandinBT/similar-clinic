#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

#include <string>
#include <iostream>

class Date {
    int day;
    int month;
    int year;

    int toInt() const;

    bool isValid() const;

public:
    Date();
    Date(const Date&);

    Date& operator = (const Date&);

    void setDay(const int&);
    void setMonth(const int&);
    void setYear(const int&);

    std::string toString() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator == (const Date&) const;
    bool operator != (const Date&) const;
    bool operator < (const Date&) const;
    bool operator <= (const Date&) const;
    bool operator > (const Date&) const;
    bool operator >= (const Date&) const;

    friend std::istream& operator >> (std::istream&, Date&);
    friend std::ostream& operator << (std::ostream&, const Date&);
};

#endif // DATE_HPP_INCLUDED
