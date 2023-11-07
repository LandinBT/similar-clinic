#include "consultation.hpp"

using std::string, std::istream, std::ostream, std::stringstream, std::setfill,
      std::setw;

Consultation::Consultation() {}

Consultation::Consultation(const Consultation& c) : date(c.date), time(c.time),
    diagnosisCode(c.diagnosisCode), therapIndic(c.therapIndic),
    doctorEmpCode(c.doctorEmpCode), patientSsN(c.patientSsN),
    firstMedCode(c.firstMedCode), secondMedCode(c.secondMedCode),
    thirdMedCode(c.thirdMedCode) {}

Consultation& Consultation::operator = (const Consultation& c) {
    date = c.date;
    time = c.time;
    diagnosisCode = c.diagnosisCode;
    therapIndic = c.therapIndic;
    doctorEmpCode = c.doctorEmpCode;
    patientSsN = c.patientSsN;
    firstMedCode = c.firstMedCode;
    secondMedCode = c.secondMedCode;
    thirdMedCode = c.thirdMedCode;

    return *this;
    }

void Consultation::setDate(const Date& d) {
    date = d;
    }

void Consultation::setTime(const Time& t) {
    time = t;
    }

void Consultation::setDiagnosisCode(const string& c) {
    diagnosisCode = c;
    }

void Consultation::setTherapIndic(const string& i) {
    therapIndic = i;
    }

void Consultation::setDoctorEmpCode(const long& c) {
    doctorEmpCode = c;
    }

void Consultation::setPatientSsN(const long& n) {
    patientSsN = n;
    }

void Consultation::setFirstMedCode(const long& c) {
    firstMedCode = c;
    }

void Consultation::setSecondMedCode(const long& c) {
    secondMedCode = c;
    }

void Consultation::setThirdMedCode(const long& c) {
    thirdMedCode = c;
    }

string Consultation::toString() const {
    return date.toString() + '\n' +
           time.toString() + '\n' +
           diagnosisCode + '\n' +
           therapIndic + '\n' +
           std::to_string(doctorEmpCode) + '\n' +
           std::to_string(patientSsN) + '\n' +
           std::to_string(firstMedCode) + '\n' +
           std::to_string(secondMedCode) + '\n' +
           std::to_string(thirdMedCode);
    }

Date Consultation::getDate() const {
    return date;
    }

Time Consultation::getTime() const {
    return time;
    }

string Consultation::getDiagnosisCode() const {
    return diagnosisCode;
    }

string Consultation::getTherapIndic() const {
    return therapIndic;
    }

long Consultation::getDoctorEmpCode() const {
    return doctorEmpCode;
    }

long Consultation::getPatientSsN() const {
    return patientSsN;
    }

long Consultation::getFirstMedCode() const {
    return firstMedCode;
    }

long Consultation::getSecondMedCode() const {
    return secondMedCode;
    }

long Consultation::getThirdMedCode() const {
    return thirdMedCode;
    }

bool Consultation::operator == (const Consultation& c) const {
    return therapIndic == c.therapIndic;
    }

bool Consultation::operator != (const Consultation& c) const {
    return !(*this == c);
    }

bool Consultation::operator < (const Consultation& c) const {
    return therapIndic < c.therapIndic;
    }

bool Consultation::operator <= (const Consultation& c) const {
    return *this < c or *this == c;
    }

bool Consultation::operator > (const Consultation& c) const {
    return !(*this <= c);
    }

bool Consultation::operator >= (const Consultation& c) const {
    return !(*this < c);
    }

istream& operator >> (istream& is, Consultation& c) {
    is >> c.date;

    is >> c.time;

    getline(is, c.diagnosisCode, '*');

    getline(is, c.therapIndic, '*');

    // read doctor employee code
    string str;
    getline(is, str, '*');

    stringstream ssd(str); // stringstream doctor

    getline(ssd, str, '-');
    long fpd = stol(str); // first part doctor

    getline(ssd, str);
    long lpd = stol(str); // last part doctor

    c.doctorEmpCode = fpd*10000000 + lpd;

    // read patient social security number
    getline(is, str, '*');
    stringstream ssp(str); // stringstream patient

    getline(ssp, str, '-');
    long fpp = stol(str); // first part patient

    getline(ssp, str);
    long lpp = stol(str); // last part patient

    c.patientSsN = fpp*10 + lpp; // combined

    // read first medication code
    getline(is, str, '*');
    stringstream ssfm(str); // stringstream first medictaion

    getline(ssfm, str, '-');
    long fpm = stol(str); // first part medication

    getline(ssfm, str);
    long lpm = stol(str); // second part medication

    c.firstMedCode = fpm*10000 + lpm;

    // read second medication code
    getline(is, str, '*');
    stringstream sssm(str); // stringstream second medictaion

    getline(sssm, str, '-');
    fpm = stol(str);

    getline(sssm, str);
    lpm = stol(str);

    c.secondMedCode = fpm*10000 + lpm;

    // read third medication code
    getline(is, str, '#');
    stringstream sstm(str); // stringstream third medictaion

    getline(sstm, str, '-');
    fpm = stol(str);

    getline(sstm, str);
    lpm = stol(str);

    c.thirdMedCode = fpm*10000 + lpm;

    return is;
    }

ostream& operator << (ostream& os, const Consultation& c) {
    os << c.date;

    os << c.time;

    os << c.diagnosisCode << "*";

    os << c.therapIndic << "*";

    // doctor
    long fpd = c.doctorEmpCode / 10000000; // first part doctor
    long lpd = c.doctorEmpCode % 10000000; // last part doctor

    os << setfill('0') << setw(2) << fpd << "-"
       << setfill('0') << setw(7) << lpd << "*";

    // patient
    long fpp = c.patientSsN / 10; // first part patient
    long lpp = c.patientSsN % 10; // last part patient

    os << setfill('0') << setw(10) << fpp << "-"
       << setfill('0') << setw(1) << lpp << "*";

    // first medication
    long fpm = c.firstMedCode / 10000; // first part medication
    long lpm = c.firstMedCode % 10000; // last part medication

    os << setfill('0') << setw(4) << fpm << "-"
       << setfill('0') << setw(4) << lpm << "*";

    // second medication
    fpm = c.secondMedCode / 10000;
    lpm = c.secondMedCode % 10000;

    os << setfill('0') << setw(4) << fpm << "-"
       << setfill('0') << setw(4) << lpm << "*";

    // third medication
    fpm = c.thirdMedCode / 10000;
    lpm = c.thirdMedCode % 10000;

    os << setfill('0') << setw(4) << fpm << "-"
       << setfill('0') << setw(4) << lpm << "#";

    return os;
    }
