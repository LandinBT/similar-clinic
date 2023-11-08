#ifndef DIAGNOSISFILE_HPP_INCLUDED
#define DIAGNOSISFILE_HPP_INCLUDED

#include <string>
#include <list>
#include <fstream>

#include "diagnosis.hpp"
#include "indextuple.hpp"

class DiagnosisFile {
    std::string dataFileName;
    std::string indexByCodeFileName;

    std::fstream dataFile;
    std::fstream indexFileByCode;

    std::list<IndexTuple<>> indexListByCode;

    void reindex();

    template <class T>
    std::list<T> fileToList(const std::fstream&, const std::list<T>&) const;

    template <class T>
    std::fstream listToFile(const std::list<T>&, const std::fstream&) const;

    template <class T>
    int getIndex(const std::list<T>&, const T&) const;

public:
    DiagnosisFile();

    ~DiagnosisFile();

    void addData(const Diagnosis&);
    void addData(const std::list<Diagnosis>&);

    void deleteData(const int&);

    int findData(const Diagnosis&);
    int findDataByCode(const std::string&);

    Diagnosis retrieve(const int&);

    std::list<Diagnosis> toList() const;

    void clean();

    void compress();

    void importFromDisk(const std::string&);
    void exportToDisk(const std::string&);
};

#endif // DIAGNOSISFILE_HPP_INCLUDED
