#ifndef PATIENTFILE_HPP_INCLUDED
#define PATIENTFILE_HPP_INCLUDED

#include <string>
#include <list>
#include <fstream>

#include "patient.hpp"
#include "name.hpp"
#include "indextuple.hpp"

class PatientFile {
        std::string dataFileName;
        std::string indexBySSNFileName;
        std::string indexByNameFileName;

        std::fstream dataFile;
        std::fstream indexFileBySSN;
        std::fstream indexFileByName;

        std::list<IndexTuple<long>> indexListBySSN;
        std::list<IndexTuple<Name>> indexListByName;

        void reindex();

        template <class T>
        std::list<T> fileToList(const std::fstream&, const std::list<T>&) const;

        template <class T>
        std::fstream listToFile(const std::list<T>&, const std::fstream&) const;

        template <class T>
        int getIndex(const std::list<T>&, const T&) const;

    public:
        PatientFile();

        ~PatientFile();

        void addData(const Patient&);
        void addData(const std::list<Patient>&);

        void deleteData(const int&);

        int findData(const Patient&);
        int findDataBySSN(const long&);
        int findDataByName(const Name&);

        Patient retrieve(const int&);

        std::list<Patient> toList() const;

        void clean();

        void compress();

        void importFromDisk(const std::string&);
        void exportToDisk(const std::string&);
    };

#endif // PATIENTFILE_HPP_INCLUDED
