#include "patient.hpp"

using std::string, std::istream, std::ostream, std::stringstream, std::setfill,
      std::setw;

Patient::Patient() {}

Patient::Patient(const Patient& p) : socSecNum(p.socSecNum),
    name(p.name), birth(p.birth), address(p.address), phoneNum(p.phoneNum) {}

Patient& Patient::operator = (const Patient& p) {
    socSecNum = p.socSecNum;
    name = p.name;
    birth = p.birth;
    address = p.address;
    phoneNum = p.phoneNum;

    return *this;
    }

void Patient::setSocSecNum(const long& n) {
    socSecNum = n;
    }

void Patient::setName(const Name& n) {
    name = n;
    }

void Patient::setBirth(const Date& d) {
    birth = d;
    }

void Patient::setAddress(const Address& a) {
    address = a;
    }

void Patient::setPhoneNum(const long& n) {
    phoneNum = n;
    }

string Patient::toString() const {
    return std::to_string(socSecNum) + '\n' + name.toString() + '\n' +
           birth.toString() + '\n' + address.toString() + '\n' +
           std::to_string(phoneNum);
    }

long Patient::setSocSecNum() const {
    return socSecNum;
    }

Name Patient::setName() const {
    return name;
    }

Date Patient::setBirth() const {
    return birth;
    }

Address Patient::setAddress() const {
    return address;
    }

long Patient::setPhoneNum() const {
    return phoneNum;
    }

bool Patient::operator == (const Patient& p) const {
    return socSecNum == p.socSecNum;
    }

bool Patient::operator != (const Patient& p) const {
    return !(*this == p);
    }

bool Patient::operator < (const Patient& p) const {
    return socSecNum < p.socSecNum;
    }

bool Patient::operator <= (const Patient& p) const {
    return *this < p or *this == p;
    }

bool Patient::operator > (const Patient& p) const {
    return !(*this <= p);
    }

bool Patient::operator >= (const Patient& p) const {
    return !(*this < p);
    }

istream& operator >> (istream& is, Patient& p) {
    string str;

    getline(is, str, '*'); // read 8576003230-9*

    stringstream strStream(str);

    getline(strStream, str, '-'); // 8576003230
    long firstPart = stol(str);

    getline(strStream, str); // 9
    long lastPart = stol(str);

    p.socSecNum = firstPart*10 + lastPart; // combined

    is >> p.name;

    is >> p.birth;

    is >> p.address;

    getline(is, str, '*'); // read 83 3573 6729*

    stringstream otherss(str);

    getline(otherss, str, ' '); // 83
    firstPart = stol(str);

    getline(otherss, str, ' '); // 3573
    long secondPart = stol(str);

    getline(otherss, str); // 6729
    lastPart = stol(str);

    p.phoneNum = firstPart*100000000 + secondPart*10000 + lastPart;

    return is;
    }

ostream& operator << (ostream& os, const Patient& p) {
    long firstPartSsn = p.socSecNum / 10;
    long lastPartSsn = p.socSecNum % 10;

    os << setfill('0') << setw(10) << firstPartSsn << "-"
       << setfill('0') << setw(1) << lastPartSsn << "*";

    os << p.name;

    os << p.birth;

    os << p.address;

    long firstPartPn = p.phoneNum / 100000000;
    long secondPartPn = (p.phoneNum / 10000) % 100;
    long lastPartPn = p.phoneNum % 10000;

    os << setfill('0') << setw(2) << firstPartPn << " "
       << setfill('0') << setw(4) << secondPartPn << " "
       << setfill('0') << setw(4) << lastPartPn << "*";

    return os;
    }
