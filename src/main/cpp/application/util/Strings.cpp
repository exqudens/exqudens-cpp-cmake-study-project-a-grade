#include "Strings.h"

namespace application::util::Strings {

    using std::stoi;
    using std::stod;

    const string WHITE_SPACES = " \n\r\t\f\v";

    string leftTrim(string str) {
        int start = str.find_first_not_of(WHITE_SPACES);
        return start == -1 ? "" : str.substr(start);
    }

    string rightTrim(string str) {
        int end = str.find_last_not_of(WHITE_SPACES);
        return end == -1 ? "" : str.substr(0, end + 1);
    }

    string trim(string str) {
        return leftTrim(rightTrim(str));
    }

    StringArray leftSplitToStringArray(string str, char delim, int limit) {
        int startSize;
        int size;
        string* tmp1;
        string* tmp2;
        int index;
        string line;
        string* data;

        startSize = 10;
        size = startSize;
        tmp1 = new string[size];
        index = 0;

        for (int i = 0; i < str.size(); i++) {

            if (index >= size) {
                size = size + startSize;
                tmp2 = new string[size];
                for (int i = 0; i < index; i++) {
                    tmp2[i] = tmp1[i];
                }
                delete [] tmp1;
                tmp1 = tmp2;
            }

            if (delim == str[i] && limit == -1) {
                tmp1[index] = line;
                line = "";
                index++;
            } else if (delim == str[i] && limit > 1 && index < limit - 1) {
                tmp1[index] = line;
                line = "";
                index++;
            } else {
                line += str[i];
            }

        }

        // put last element
        tmp1[index] = line;

        // create actual size array
        size = index + 1;
        data = new string[size];
        for (int i = 0; i < size; i++) {
            data[i] = tmp1[i];
        }
        delete [] tmp1;

        return {size, data};
    }

    StringArray splitToStringArray(string str, char delim) {
        return leftSplitToStringArray(str, delim, -1);
    }

    IntArray splitToIntArray(string str, char delim) {
        StringArray stringArray {splitToStringArray(str, delim)};

        int* data = new int[stringArray.size];

        for (int i = 0; i < stringArray.size; i++) {
            data[i] = stoi(stringArray.data[i]);
        }

        delete [] stringArray.data;

        return {stringArray.size, data};
    }

    DoubleArray splitToDoubleArray(string str, char delim) {
        StringArray stringArray {splitToStringArray(str, delim)};

        double* data = new double[stringArray.size];

        for (int i = 0; i < stringArray.size; i++) {
            data[i] = stod(stringArray.data[i]);
        }

        delete [] stringArray.data;

        return {stringArray.size, data};
    }

}
