#ifndef DOCTORFILE_HPP_INCLUDED
#define DOCTORFILE_HPP_INCLUDED

#include <string>
#include <list>
#include <fstream>

#include "doctor.hpp"
#include "name.hpp"
#include "indextuple.hpp"

class DoctorFile {
        std::string dataFileName;
        std::string indexByEmpCodeFileName;
        std::string indexByNameFileName;

        std::fstream dataFile;
        std::fstream indexFileByEmpCode;
        std::fstream indexFileByName;

        std::list<IndexTuple<long>> indexListByEmpCode;
        std::list<IndexTuple<Name>> indexListByName;

        void reindex();

        template <class T>
        std::list<T> fileToList(const std::fstream&, const std::list<T>&) const;

        template <class T>
        std::fstream listToFile(const std::list<T>&, const std::fstream&) const;

        template <class T>
        int getIndex(const std::list<T>&, const T&) const;

    public:
        DoctorFile();

        ~DoctorFile();

        void addData(const Doctor&);
        void addData(const std::list<Doctor>&);

        void deleteData(const int&);

        int findData(const Doctor&);
        int findDataByEmpCode(const long&);
        int findDataByName(const Name&);

        Doctor retrieve(const int&);

        std::list<Doctor> toList() const;

        void clean();

        void compress();

        void importFromDisk(const std::string&);
        void exportToDisk(const std::string&);
    };

#endif // DOCTORFILE_HPP_INCLUDED
