#ifndef DATA_H
#define DATA_H

#include <string>

namespace application::TestData {

    using std::string;

    struct TestCase {
        string in;
        string out;
        int result;
    };

    const TestCase SUCCESS_TEST_01 = {
            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123 Alex Thornton\n"
            "234 Boo Thornton\n"
            "345 Jane Student\n"
            "456 Joe Student\n"
            "567 Too-Many Courses\n"
            "5\n"
            "345 14 14 14 14 14 45 45\n"
            "123 13 10 8 14 12 50 37\n"
            "456 12 9 15 13 11 38 26\n"
            "234 15 15 15 15 15 50 50\n"
            "567 8 4 0 10 0 24 12\n"
            "3\n"
            "90.0 80.0 70.0 60.0\n"
            "85.0 75.0 65.0 55.0\n"
            "80.0 70.0 60.0 50.0",

            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123 Alex Thornton\n"
            "234 Boo Thornton\n"
            "345 Jane Student\n"
            "456 Joe Student\n"
            "567 Too-Many Courses\n"
            "5\n"
            "345 14 14 14 14 14 45 45\n"
            "123 13 10 8 14 12 50 37\n"
            "456 12 9 15 13 11 38 26\n"
            "234 15 15 15 15 15 50 50\n"
            "567 8 4 0 10 0 24 12\n"
            "TOTAL SCORES\n"
            "123 Alex Thornton 79.1\n"
            "234 Boo Thornton 100\n"
            "345 Jane Student 92\n"
            "456 Joe Student 72.4\n"
            "567 Too-Many Courses 30.8\n"
            "3\n"
            "90.0 80.0 70.0 60.0\n"
            "CUTPOINT SET 1\n"
            "123 Alex Thornton C\n"
            "234 Boo Thornton A\n"
            "345 Jane Student A\n"
            "456 Joe Student C\n"
            "567 Too-Many Courses F\n"
            "85.0 75.0 65.0 55.0\n"
            "CUTPOINT SET 2\n"
            "123 Alex Thornton B\n"
            "234 Boo Thornton A\n"
            "345 Jane Student A\n"
            "456 Joe Student C\n"
            "567 Too-Many Courses F\n"
            "80.0 70.0 60.0 50.0\n"
            "CUTPOINT SET 3\n"
            "123 Alex Thornton B\n"
            "234 Boo Thornton A\n"
            "345 Jane Student A\n"
            "456 Joe Student B\n"
            "567 Too-Many Courses F\n",

            0
    };

    const TestCase SUCCESS_TEST_02 = {
            "3\n"
            "30 50 100\n"
            "16 24 32\n"
            "2\n"
            "1 Student 1\n"
            "2 Student 2\n"
            "2\n"
            "1 30 50 100\n"
            "2 29 49 80\n"
            "2\n"
            "60.0 50.0 40.0 30.0\n"
            "65.0 55.0 45.0 35.0",

            "3\n"
            "30 50 100\n"
            "16 24 32\n"
            "2\n"
            "1 Student 1\n"
            "2 Student 2\n"
            "2\n"
            "1 30 50 100\n"
            "2 29 49 80\n"
            "TOTAL SCORES\n"
            "1 Student 1 72\n"
            "2 Student 2 64.5867\n"
            "2\n"
            "60.0 50.0 40.0 30.0\n"
            "CUTPOINT SET 1\n"
            "1 Student 1 A\n"
            "2 Student 2 A\n"
            "65.0 55.0 45.0 35.0\n"
            "CUTPOINT SET 2\n"
            "1 Student 1 A\n"
            "2 Student 2 B\n",

            0
    };

    const TestCase FAIL_TEST_01 = {
            "7\n"
            "15 15 15 15 15 50 50",

            "7\n"
            "15 15 15 15 15 50 50\n"
            "Error in line: 3 (stoi)\n",

            1
    };

    const TestCase FAIL_TEST_02 = {
            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15\n"
            "5",

            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15\n"
            "Error in line: 3 (Wrong number of weights expected 7 actual 6)\n",

            1
    };

    const TestCase FAIL_TEST_03 = {
            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123_Alex_Thornton\n"
            "...",

            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123_Alex_Thornton\n"
            "Error in line: 5 (Wrong format!)\n",

            1
    };

    const TestCase FAIL_TEST_04 = {
            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123 Alex Thornton\n"
            "234 Boo Thornton\n"
            "456 Joe Student\n"
            "567 Too-Many Courses\n"
            "5\n"
            "...",

            "7\n"
            "15 15 15 15 15 50 50\n"
            "12 12 12 12 12 15 25\n"
            "5\n"
            "123 Alex Thornton\n"
            "234 Boo Thornton\n"
            "456 Joe Student\n"
            "567 Too-Many Courses\n"
            "5\n"
            "Error in line: 9 (Wrong format!)\n",

            1
    };

}

#endif // DATA_H
