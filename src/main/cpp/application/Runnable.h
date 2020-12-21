#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <iostream>

namespace application::Runnable {

    using std::istream;
    using std::ostream;

    int run(istream& in, ostream& out);
    int run(int argc, char *argv[]);

}

#endif // RUNNABLE_H
