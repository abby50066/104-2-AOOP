#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#include "mytar.h"
#include "myhw2.h"

using namespace std;

int readTarInfo(char *tarfile, class Stack<struct TarHeader> &info)
{
    char header[512];

    std::ifstream is(tarfile, std::ifstream::binary);
    if (!is) {
        cout << "Cannot open tar file.\n";
        return -1;
    }

    is.seekg(0, is.beg);

    while (1) {
        int len;
        is.read(header, 512);
        if (!strncmp(header, "", 512)) {
            is.close();
            break;
        }
        if (strncmp(header+257, "ustar", 5)) {
            cout << "Not a ustar file.\n";
            cout << "File opening error.\n";
            is.close();
            return -1;
        }

        struct TarHeader node;
        memcpy (&node, header, 512);
        info.push(node);

        len = strtol(header + 124, 0, 8);
        len = (len+511)&~0x1ffU;	// set len to multiple of block(512 bytes).
        if (!is.seekg(len, ios::cur)) {
            is.close();
            return -1;
        }
    }

    return 0;
}

int printTarInfo(class Stack<struct TarHeader> &info)
{
    int totalFile = info.getTotalFile();
    cout << "total " << totalFile << " files\n";
    while (info.getTotalFile()) {

        char *mode = info.getMode();
        cout << mode;
        delete[] mode;

        cout << " " << info.getUsername();
        cout << "/" << info.getGroupname();
/*  this is for my computer.
        static long width = 0;
        long filesize = info.getFilesize();
        int sizeLen = 0;
        while (filesize > 0) {
            filesize /= 10;
            sizeLen++;
        }
        width = ((sizeLen > width) ? sizeLen : width);
*/
        string fileSize = info.getFilesize();
        cout << " " << setw((info.getWidth() - strlen(info.getUsername()) - strlen(info.getGroupname()))) << fileSize;
        //delete[] fileSize;

        char *time = info.getTime();
        cout << " " << time;
        delete[] time;

        cout << " " << info.getFilename();
        cout << endl;

        info.pop();
    }

    return totalFile;
}
