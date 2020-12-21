#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <string>

namespace application::model {

    using std::string;

    struct StringArray {
        int size;
        string* data;
    };

}

#endif // STRING_ARRAY_H
