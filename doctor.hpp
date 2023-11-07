#ifndef DOCTOR_HPP_INCLUDED
#define DOCTOR_HPP_INCLUDED

#include <string>
#include <iostream>

#include "name.hpp"
#include "time.hpp"

class Doctor {
    long empCode; // employee code
    Name name;
    long license;
    Time arrival;
    Time departure;

public:
    Doctor();
    Doctor(const Doctor&);

    Doctor& operator = (const Doctor&);

    void setEmpCode(const long&);
    void setName(const Name&);
    void setLicense(const long&);
    void setArrival(const Time&);
    void setDeparture(const Time&);

    std::string toString() const;

    long getEmpCode() const;
    Name getName() const;
    long getLicense() const;
    Time getArrival() const;
    Time getDeparture() const;

    bool operator == (const Doctor&) const;
    bool operator != (const Doctor&) const;
    bool operator < (const Doctor&) const;
    bool operator <= (const Doctor&) const;
    bool operator > (const Doctor&) const;
    bool operator >= (const Doctor&) const;

    friend std::istream& operator >> (std::istream&, Doctor&);
    friend std::ostream& operator << (std::ostream&, const Doctor&);
};

#endif // DOCTOR_HPP_INCLUDED
