#ifndef MEDICATION_HPP_INCLUDED
#define MEDICATION_HPP_INCLUDED

#include <string>
#include <iostream>

class Medication {
    long code;
    std::string name;

public:
    Medication();
    Medication(const Medication&);

    Medication& operator = (const Medication&);

    void setCode(const long&);
    void setName(const std::string&);

    std::string toString() const;

    long getCode() const;
    std::string getName() const;

    bool operator == (const Medication&) const;
    bool operator != (const Medication&) const;
    bool operator < (const Medication&) const;
    bool operator <= (const Medication&) const;
    bool operator > (const Medication&) const;
    bool operator >= (const Medication&) const;

    friend std::istream& operator >> (std::istream&, Medication&);
    friend std::ostream& operator << (std::ostream&, const Medication&);
};

#endif // MEDICATION_HPP_INCLUDED
