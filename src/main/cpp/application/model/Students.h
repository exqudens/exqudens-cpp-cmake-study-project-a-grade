#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>

namespace application::model {

    using std::string;

    struct Student;

    struct Students {
        int size;
        Student* data;
    };

}

#endif // STUDENTS_H
