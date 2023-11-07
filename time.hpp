#ifndef TIME_HPP_INCLUDED
#define TIME_HPP_INCLUDED

#include <string>
#include <iostream>
#include <sstream> // stringstream
#include <iomanip> // setw, setfill
#include <stdexcept> // invalid_argument

class Time {
    int hour;
    int minute;

    int toInt() const;

    bool isValid(const int&, const int&) const; // hour, minute

public:
    Time();
    Time(const Time&);

    Time& operator = (const Time&);

    void setHour(const int&);
    void setMinute(const int&);

    std::string toString() const;

    int getHour() const;
    int getMinute() const;

    bool operator == (const Time&) const;
    bool operator != (const Time&) const;
    bool operator < (const Time&) const;
    bool operator <= (const Time&) const;
    bool operator > (const Time&) const;
    bool operator >= (const Time&) const;

    friend std::istream& operator >> (std::istream&, Time&);
    friend std::ostream& operator << (std::ostream&, const Time&);
};

#endif // TIME_HPP_INCLUDED
