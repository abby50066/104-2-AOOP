#ifndef __MYHW2_H__
#define __MYHW2_H__

int readTarInfo(char *, class Stack<struct TarHeader> &);	/* return 0 if NO ERROR */
int printTarInfo(class Stack<struct TarHeader> &);			/* return a number which present file number in tarfile. */

#endif
