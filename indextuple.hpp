#ifndef INDEXTUPLE_HPP_INCLUDED
#define INDEXTUPLE_HPP_INCLUDED

#include <string>
#include <iostream>

template <class T = std::string>
class IndexTuple {
    int index;
    T data;

public:
    IndexTuple();
    IndexTuple(const IndexTuple&);
    IndexTuple(const int&, const T&); // index, data
    IndexTuple(const T&); // data

    IndexTuple& operator = (const IndexTuple&);
    IndexTuple& operator = (const T&); // data

    void setIndex(const int&);
    void setData(const T&);

    int getIndex() const;
    T getData() const;

    bool operator == (const IndexTuple&) const;
    bool operator != (const IndexTuple&) const;
    bool operator < (const IndexTuple&) const;
    bool operator <= (const IndexTuple&) const;
    bool operator > (const IndexTuple&) const;
    bool operator >= (const IndexTuple&) const;

    template <class U>
    friend std::istream& operator >> (std::istream&, IndexTuple<U>&);

    template <class U>
    friend std::ostream& operator << (std::ostream&, const IndexTuple<U>&);
};

#endif // INDEXTUPLE_HPP_INCLUDED
