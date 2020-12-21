#include <iostream>
#include <string>
#include <sstream>

#include "TestData.h"
#include "../../../../src/main/cpp/application/Runnable.h"
#include "../../../../src/main/cpp/application/util/Strings.h"

namespace application::util {

    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using application::util::Strings::leftSplitToStringArray;
    using application::model::StringArray;

    void test01() {
        cout << "=== test-01-Strings ===" << endl;

        string str1 = "123 abc 333 xxx";
        StringArray stringArray {leftSplitToStringArray(str1, ' ', 2)};

        if (
                2 == stringArray.size
                && "123" == stringArray.data[0]
                && "abc 333 xxx" == stringArray.data[1]
                ) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------" << endl;
            cout << "stringArray.size = " << stringArray.size << endl;
            cout << "stringArray.data[0] = " << stringArray.data[0] << endl;
            cout << "stringArray.data[1] = " << stringArray.data[1] << endl;
        }

        cout << "=======================" << endl;
    }

}

namespace application {

    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::istringstream;
    using std::ostringstream;

    void successTest01() {
        cout << "=== success-test-01-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::SUCCESS_TEST_01.in;
        expectedResult = TestData::SUCCESS_TEST_01.result;
        expectedOut = TestData::SUCCESS_TEST_01.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "================================" << endl;
    }

    void successTest02() {
        cout << "=== success-test-02-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::SUCCESS_TEST_02.in;
        expectedResult = TestData::SUCCESS_TEST_02.result;
        expectedOut = TestData::SUCCESS_TEST_02.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "================================" << endl;
    }

    void failTest01() {
        cout << "=== fail-test-01-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::FAIL_TEST_01.in;
        expectedResult = TestData::FAIL_TEST_01.result;
        expectedOut = TestData::FAIL_TEST_01.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "=============================" << endl;
    }

    void failTest02() {
        cout << "=== fail-test-02-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::FAIL_TEST_02.in;
        expectedResult = TestData::FAIL_TEST_02.result;
        expectedOut = TestData::FAIL_TEST_02.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "=============================" << endl;
    }

    void failTest03() {
        cout << "=== fail-test-03-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::FAIL_TEST_03.in;
        expectedResult = TestData::FAIL_TEST_03.result;
        expectedOut = TestData::FAIL_TEST_03.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "=============================" << endl;
    }

    void failTest04() {
        cout << "=== fail-test-04-Runnable ===" << endl;

        string in;
        string out;
        string expectedOut;
        string actualOut;

        istringstream inStream;
        ostringstream outStream;

        int result;
        int expectedResult;
        int actualResult;

        in = TestData::FAIL_TEST_04.in;
        expectedResult = TestData::FAIL_TEST_04.result;
        expectedOut = TestData::FAIL_TEST_04.out;

        inStream.str(in);

        result = application::Runnable::run(inStream, outStream);
        out = outStream.str();
        actualResult = result;
        actualOut = out;

        if (expectedResult == actualResult && expectedOut == actualOut) {
            cout << "(" << "PASSED" << ")" << endl;
        } else {
            cout << "(" << "FAILED" << ")" << endl;
            cout << "-----------------------------" << endl;
            cout << "expectedResult:" << endl;
            cout << expectedResult << endl;
            cout << "actualResult:" << endl;
            cout << actualResult << endl;
            cout << "expectedOut:" << endl;
            cout << expectedOut << endl;
            cout << "actualOut:" << endl;
            cout << actualOut << endl;
        }

        cout << "=============================" << endl;
    }

}

int main() {

    application::util::test01();

    application::successTest01();
    application::successTest02();

    application::failTest01();
    application::failTest02();
    application::failTest03();
    application::failTest04();

    return 0;
}
