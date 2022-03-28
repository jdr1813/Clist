/*
Name: Justin Rivas
Coding 05
Purpose: Creating a list object similar to Python.
*/

#include "main.h"

int main(int argc, char** argv) {
    /***********************************
     * DO NOT MODIFY THIS FILE OTHER THAN
     * TO ADD YOUR COMMENT HEADER AND
     * UNCOMMENT THINGS AS YOU COMPLETE
     * THE FUNCTIONALITY OF YOUR LIST OBJECT
     ***********************************/

    /* This will create a "list" of size LISTSIZE
     * and initialize it to all zeros */
    cout << "create and initialize mylist" << endl;
    MyList mylist(LISTSIZE);
    mylist.printArray();
    if(mylist.getSorted() == true){
       cout << "This list is sorted." << endl;
    } else{
         cout << "This list has not been sorted." << endl;
         mylist.sort();
         cout << "This is the list sorted in ascending order." << endl;
         mylist.printArray();
    }
    cout << endl;

    /* This will set the list to all 50 */
    cout << "set mylist to all 50" << endl;
    mylist.setArray(50);
    mylist.printArray();
      if(mylist.getSorted() == true){
         cout << "This list is sorted." << endl;
      } else{
         cout << "This list has not been sorted." << endl;
         mylist.sort();
         cout << "This is the list sorted in ascending order." << endl;
         mylist.printArray();
      }
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers -2 to 4" << endl;
    mylist.setRandom(-2,4);
    mylist.printArray();
      if(mylist.getSorted() == true){
         cout << "This list is sorted." << endl;
      } else{
         cout << "This list has not been sorted." << endl;
         mylist.sort();
         cout << "This is the list sorted in ascending order." << endl;
         mylist.printArray();
      }
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers 4 to 4" << endl;
    mylist.setRandom(4,4);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 1-100 values */
    cout << "attempt to set to random numbers 1 to 100" << endl;
    mylist.setRandom(1,100);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 500-1000 values */
    cout << "attempt to set to random numbers 500 to 1000" << endl;
    mylist.setRandom(1000,500);
    mylist.printArray();
    mylist.sort();
    cout << "This is the list sorted." << endl;
    mylist.printArray();
    cout << endl;

    /* These next two sets will succeed and set the 1st and last
     * elements to 1000 and 2000 respectively */
    if(mylist.setElement(1000, 0)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(2000, LISTSIZE-1)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    /* These next two sets will fail and leave the array unmodified */
    if(mylist.setElement(9999, -1)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(9999, LISTSIZE)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    cout << "Testing new and/or modified code..." << endl;
    cout << endl;

    cout << "printing the array element by element using: int getElement(int);" << endl;
    cout << "(going one too far to test out of range)" << endl;

   for(int i=0; i<LISTSIZE + 1; i++){
      try
      {
         cout << mylist.getElement(i) << endl;
      }
      catch(int e)
      {
         cout << "error, out of range" << endl;
      }
   }
   
   cout << endl;
   cout << "attempting to get element [LISTSIZE * 1.5] using: int getElement(int)" << endl;
   
   try
   {
      cout << mylist.getElement(LISTSIZE * 1.5) << endl;
   }
   catch(int e)
   {
      cout << "error, out of range" << endl;
   }

   cout << endl;
   cout << "printing the array element by element using: bool getElement(int, int*);" << endl;
   cout << "(going one too far to test out of range)" << endl;
   

   for(int i=0; i<LISTSIZE; i++){
      try
      {
         cout << mylist.getElement(i) << endl;
      }
      catch(int e)
      {
         cout << "error, out of range" << endl;
      }
   }

   int element;
   if(mylist.getElement(LISTSIZE, &element)){
      cout << element << endl;
   } else {
      cout << "error, out of range" << endl;
   }

   cout << endl;
   cout << "attempting to get element [LISTSIZE * 1.5] using: bool getElement(int, int*)" << endl;
   if(mylist.getElement(LISTSIZE * 1.5, &element)){
      cout << element << endl;
   } else {
      cout << "error, out of range" << endl;
   }
    
   cout << endl;
   cout << "resizing array to LISTSIZE" << endl;

   if(mylist.resizeArray(LISTSIZE)){
      cout << "resized..." << endl;
      mylist.printArray();
      cout << "Elements in array: " << mylist.getLength() <<   endl;
      if(mylist.getSorted() == true){
       cout << "This list is sorted." << endl;
      } 
      else{
         cout << "This list has not been sorted." << endl;
         mylist.sort();
         cout << "This is the list sorted in ascending order." << endl;
         mylist.printArray();
      }

   } else {
      cout << "failed to resize" << endl;
   }

   cout << endl;
   cout << "resizing array to LISTSIZE+5" << endl;

   if(mylist.resizeArray(LISTSIZE + 5)){
      cout << "resized..." << endl;
      mylist.printArray();
      cout << "Elements in array: " << mylist.getLength() <<   endl;
      if(mylist.getSorted() == true){
         cout << "This list is sorted." << endl;
      } 
      else{
         cout << "This list has not been sorted." << endl;
      }
      
   } else {
      cout << "failed to resize" << endl;
   }

   cout << endl;
   cout << "resizing array to LISTSIZE-5" << endl;

   if(mylist.resizeArray(LISTSIZE - 5)){
      cout << "resized..." << endl;
      mylist.printArray();
      cout << "Elements in array: " << mylist.getLength() <<   endl;
      if(mylist.getSorted() == true){
         cout << "This list is sorted in ascending order." << endl;
      } 
      else{
         cout << "This list has not been sorted." << endl;
         mylist.sort();
         cout << "This is the list sorted in ascending order." << endl;
         mylist.printArray();
      }

   } else {
      cout << "failed to resize" << endl;
   }
   
   cout << endl;
   cout << "resizing array to 0" << endl;
   
   if(mylist.resizeArray(0)){
      cout << "resized..." << endl;
      mylist.printArray();
      cout << "Elements in array: " << mylist.getLength() <<   endl;
   } else {
      cout << "failed to resize" << endl;
   }
   cout << endl;


   cout << "Resizing array with 20 elements filled with random numbers 1-50" << endl;
   cout << endl;
   mylist.resizeArray(20);
   mylist.setRandom(1, 50);
   mylist.printArray();
   cout << "Elements in array: " << mylist.getLength() << endl;
   cout << endl;
   cout << "Here is the array in ascending order" << endl;
   mylist.sort();
   mylist.printArray();

   cout << "Resizing array with 10 elements filled with random numbers 1-10" << endl;
   cout << endl;
   mylist.resizeArray(10);
   mylist.setRandom(1, 10);
   mylist.printArray();
   cout << "Elements in array: " << mylist.getLength() << endl;
   cout << endl;
   cout << "testing findElement before sorting" << endl;
   cout << mylist.findElement(1) << endl;
   cout << mylist.findElement(2) << endl;
   cout << mylist.findElement(3) << endl;
   cout << mylist.findElement(4) << endl;
   cout << mylist.findElement(5) << endl;
   cout << mylist.findElement(6) << endl;

   cout << "Here is the array in ascending order" << endl;
   mylist.sort();
   mylist.printArray();
   cout << "testing findElement after sorting" << endl;
   cout << mylist.findElement(1) << endl;
   cout << mylist.findElement(2) << endl;
   cout << mylist.findElement(3) << endl;
   cout << mylist.findElement(4) << endl;
   cout << mylist.findElement(5) << endl;
   cout << mylist.findElement(6) << endl;
   cout << endl;

   cout << "Binary search doesn't return the first occurance, just whichever it finds first." << endl;
   mylist.setArray(50);
   mylist.sort();
   mylist.printArray();
   cout << mylist.findElement(1) << endl;
   cout << mylist.findElement(2) << endl;
   cout << mylist.findElement(50) << endl;
   cout << mylist.findElement(4) << endl;
   cout << mylist.findElement(5) << endl;
   cout << mylist.findElement(6) << endl;
   
    return 0;
}
