#ifndef PATIENT_HPP_INCLUDED
#define PATIENT_HPP_INCLUDED

#include <string>
#include <iostream>

#include "name.hpp"
#include "date.hpp"
#include "address.hpp"

class Patient {
    long socSecNum; // social security number
    Name name;
    Date birth;
    Address address;
    long phoneNum; // phone number

public:
    Patient();
    Patient(const Patient&);

    Patient& operator = (const Patient&);

    void setSocSecNum(const long&);
    void setName(const Name&);
    void setBirth(const Date&);
    void setAddress(const Address&);
    void setPhoneNum(const long&);

    std::string toString() const;

    long setSocSecNum() const;
    Name setName() const;
    Date setBirth() const;
    Address setAddress() const;
    long setPhoneNum() const;

    bool operator == (const Patient&) const;
    bool operator != (const Patient&) const;
    bool operator < (const Patient&) const;
    bool operator <= (const Patient&) const;
    bool operator > (const Patient&) const;
    bool operator >= (const Patient&) const;

    friend std::istream& operator >> (std::istream&, Patient&);
    friend std::ostream& operator << (std::ostream&, const Patient&);
};

#endif // PATIENT_HPP_INCLUDED
