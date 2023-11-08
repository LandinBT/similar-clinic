#ifndef CONSULTATIONFILE_HPP_INCLUDED
#define CONSULTATIONFILE_HPP_INCLUDED

#include <string>
#include <list>
#include <fstream>

#include "consultation.hpp"
#include "indextuple.hpp"

class ConsultationFile {
        std::string dataFileName;

        std::fstream dataFile;

        void reindex();

        template <class T>
        std::list<T> fileToList(const std::fstream&, const std::list<T>&) const;

        template <class T>
        std::fstream listToFile(const std::list<T>&, const std::fstream&) const;

        template <class T>
        int getIndex(const std::list<T>&, const T&) const;

    public:
        ConsultationFile();

        ~ConsultationFile();

        void addData(const Consultation&);
        void addData(const std::list<Consultation>&);

        void deleteData(const int&);

        int findData(const Consultation&);
        int findDataByTherapIndic(const std::string&);

        Consultation retrieve(const int&);

        std::list<Consultation> toList() const;

        void clean();

        void compress();

        void importFromDisk(const std::string&);
        void exportToDisk(const std::string&);
    };

#endif // CONSULTATIONFILE_HPP_INCLUDED
