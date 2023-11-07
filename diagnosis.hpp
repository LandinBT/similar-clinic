#ifndef DIAGNOSIS_HPP_INCLUDED
#define DIAGNOSIS_HPP_INCLUDED

#include <string>
#include <iostream>

class Diagnosis {
    std::string code;
    std::string description;

public:
    Diagnosis();
    Diagnosis(const Diagnosis&);

    Diagnosis& operator = (const Diagnosis&);

    void setCode(const std::string&);
    void setDescription(const std::string&);

    std::string toString() const;

    std::string getCode() const;
    std::string getDescription() const;

    bool operator == (const Diagnosis&) const;
    bool operator != (const Diagnosis&) const;
    bool operator < (const Diagnosis&) const;
    bool operator <= (const Diagnosis&) const;
    bool operator > (const Diagnosis&) const;
    bool operator >= (const Diagnosis&) const;

    friend std::istream& operator >> (std::istream&, Diagnosis&);
    friend std::ostream& operator << (std::ostream&, const Diagnosis&);
};

#endif // DIAGNOSIS_HPP_INCLUDED
