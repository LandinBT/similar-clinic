#include "name.hpp"

using std::string, std::istream, std::ostream;

Name::Name() {}

Name::Name(const Name& n) : first(n.first), last(n.last) {}

Name& Name::operator = (const Name& n) {
    first = n.first;
    last = n.last;

    return *this;
    }

void Name::setFirst(const string& f) {
    first = f;
    }

void Name::setLast(const string& l) {
    last = l;
    }

string Name::toString() const {
    return last+", "+first;
    }

string Name::getFirst() const {
    return first;
    }

string Name::getLast() const {
    return last;
    }

bool Name::operator == (const Name& n) const {
    return toString() == n.toString();
    }

bool Name::operator != (const Name& n) const {
    return !(*this == n);
    }

bool Name::operator < (const Name& n) const {
    return toString() < n.toString();
    }

bool Name::operator <= (const Name& n) const {
    return *this < n or *this == n;
    }

bool Name::operator > (const Name& n) const {
    return !(*this <= n);
    }

bool Name::operator >= (const Name& n) const {
    return !(*this < n);
    }

istream& operator >> (istream& is, Name& n) {
    getline(is, n.last, '*');
    getline(is, n.first, '*');

    return is;
    }

ostream& operator << (ostream& os, const Name& n) {
    return os << n.last << "*" << n.first << "*";
    }
