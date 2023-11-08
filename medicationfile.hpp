#ifndef MEDICATIONFILE_HPP_INCLUDED
#define MEDICATIONFILE_HPP_INCLUDED

#include <string>
#include <list>
#include <fstream>

#include "medication.hpp"
#include "indextuple.hpp"

class MedicationFile {
    std::string dataFileName;
    std::string indexByCodeFileName;

    std::fstream dataFile;
    std::fstream indexFileByCode;

    std::list<IndexTuple<long>> indexListByCode;

    void reindex();

    template <class T>
    std::list<T> fileToList(const std::fstream&, const std::list<T>&) const;

    template <class T>
    std::fstream listToFile(const std::list<T>&, const std::fstream&) const;

    template <class T>
    int getIndex(const std::list<T>&, const T&) const;

public:
    MedicationFile();

    ~MedicationFile();

    void addData(const Medication&);
    void addData(const std::list<Medication>&);

    void deleteData(const int&);

    int findData(const Medication&);
    int findDataByCode(const long&);

    Medication retrieve(const int&);

    std::list<Medication> toList() const;

    void clean();

    void compress();

    void importFromDisk(const std::string&);
    void exportToDisk(const std::string&);
};

#endif // MEDICATIONFILE_HPP_INCLUDED
