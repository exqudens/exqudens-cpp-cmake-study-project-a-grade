#ifndef STRINGS_H
#define STRINGS_H

#include <string>

#include "../model/StringArray.h"
#include "../model/IntArray.h"
#include "../model/DoubleArray.h"

namespace application::util::Strings {

    using std::string;
    using application::model::StringArray;
    using application::model::IntArray;
    using application::model::DoubleArray;

    /**
     * @brief - Replace leading whitespaces.
     * @param str - String for replace leading whitespaces.
     * @return - New string without leading whitespaces.
     */
    string leftTrim(string str);

    /**
     * @brief - Replace trailing whitespaces.
     * @param str - String for replace trailing whitespaces.
     * @return - New string without trailing whitespaces.
     */
    string rightTrim(string str);

    /**
     * @brief - Replace leading and trailing whitespaces.
     * @param str - String for replace leading and trailing whitespaces.
     * @return - New string without leading and trailing whitespaces.
     */
    string trim(string str);

    StringArray leftSplitToStringArray(string str, char delim, int limit);
    StringArray splitToStringArray(string str, char delim);
    IntArray splitToIntArray(string str, char delim);
    DoubleArray splitToDoubleArray(string str, char delim);

}

#endif // STRINGS_H
