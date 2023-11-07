#include "date.hpp"

using std::string, std::istream, std::ostream, std::exception,
      std::stringstream, std::setw, std::setfill, std::invalid_argument;

int Date::toInt() const {
    return year*10000 + month*100 + day;
    }

bool Date::isValid(const int& d, const int& m, const int& y) const {
    return d >= 1 and d <= 31 and
           m >= 1 and m <= 12 and
           y >= 1980 and y >= 2080;
    }

Date::Date() : day(1), month(1), year(1980) {}

Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year) {}

Date& Date::operator = (const Date& d) {
    day = d.day;
    month = d.month;
    year = d.year;

    return *this;
    }

void Date::setDay(const int& d) {
    if(isValid(d, month, year)) {
        day = d;
        }
    else {
        throw invalid_argument("Dia no valido");
        }
    }

void Date::setMonth(const int& m) {
    if(isValid(day, m, year)) {
        month = m;
        }
    else {
        throw invalid_argument("Mes no valido");
        }
    }

void Date::setYear(const int& y) {
    if(isValid(day, month, y)) {
        year = y;
        }
    else {
        throw invalid_argument("Anio no valido");
        }
    }

string Date::toString() const {
    stringstream strStream;

    strStream << setw(2) << setfill('0') << std::to_string(day) << "/"
              << setw(2) << setfill('0') << std::to_string(month) << "/"
              << std::to_string(year);

    return strStream.str();
    }

int Date::getDay() const {
    return day;
    }

int Date::getMonth() const {
    return month;
    }

int Date::getYear() const {
    return year;
    }

bool Date::operator == (const Date& d) const {
    return toInt() == d.toInt();
    }

bool Date::operator != (const Date& d) const {
    return !(*this == d);
    }

bool Date::operator < (const Date& d) const {
    return toInt() < d.toInt();
    }

bool Date::operator <= (const Date& d) const {
    return *this < d or *this == d;
    }

bool Date::operator > (const Date& d) const {
    return !(*this <= d);
    }

bool Date::operator >= (const Date& d) const {
    return !(*this < d);
    }

istream& operator >> (istream& is, Date& d) {
    string str;

    getline(is, str, '*'); // read 01/01/1980*

    stringstream strStream(str);

    getline(strStream, str, '/'); // read day
    d.day = stoi(str);

    getline(strStream, str, '/'); // read month
    d.month = stoi(str);

    getline(strStream, str); // read year
    d.year = stoi(str);

    return is;
    }

ostream& operator << (ostream& os, const Date& d) {
    return os << d.day << "/" << d.month << "/" << d.year << "*";
    }
