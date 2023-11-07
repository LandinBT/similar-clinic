#include "time.hpp"

using std::string, std::istream, std::ostream, std::exception,
      std::stringstream, std::setw, std::setfill, std::invalid_argument;

int Time::toInt() const {
    return hour*100 + minute;
    }

bool Time::isValid(const int& h, const int& m) const {
    return h >= 0 and h < 24 and
           m >= 0 and m < 60;
    }

Time::Time() : hour(0), minute(0) {}

Time::Time(const Time& t) : hour(t.hour), minute(t.minute) {}

Time& Time::operator = (const Time& t) {
    hour = t.hour;
    minute = t.minute;

    return *this;
    }

void Time::setHour(const int& h) {
    if(isValid(h, minute)) {
        hour = h;
        }
    else {
        throw invalid_argument("Hora no valida");
        }
    }

void Time::setMinute(const int& m) {
    if(isValid(hour, m)) {
        minute = m;
        }
    else {
        throw invalid_argument("Minuto no valido");
        }
    }

string Time::toString() const {
    stringstream strStream;

    strStream << setw(2) << setfill('0') << std::to_string(hour) << ":"
              << setw(2) << setfill('0') << std::to_string(minute);

    return strStream.str();
    }

int Time::getHour() const {
    return hour;
    }

int Time::getMinute() const {
    return minute;
    }

bool Time::operator == (const Time& t) const {
    return toInt() == t.toInt();
    }

bool Time::operator != (const Time& t) const {
    return !(*this == t);
    }

bool Time::operator < (const Time& t) const {
    return toInt() < t.toInt();
    }

bool Time::operator <= (const Time& t) const {
    return *this < t or *this == t;
    }

bool Time::operator > (const Time& t) const {
    return !(*this <= t);
    }

bool Time::operator >= (const Time& t) const {
    return !(*this < t);
    }

istream& operator >> (istream& is, Time& t) {
    string str;

    getline(is, str, '*'); // read 00:00*

    stringstream strStream(str);

    getline(strStream, str, ':'); // read hour(s)
    t.hour = stoi(str);

    getline(strStream, str); // read minute(s)
    t.minute = stoi(str);

    return is;
    }

ostream& operator << (ostream& os, const Time& t) {
    return os << t.hour << ":" << t.minute << "*";
    }
