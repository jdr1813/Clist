/*
Name: Justin Rivas
Coding 05
Purpose: Creating a list object similar to Python.
*/

#include "mylist.h"

// constructor
MyList::MyList(int size) {
    srand(time(NULL));  // call only once!
    if (size >= 1){
    length = size;
    } else {
        length = LISTSIZE;
    }
    array = new int[length];
    setArray(0);
}

// destructor
MyList::~MyList() {
    delete[] array;
}

void MyList::swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void MyList::setArray(int value){
    for(int i = 0; i < length; i++){
        array[i] = value;
    }
    sorted = true;
}

void MyList::setRandom(int min, int max){

    if(min == max || min < 1 || max < 1){
        min = RMIN;
        max = RMAX;
    } else if(min > max){
        swap(&min, &max);
    }
    
    for(int i=0; i<length; i++){
        array[i] = rand() % (min - max + 1) + min;
    } 
    sorted = false;
}

bool MyList::setElement(int value, int index){
    bool inRange = true;

    if (index >= 0 && index < length){
    
        array[index] = value;

    } else {
        inRange = false;
    }
    sorted = false;
    return inRange;
}

int MyList::getElement(int index){

    if (index >= 0 && index < length) {

        index = array[index];

    } else {
        throw 0;
    }
    return index;
}

bool MyList::getElement(int index, int *iptr){
    bool inRange = true;

    if (index >= 0 && index < length) {
        
        *iptr = array[index];
    } else{
        inRange = false;
    }
    return inRange;
}

bool MyList::resizeArray(int newSize){
    bool resized = false;
    if(newSize > 0 && newSize != length){
        int *newArray = new int[newSize];
        int min = std::min(newSize, length);
        for(int i = 0; i<min; i++){
            newArray[i] = array[i];
        }
        for(int i = length; i<newSize; i++){
            newArray[i] = 0;
        }
        if(min < newSize){
            sorted = false;
        }
        delete array;
        array = newArray;
        length = newSize;
        resized = true;
    }
    return resized;
}

void MyList::printArray() {

    cout << "[";
    for (int i = 0; i < length; i++){
        cout << array[i]<< " ";
    }
    cout << "\b]" << endl;
}

int MyList::getLength(){
    return length;
}

bool MyList::getSorted(){
    return sorted;
}

void MyList::sort(){
    int i, j, minindex;
    if(!sorted){
        for (i = 0; i < length-1; i++){
            minindex = i;
            for(j = i+1; j < length; j++){
                if (array[j] < array[minindex]){
                    minindex = j;
                }
            }
            swap(&array[minindex], &array[i]);
        }
        sorted = true;
    }
    
}

int MyList::findElement(int key){
    
    if (sorted){
        key = binsearch(array, 0, length-1, key);
    }else if(!sorted){
        key = linsearch(key);
    } else{
        key = -1;
    }
    return key;
}

int MyList::binsearch(int arr[], int low, int high, int key){
    int found = -1;

    if (high >= low){
        int mid = low + (high - low) / 2;

        if(arr[mid] == key){
            found = mid;
        } else if(arr[mid] > key){
            found = binsearch(array, low, mid - 1, key);
        } else{
            found = binsearch(array, mid + 1, high, key);
        }
    }
    return found;
}

int MyList::linsearch(int num){
    int key = -1;
    int i = 0;

    while (i < length && key == -1){
        if(array[i] == num){
            key = i;
        }
        i++;
    }   

    return key;
}
