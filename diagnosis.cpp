#include "diagnosis.hpp"

using std::string, std::istream, std::ostream;

Diagnosis::Diagnosis() {}

Diagnosis::Diagnosis(const Diagnosis& d) : code(d.code),
    description(d.description) {}

Diagnosis& Diagnosis::operator = (const Diagnosis& d) {
    code = d.code;
    description = d.description;

    return *this;
    }

void Diagnosis::setCode(const string& c) {
    code = c;
    }

void Diagnosis::setDescription(const string& d) {
    description = d;
    }

string Diagnosis::toString() const {
    return code+'\n'+description;
    }

string Diagnosis::getCode() const {
    return code;
    }

string Diagnosis::getDescription() const {
    return description;
    }

bool Diagnosis::operator == (const Diagnosis& d) const {
    return code == d.code;
    }

bool Diagnosis::operator != (const Diagnosis& d) const {
    return !(*this == d);
    }

bool Diagnosis::operator < (const Diagnosis& d) const {
    return code < d.code;
    }

bool Diagnosis::operator <= (const Diagnosis& d) const {
    return *this < d or *this == d;
    }

bool Diagnosis::operator > (const Diagnosis& d) const {
    return !(*this <= d);
    }

bool Diagnosis::operator >= (const Diagnosis& d) const {
    return !(*this < d);
    }

istream& operator >> (istream& is, Diagnosis& d) {
    getline(is, d.code, '*');
    getline(is, d.description, '*');

    return is;
    }

ostream& operator << (ostream& os, const Diagnosis& d) {
    return os << d.code << "*" << d.description << "*";
    }
