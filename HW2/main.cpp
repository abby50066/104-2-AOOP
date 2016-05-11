#include <iostream>
#include <cstring>

#include "mytar.h"
#include "myhw2.h"

int main(int argc, char **argv) {
    class Stack<struct TarHeader> info;

    if (argc != 2) {
        std::cout << "Usage : ./mytar [tar file name]\n";
        return -1;
    }

    if (readTarInfo(argv[1], info) == -1 ) {
        return -1;
    }
    printTarInfo(info);

    return 0;
}
