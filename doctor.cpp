#include "doctor.hpp"

using std::string, std::istream, std::ostream, std::setfill, std::setw,
std::stringstream;

Doctor::Doctor() {}

Doctor::Doctor(const Doctor& d) : empCode(d.empCode), name(d.name),
    license(d.license), arrival(d.arrival), departure(d.departure) {}

Doctor& Doctor::operator = (const Doctor& d) {
    empCode = d.empCode;
    name = d.name;
    license = d.license;
    arrival = d.arrival;
    departure = d.departure;

    return *this;
    }

void Doctor::setEmpCode(const long& c) {
    empCode = c;
    }

void Doctor::setName(const Name& n) {
    name = n;
    }

void Doctor::setLicense(const long& l) {
    license = l;
    }

void Doctor::setArrival(const Time& t) {
    arrival = t;
    }

void Doctor::setDeparture(const Time& t) {
    departure = t;
    }

string Doctor::toString() const {
    string str;
    long firstPart = empCode / 10000000;
    long lastPart = empCode % 10000000;

    str = std::to_string(firstPart) + '-' + std::to_string(lastPart);
    str += '\n';
    str += name.toString();
    str += '\n';
    str += license;
    str += '\n';
    str += arrival.toString();
    str += " | ";
    str += departure.toString();

     return str;
    }

long Doctor::getEmpCode() const {
    return empCode;
    }

Name Doctor::getName() const {
    return name;
    }

long Doctor::getLicense() const {
    return license;
    }

Time Doctor::getArrival() const {
    return arrival;
    }

Time Doctor::getDeparture() const {
    return departure;
    }

bool Doctor::operator == (const Doctor& d) const {
    return empCode == d.empCode;
    }

bool Doctor::operator != (const Doctor& d) const {
    return !(*this == d);
    }

bool Doctor::operator < (const Doctor& d) const {
    return empCode < d.empCode;
    }

bool Doctor::operator <= (const Doctor& d) const {
    return *this < d or *this == d;
    }

bool Doctor::operator > (const Doctor& d) const {
    return !(*this <= d);
    }

bool Doctor::operator >= (const Doctor& d) const {
    return !(*this < d);
    }

istream& operator >> (istream& is, Doctor& d) {
    string str;

    getline(is, str, '*'); // read 87-2202565*

    stringstream strStream(str); // 87-2202565

    getline(strStream, str, '-'); // read 87-
    long firstPart = stol(str);

    getline(strStream, str); // read 2202565
    long lastPart = stol(str);

    d.empCode = firstPart*10000000 + lastPart; // combined

    is >> d.name; // read name

    getline(is, str, '*'); // read license
    d.license = stol(str);

    is >> d.arrival;

    is >> d.departure;

    return is;
    }

ostream& operator << (ostream& os, const Doctor& d) {
    long firstPart = d.empCode / 10000000;
    long lastPart = d.empCode % 10000000;

    os << setfill('0') << setw(2) << firstPart << "-"
       << setfill('0') << setw(7) << lastPart << "*";

    os << d.name;

    os << d.license << "*";

    os << d.arrival << d.departure;

    return os;
    }
