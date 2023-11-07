#include "medication.hpp"

using std::string, std::istream, std::ostream, std::stringstream, std::setfill,
      std::setw;

Medication::Medication() {}

Medication::Medication(const Medication& m) : code(m.code), name(m.name) {}

Medication& Medication::operator = (const Medication& m) {
    code = m.code;
    name = m.name;

    return *this;
    }

void Medication::setCode(const long& c) {
    code = c;
    }

void Medication::setName(const string& n) {
    name = n;
    }

string Medication::toString() const {
    return std::to_string(code) + " | " + name;
    }

long Medication::getCode() const {
    return code;
    }

string Medication::getName() const {
    return name;
    }

bool Medication::operator == (const Medication& m) const {
    return code == m.code;
    }

bool Medication::operator != (const Medication& m) const {
    return !(*this == m);
    }

bool Medication::operator < (const Medication& m) const {
    return code < m.code;
    }

bool Medication::operator <= (const Medication& m) const {
    return *this < m or *this == m;
    }

bool Medication::operator > (const Medication& m) const {
    return !(*this <= m);
    }

bool Medication::operator >= (const Medication& m) const {
    return !(*this < m);
    }

istream& operator >> (istream& is, Medication& m) {
    string str;
    getline(is, str, '*'); // read 2823-4178*

    stringstream strStream(str);

    getline(strStream, str, '-'); // 2823
    long firstPart = stol(str);

    getline(strStream, str); // 4178
    long lastPart = stol(str);

    m.code = firstPart*10000 + lastPart;

    getline(is, m.name, '*');

    return is;
    }

ostream& operator << (ostream& os, const Medication& m) {
    long firstPart = m.code / 10000;
    long lastPart = m.code % 10000;

    os << setfill('0') << setw(4) << firstPart << "-"
       << setfill('0') << setw(4) << lastPart << "*";

    os << m.name << "*";

    return os;
    }
