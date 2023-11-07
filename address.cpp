#include "address.hpp"

using std::string, std::istream, std::ostream;

Address::Address() {}

Address::Address(const Address& a) : street(a.street), houseNum(a.houseNum),
    colony(a.colony), zipCode(a.zipCode), locality(a.locality) {}

Address& Address::operator = (const Address& a) {
    street = a.street;
    houseNum = a.houseNum;
    colony = a.colony;
    zipCode = a.zipCode;
    locality = a.locality;

    return *this;
    }

void Address::setStreet(const string& s) {
    street = s;
    }

void Address::setHouseNum(const int& n) {
    houseNum = n;
    }

void Address::setColony(const string& c) {
    colony = c;
    }

void Address::setZipCode(const int& c) {
    zipCode = c;
    }

void Address::setLocality(const string& l) {
    locality = l;
    }

string Address::toString() const {
    return street + " " + std::to_string(houseNum) + ", " + colony + ", " +
           std::to_string(zipCode) + " " + locality;
    }

string Address::getStreet() const {
    return street;
    }

int Address::getHouseNum() const {
    return houseNum;
    }

string Address::setColony() const {
    return colony;
    }

int Address::getZipCode() const {
    return zipCode;
    }

string Address::getLocality() const {
    return locality;
    }

bool Address::operator == (const Address& a) const {
    return toString() == a.toString();
    }

bool Address::operator != (const Address& a) const {
    return !(*this == a);
    }

bool Address::operator < (const Address& a) const {
    return toString() < a.toString();
    }

bool Address::operator <= (const Address& a) const {
    return *this < a or *this == a;
    }

bool Address::operator > (const Address& a) const {
    return !(*this <= a);
    }

bool Address::operator >= (const Address& a) const {
    return !(*this < a);
    }

istream& operator >> (istream& is, Address& a) {
    getline(is, a.street, '*'); // read street

    string str;

    getline(is, str, '*'); // read house number
    a.houseNum = stoi(str);

    getline(is, a.colony, '*'); // read colony

    getline(is, str, '*'); // read zip code
    a.zipCode = stoi(str);

    getline(is, a.locality, '*'); // read locality

    return is;
    }

ostream& operator << (ostream& os, const Address& a) {
    return os << a.street << "*" << a.houseNum << "*" << a.colony << "*"
           << a.zipCode << "*" << a.locality << "*";
    }
