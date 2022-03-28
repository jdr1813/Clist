/*
Name: Justin Rivas
Coding 05
Purpose: Creating a list object similar to Python.
*/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand, atoi */
#include <time.h>       /* time */
// you can add libraries if you need them, but you shouldn't

// DO NOT MODIFY THESE DEFINES
#define RMIN 1
#define RMAX 10
#define LISTSIZE 10

using std::cout;
using std::endl;

class MyList {
public:
    // DO NOT MODIFY THESES NEXT TWO
    MyList(int); // constructor
    ~MyList(); // destructor

    void printArray();
    void setArray(int);
    void setRandom(int, int);
    bool setElement(int, int);
    int getElement(int);
    bool getElement(int, int *);
    bool resizeArray(int);
    int getLength();
    bool getSorted();
    void sort();
    int findElement(int);

private:
    // these are the only attributes allowed
    // DO NOT ADD OR MODIFY THEM
    int length;
    int *array;
    bool sorted;

    void swap(int*, int*);
    bool inRange(int);
    int binsearch(int *,int,int,int);
    int linsearch(int);
};

#endif //MYLIST_H
