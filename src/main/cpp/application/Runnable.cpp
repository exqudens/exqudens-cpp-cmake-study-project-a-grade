#include <fstream>

#include "model/GradedArtifact.h"
#include "model/GradedArtifacts.h"
#include "model/Student.h"
#include "model/Students.h"
#include "util/Strings.h"
#include "Runnable.h"

namespace application::Runnable {

    using std::exception;
    using std::runtime_error;
    using std::string;
    using std::istream;
    using std::ostream;
    using std::cin;
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::stoi;
    using std::to_string;
    using std::ifstream;
    using std::ofstream;
    using application::model::StringArray;
    using application::model::IntArray;
    using application::model::DoubleArray;
    using application::model::GradedArtifact;
    using application::model::GradedArtifacts;
    using application::model::Student;
    using application::model::Students;
    using application::util::Strings::trim;
    using application::util::Strings::splitToStringArray;
    using application::util::Strings::splitToIntArray;
    using application::util::Strings::splitToDoubleArray;

    int run(int argc, char *argv[]);
    int run(istream &in, ostream &out);

    GradedArtifacts readGradedArtifacts(istream &in, ostream &out, int &lineNumber);
    Students readStudents(istream &in, ostream &out, int &lineNumber);
    void fillScores(
            istream &in,
            ostream &out,
            int &lineNumber,
            GradedArtifacts gradedArtifacts,
            Students students
    );
    void processCutPoints(
            istream &in,
            ostream &out,
            int &lineNumber,
            Students students
    );

    int findStudentIndex(int id, Students& students);
    double calc(int max, int weight, int actual);

    int run(int argc, char *argv[]) {
        int result = 1;

        if (argc == 1) {

            istream &in = cin;
            ostream &out = cout;
            result = run(in, out);

        } else if (argc == 3) {

            string inPath = string(argv[1]);
            string outPath = string(argv[2]);
            ifstream inFile;
            ofstream outFile;

            inFile.open(inPath);
            outFile.open(outPath);

            if (!inFile.is_open()) {
                cerr << "File error '" << inPath << "'! (file not opened)" << endl;
            } else if (!outFile.is_open()) {
                cerr << "File error '" << outPath << "'! (file not opened)" << endl;
            } else {
                istream &in = inFile;
                ostream &out = outFile;
                result = run(in, out);
            }

            if (inFile.is_open()) {
                inFile.close();
            }
            if (outFile.is_open()) {
                outFile.close();
            }

        } else {

            cerr << "Usage: " << argv[0] << " path-to-input-file path-to-output-file" << endl;
            cerr << "Usage: " << argv[0] << " < path-to-input-file > path-to-output-file" << endl;

        }

        return result;
    }

    int run(istream &in, ostream &out) {
        int lineNumber;

        try {
            lineNumber = 1;

            GradedArtifacts gradedArtifacts {readGradedArtifacts(in, out, lineNumber)};
            Students students {readStudents(in, out, lineNumber)};
            fillScores(in, out, lineNumber, gradedArtifacts, students);

            delete [] gradedArtifacts.data;

            out << "TOTAL SCORES" << endl;
            for (int i = 0; i < students.size; i++) {
                out << students.data[i].id << " " << students.data[i].fullName << " " << students.data[i].totalScore << endl;
            }

            processCutPoints(in, out, lineNumber, students);

            delete [] students.data;

            return 0;
        } catch (exception& e) {
            out << "Error in line: " << lineNumber << " (" << e.what() << ")" << endl;
            return 1;
        }
    }

    GradedArtifacts readGradedArtifacts(istream &in, ostream &out, int &lineNumber) {
        string line;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        int size = stoi(trim(line));
        line.erase();
        lineNumber++;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        IntArray points {splitToIntArray(trim(line), ' ')};
        if (size != points.size) {
            string m = "";
            m += "Wrong number of points expected ";
            m += to_string(size);
            m += " actual ";
            m += points.size;
            throw runtime_error(m);
        }
        line.erase();
        lineNumber++;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        IntArray weights {splitToIntArray(trim(line), ' ')};
        if (size != weights.size) {
            string m = "";
            m += "Wrong number of weights expected ";
            m += to_string(size);
            m += " actual ";
            m += to_string(weights.size);
            throw runtime_error(m);
        }
        line.erase();
        lineNumber++;

        GradedArtifact* data = new GradedArtifact[size];
        for (int i = 0; i < size; i++) {
            data[i] = {points.data[i], weights.data[i]};
        }

        GradedArtifacts gradedArtifacts {size, data};

        delete [] points.data;
        delete [] weights.data;

        return gradedArtifacts;
    }

