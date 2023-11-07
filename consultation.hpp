#ifndef CONSULTATION_HPP_INCLUDED
#define CONSULTATION_HPP_INCLUDED

#include <string>
#include <iostream>

#include "date.hpp"
#include "time.hpp"
#include "diagnosis.hpp"
#include "doctor.hpp"
#include "patient.hpp"
#include "medication.hpp"

class Consultation {
    Date date;
    Time time;
    std::string diagnosisCode;
    std::string therapIndic; // therapeutic indications
    long doctorEmpCode;
    long patientSsN;
    long firstMedCode; // first medication
    long secondMedCode; // second medication
    long thirdMedCode; // third medication

public:
    Consultation();
    Consultation(const Consultation&);

    Consultation& operator = (const Consultation&);

    void setDate(const Date&);
    void setTime(const Time&);
    void setDiagnosisCode(const std::string&);
    void setTherapIndic(const std::string&);
    void setDoctorEmpCode(const long&);
    void setPatientSsN(const long&);
    void setFirstMedCode(const long&);
    void setSecondMedCode(const long&);
    void setThirdMedCode(const long&);

    std::string toString() const;

    Date getDate() const;
    Time getTime() const;
    std::string getDiagnosisCode() const;
    std::string getTherapIndic() const;
    long getDoctorEmpCode() const;
    long getPatientSsN() const;
    long getFirstMedCode() const;
    long getSecondMedCode() const;
    long getThirdMedCode() const;

    bool operator == (const Consultation&) const;
    bool operator != (const Consultation&) const;
    bool operator < (const Consultation&) const;
    bool operator <= (const Consultation&) const;
    bool operator > (const Consultation&) const;
    bool operator >= (const Consultation&) const;

    friend std::istream& operator >> (std::istream&, Consultation&);
    friend std::ostream& operator << (std::ostream&, const Consultation&);
};

#endif // CONSULTATION_HPP_INCLUDED
