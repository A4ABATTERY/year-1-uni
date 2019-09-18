#include <iostream>
#include <assert.h>

using std::cout;

const int ARR_LENGTH = 7;

int* createStatArray(int len);
int* createDynArray();
void initArray(int* arr);
void setSquares(int* arr);
void printArray(int* arr);

int main() {
  /* Only use one of the three array declarations up top here
  at one time. Undoubtedly you will run into compiler errors
  as you switch between the three, trying stuff, seeing what
  happens, which is good! That is part of the process of seeing
  how all the moving parts we've talked about fit together. You
  will need to comment various statments out in switching between
  the three declarations. */

  // int* arr = createStatArray(5);

int* arr = createDynArray();

 // int arr[5];
  initArray(arr);

  /* These two values will be the same if the array is declared
  statically and in the same scope as these print statements/
  assertion (assert kills your program if the condition inside
  of it is not met, so comment this out when you start working
  with dynamic memory). */
  cout << "arr:  " << arr << "\n";
  cout << "&arr: " << &arr << "\n";
  //assert(arr == (int*) &arr);

  /* As mentioned in lecture and on the slides, the output from
  this block here will be garbage when working with dynamic memory,
  so comment this out, too, once you start playing around with
  createDynArray. */
  int len = sizeof(arr) / sizeof(int);
  cout << "size of arr: " << sizeof(arr) << "\n";
  cout << "size of int: " << sizeof(int) << "\n";
  cout << "length of arr: " << len << "\n";

  printArray(arr);

  // setSquares(arr);
  // printArray(arr);
  // delete[] arr;

  return 0;
}

int* createStatArray(int len) {
  /* Create a local array statically (on the stack!) */
  int new_arr[len];

  /* Remember, new_arr is LOCAL TO THIS SCOPE and the memory
  associated with new_arr will be wiped as soon as this
  function. So, while this function will compile and run,
  the array structure (and certainly the contents) of
  new_arr as it is returned to the main will be utter
  garbage! */
  return new_arr;
}
int* createDynArray() {
  /* Create a dynamic array (on the heap!) of size ARR_LENGTH,
  which, recall, is a constant that we define in global scope
  at the top of the program. */
  int* new_arr = new int[ARR_LENGTH];

  /* initArray is called to initialize each element in new_arr.
  More explanation as to why we can expect these changes to be
  preserved in the initArray implementation. */
  initArray(new_arr);
  /* Because new_arr points to a memory address ON THE HEAP,
  memory which is unaffected by the deletion of this current
  stack frame, the memory address returned by this function
  will be unadulterated in the main. In other words, all the
  work we did in allocating memory to and initializing this
  variable will be preserved. This is not supposed to work. */
  return new_arr;
}
void initArray(int* arr) {
  /* So why is it that we can expect the changes to be made
  in this function to be preserved? Because we are passing in,
  not a by-value copy of the array itself, but rather the
  memory address at which the array can be found on the heap.
  Thus, the memory that is being operated on in this function,
  as well as the one which called it, and what is evenutally
  passed back up into main to be stored in 'arr' IS THE SAME
  PIECE OF MEMORY.

  (Note: Consider the parameter type. The data type that stores
  the address of the particular array we are working with is
  'int*'. This is what we are talking about when we say "pass
  by pointer.") */

  /* -1 is the standard value to which a variable should be
  initialized. */
  for (int i=0; i<ARR_LENGTH; i++) {
    arr[i] = -1;
  }
}
void setSquares(int* arr) {
  /* I did not get to this function in either lecture, but it
  is designed to set each array index to the first ARR_LENGTH
  positive square numbers. In the implementation of this
  function contains the recipe for a segmentation fault. Even
  if you see the error right away, try running the code and
  seeing what happens. Then correct the error. I would
  encourage you to play around with this and see what you
  can get away with (maybe try i<=...). */
  for (int i=0; i<ARR_LENGTH*2; i++) {
    arr[i] = (i+1) * (i+1);
  }
}
void printArray(int* arr) {
  /* This function prints out a nicely formatted rendering of
  the array's contents.

  Style note: I don't like endl; I find it ugly and
  misrepresentative of what's really going on in behind the
  scenes. The new line character is '\n'. I type it out
  explicitly. Similarly, '\t' means tab. */
  cout << "\n\tArray contents: ";
  for (int i=0; i<ARR_LENGTH; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n\n";
}
                                                                        
         