    Students readStudents(istream &in, ostream &out, int &lineNumber) {
        string line;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        int size = stoi(trim(line));
        line.erase();
        lineNumber++;

        Student* data = new Student[size];
        for (int i = 0; i < size; i++) {
            getline(in, line);
            if (!line.empty()) {
                out << line << endl;
            }

            int firstIndexOfSpace = line.find_first_of(' ');

            if (firstIndexOfSpace == -1 || firstIndexOfSpace + 1 >= line.size()) {
                string m = "";
                m += "Wrong format!";
                throw runtime_error(m);
            }

            string column1 = line.substr(0, firstIndexOfSpace);
            string column2 = line.substr(firstIndexOfSpace + 1, line.size() - 1);

            data[i] = {stoi(trim(column1)), column2};

            line.erase();
            lineNumber++;
        }

        Students students {size, data};

        return students;
    }

    void fillScores(
            istream &in,
            ostream &out,
            int &lineNumber,
            GradedArtifacts gradedArtifacts,
            Students students
    ) {
        string line;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        int size = stoi(trim(line));
        line.erase();
        lineNumber++;

        if (students.size != size) {
            cerr << "Wrong number of raw scores expected(" << students.size << ") actual(" << size << ") ! (lineNumber: " << lineNumber << ")" << endl;
        }

        for (int i = 0; i < size; i++) {
            getline(in, line);
            if (!line.empty()) {
                out << line << endl;
            }

            int firstIndexOfSpace = line.find_first_of(' ');

            if (firstIndexOfSpace == -1 || firstIndexOfSpace + 1 >= line.size()) {
                cerr << "Wrong format! (lineNumber: " << lineNumber << ")" << endl;
                throw 1;
            }

            string column1 = line.substr(0, firstIndexOfSpace);
            string column2 = line.substr(firstIndexOfSpace + 1, line.size() - 1);

            int id = stoi(trim(column1));
            int studentIndex = findStudentIndex(id, students);

            if (studentIndex == -1) {
                cerr << "Cant find existing student with id(" << id << ")! (lineNumber: " << lineNumber << ")" << endl;
                throw 1;
            }

            IntArray rawScores {splitToIntArray(trim(column2), ' ')};

            if (gradedArtifacts.size != rawScores.size) {
                cerr << "Wrong number of graded artifacts expected(" << gradedArtifacts.size << ") actual(" << rawScores.size << ") ! (lineNumber: " << lineNumber << ")" << endl;
                throw 1;
            }

            double totalScore = 0.0;
            for (int x = 0; x < rawScores.size; x++) {
                double score = calc(
                        gradedArtifacts.data[x].points,
                        gradedArtifacts.data[x].weight,
                        rawScores.data[x]
                );
                totalScore += score;
            }

            delete [] rawScores.data;

            students.data[studentIndex].totalScore = totalScore;

            line.erase();
            lineNumber++;
        }
    }

    void processCutPoints(
            istream &in,
            ostream &out,
            int &lineNumber,
            Students students
    ) {
        string line;

        getline(in, line);
        if (!line.empty()) {
            out << line << endl;
        }
        int size = stoi(trim(line));
        line.erase();
        lineNumber++;

        for (int i = 0; i < size; i++) {
            getline(in, line);
            if (!line.empty()) {
                out << line << endl;
            }

            DoubleArray cutPoints {splitToDoubleArray(trim(line), ' ')};

            if (4 != cutPoints.size) {
                cerr << "Wrong number of cut points expected(" << 4 << ") actual(" << cutPoints.size << ") ! (lineNumber: " << lineNumber << ")" << endl;
                throw 1;
            }

            out << "CUTPOINT SET " << (i + 1) << endl;
            for (int x = 0; x < students.size; x++) {

                if (students.data[x].totalScore >= cutPoints.data[0]) {
                    out << students.data[x].id << " " << students.data[x].fullName << " A" << endl;
                } else if (students.data[x].totalScore >= cutPoints.data[1]) {
                    out << students.data[x].id << " " << students.data[x].fullName << " B" << endl;
                } else if (students.data[x].totalScore >= cutPoints.data[2]) {
                    out << students.data[x].id << " " << students.data[x].fullName << " C" << endl;
                } else if (students.data[x].totalScore >= cutPoints.data[3]) {
                    out << students.data[x].id << " " << students.data[x].fullName << " D" << endl;
                } else {
                    out << students.data[x].id << " " << students.data[x].fullName << " F" << endl;
                }

            }

            line.erase();
            lineNumber++;

        }

    }

    int findStudentIndex(int id, Students& students) {
        for (int i = 0; i < students.size; i++) {
            if (id == students.data[i].id) {
                return i;
            }
        }
        return -1;
    }

    double calc(int max, int weight, int actual) {
        return ((double) actual / (double) max) * (double) weight;
    }

}
