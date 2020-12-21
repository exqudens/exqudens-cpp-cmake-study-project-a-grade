#ifndef STUDENT_H
#define STUDENT_H

#include <string>

namespace application::model {

    using std::string;

    struct Student {
        int id;
        string fullName;
        double totalScore;
    };

}

#endif // STUDENT_H
