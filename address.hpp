#ifndef ADDRESS_HPP_INCLUDED
#define ADDRESS_HPP_INCLUDED

#include <string>
#include <iostream>

class Address {
    std::string street;
    int houseNum; // house number
    std::string colony;
    int zipCode;
    std::string locality;

public:
    Address();
    Address(const Address&);

    Address& operator = (const Address&);

    void setStreet(const std::string&);
    void setHouseNum(const int&);
    void setColony(const std::string&);
    void setZipCode(const int&);
    void setLocality(const std::string&);

    std::string toString() const;

    std::string getStreet() const;
    int getHouseNum() const;
    std::string setColony() const;
    int getZipCode() const;
    std::string getLocality() const;

    bool operator == (const Address&) const;
    bool operator != (const Address&) const;
    bool operator < (const Address&) const;
    bool operator <= (const Address&) const;
    bool operator > (const Address&) const;
    bool operator >= (const Address&) const;

    friend std::istream& operator >> (std::istream&, Address&);
    friend std::ostream& operator << (std::ostream&, const Address&);
};

#endif // ADDRESS_HPP_INCLUDED
