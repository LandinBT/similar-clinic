#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED

#include <string>
#include <iostream>

class Name {
    std::string first;
    std::string last;

public:
    Name();
    Name(const Name&);

    Name& operator = (const Name&);

    void setFirst(const std::string&);
    void setLast(const std::string&);

    std::string toString() const;

    std::string getFirst() const;
    std::string getLast() const;

    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator < (const Name&) const;
    bool operator <= (const Name&) const;
    bool operator > (const Name&) const;
    bool operator >= (const Name&) const;

    friend std::istream& operator >> (std::istream&, Name&);
    friend std::ostream& operator << (std::ostream&, const Name&);
};

#endif // NAME_HPP_INCLUDED
