#ifndef __MYTAR_H__
#define __MYTAR_H__

using namespace std;

struct TarHeader { /* byte offset */
	char filename[100];	/*   0 */
	char filemode[8];	/* 100 */
	char userid[8];		/* 108 */
	char groupid[8];	/* 116 */
	char filesize[12];	/* 124 */
	char mtime[12];		/* 136 */
	char checksum[8];	/* 148 */
	char type;		/* 156 */
	char lname[100];	/* 157 */
	/* USTAR Section */
	char USTAR_id[6];	/* 257 */
	char USTAR_ver[2];	/* 263 */
	char username[32];	/* 265 */
	char groupname[32];	/* 297 */
	char devmajor[8];	/* 329 */
	char devminor[8];	/* 337 */
	char prefix[155];	/* 345 */
	char pad[12];		/* 500 */
};

/* Values used in typeflag field.  */
#define REGTYPE  '0'            /* regular file */
#define AREGTYPE '\0'           /* regular file */
#define LNKTYPE  '1'            /* link */
#define SYMTYPE  '2'            /* reserved */
#define CHRTYPE  '3'            /* character special */
#define BLKTYPE  '4'            /* block special */
#define DIRTYPE  '5'            /* directory */
#define FIFOTYPE '6'            /* FIFO special */
#define CONTTYPE '7'            /* reserved */

#define XHDTYPE  'x'            /* Extended header referring to the
                                   next file in the archive */
#define XGLTYPE  'g'            /* Global extended header */

/* Bits used in the mode field, values in octal.  */
#define TUREAD   00400          /* read by owner */
#define TUWRITE  00200          /* write by owner */
#define TUEXEC   00100          /* execute/search by owner */
#define TGREAD   00040          /* read by group */
#define TGWRITE  00020          /* write by group */
#define TGEXEC   00010          /* execute/search by group */
#define TOREAD   00004          /* read by other */
#define TOWRITE  00002          /* write by other */
#define TOEXEC   00001          /* execute/search by other */


template <class T>
class Stack {
    typedef struct node {
        T data;
        struct node* next;
    }Node;
    Node* top;
    int totalFile;
    int width;
public:
/*
    Stack();
    void push(int x);
    int pop();
*/
    Stack()
    {
        totalFile = 0;
        width = 0;
        top = NULL;
    }
    ~Stack()
    {
        Node* tmp;
        while(top != NULL) {
            tmp = this->top;
            top = top->next;
            delete tmp;
        }
    }
    void push(T x)
    {
        Node* node = new Node, *tmp = this->top;
        memcpy((void *)&(node->data), (void *)&x, 512);
        
        if (this->top == NULL) {
            this->top = node;
            setWidth(this->top->data.username, this->top->data.groupname, strtol(this->top->data.filesize, 0, 8), strtol(this->top->data.devmajor, 0, 8), strtol(this->top->data.devminor, 0, 8));
            totalFile += 1;
            return ;
        }

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
        setWidth(this->top->data.username, this->top->data.groupname, strtol(this->top->data.filesize, 0, 8), strtol(this->top->data.devmajor, 0, 8), strtol(this->top->data.devminor, 0, 8));
        
        //node->next = this->top;
        //this->top = node;
        totalFile += 1;
    }
    T pop()
    {
        Node* tmp = this->top;
        T value;
        memcpy(&value, &(this->top->data), 512);
        this->top = this->top->next;

        delete tmp;
        totalFile -= 1;

        return value;
    }
    void setWidth(char *username, char *groupname, long filesize, long major, long minor)
    {
        char m = this->getType();
        int sizeLen = 1;

        if (m == 'b' || m == 'c') {
            while (major > 9) {
                major /= 10;
                sizeLen++;
            }

            while (minor > 9) {
                minor /= 10;
                sizeLen++;
            }
        }
        else {
            while (filesize > 9) {
                filesize /= 10;
                sizeLen++;
            }
        }
        int newWidth = (strlen(username) + strlen(groupname) + sizeLen+2)/4*4+5;
        width = ((newWidth > width) ? newWidth : width);
    }
    int getTotalFile()
    {
        return totalFile;
    }
    char getType()
    {
        switch (this->top->data.type) {
            case REGTYPE:           /* regular file */
            case AREGTYPE:          /* regular file */
                return '-';
            case LNKTYPE:           /* link */
                return 'h';
            case SYMTYPE:           /* reserved */
                return 'l';
            case CHRTYPE:           /* character special */
                return 'c';
            case BLKTYPE:           /* block special */
                return 'b';
            case DIRTYPE:           /* directory */
                return 'd';
            case FIFOTYPE:          /* FIFO special */
                return 'p';
            case CONTTYPE:          /* reserved */
            case XHDTYPE:           /* Extended header referring to the next file in the archive */
            case XGLTYPE:           /* Global extended header */
                return '-';
            default:
                return '-';
        }
    }
    char *getMode()
    {
        char *mode = new char[11];
        memset(mode, 0, 11*sizeof(char));

        mode[0] = this->getType();

        long int filemode = strtol(this->top->data.filemode, 0, 8);
        ((filemode &  TUREAD) != 0) ? mode[1] = 'r' : mode[1] = '-';
        ((filemode & TUWRITE) != 0) ? mode[2] = 'w' : mode[2] = '-';
        ((filemode &  TUEXEC) != 0) ? mode[3] = 'x' : mode[3] = '-';
        ((filemode &  TGREAD) != 0) ? mode[4] = 'r' : mode[4] = '-';
        ((filemode & TGWRITE) != 0) ? mode[5] = 'w' : mode[5] = '-';
        ((filemode &  TGEXEC) != 0) ? mode[6] = 'x' : mode[6] = '-';
        ((filemode &  TOREAD) != 0) ? mode[7] = 'r' : mode[7] = '-';
        ((filemode & TOWRITE) != 0) ? mode[8] = 'w' : mode[8] = '-';
        ((filemode &  TOEXEC) != 0) ? mode[9] = 'x' : mode[9] = '-';

        return mode;
    }
    char *getUsername()
    {
        return this->top->data.username;
    }
    char *getGroupname()
    {
        return this->top->data.groupname;
    }
    char *getTime()
    {
        long timer = strtol(this->top->data.mtime, 0, 8);
        struct tm *timeinfo = localtime(&timer);
        char *buf = new char[20];

        strftime(buf, 20, "%F %H:%M", timeinfo);

        return buf;
    }
    string getFilesize()
    {
        char m = this->getType();
        std::string fileSize;

        if (m == 'b' || m == 'c') {
            fileSize = to_string(strtol(this->top->data.devmajor, 0, 8)) + "," + to_string(strtol(this->top->data.devminor, 0, 8));
        }
        else {
            fileSize = to_string(strtol(this->top->data.filesize, 0, 8));
        }

        return fileSize;
    }
    string getFilename()
    {
        char m = this->getType();
        if (m == 'h') {
            string str = " link to ";
            return this->top->data.filename + str + this->top->data.lname;
        }
        else if (m == 'l') {
            string str = " -> ";
            return this->top->data.filename + str + this->top->data.lname;
        }
        else {
            return this->top->data.filename;
        }
    }
    int getWidth()
    {
        return width;
    }
};

#endif
