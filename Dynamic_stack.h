/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  a293pate@edu.uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Fall 2018
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>
using namespace std;


class Dynamic_stack {

	private:
    //A pointer to be used as an array to store elements in the stack
    int *array;

    //Number of elements in the stack
    int count;

    //The size of the array
		int array_size;

    //The initial size of the array
    int initial_size;
	
	public:
    //setting default capacity of array to be 10
    Dynamic_stack(int n = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
			
		void push( int const & );
		int pop();
		void clear();		
};

/*
 * The constructor takes as argument the initial size of the
array and allocates memory for it. The default capacity (or number of entries) is 10. If
the argument n is less than one, use an array size of 1.
 */

Dynamic_stack::Dynamic_stack(int n) {
    //if user places a number that is less than 1, then default the size of the array to 1
    if (n < 1) {
        n = 1;
    }
    count = 0;
    array_size = n;
    initial_size = n;
    array = new int[array_size];
}

/*
 * The destructor deletes the memory allocated for the array.
 *
 * Assumptions: array has not already been deleted
 */
Dynamic_stack::~Dynamic_stack() {
	delete [] array;
}

/*
 * Return the integer at the top of the stack in O(1).
 * Underflow error is thrown if the array is empty
 *
 * Assumptions: count is at least 1
 *
 * The function call to empty is a bit unnecessary since it takes more time to call the function when I already have the variables accessible to me
 */

int Dynamic_stack::top() const {
    if (empty()) {
        throw underflow();
    }
    return array[count - 1];
}

/*
 * Return the number of elements currently stored in the stack in
O(1).

 Assumptions: count is greater than 0
 */

int Dynamic_stack::size() const {
    return count;
}

/*
 * Return true if stack is empty, false otherwise in O(1).
 *
 * Assumptions: count will be at least 0
 */

bool Dynamic_stack::empty() const {
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

/*
 * Return the capacity of stack in O(1). I.e. how much memory has been allocated for the elements in the array
 *
 * Assumptions: array_size is more than 0
 */

int Dynamic_stack::capacity() const {
    return array_size;
}

/*
 * Insert a new item at the head of the stack in O(1). If the
array is full, create a new array with size 2n (where n is current size of the array)
and copy the elements from the current array to the new array in O(n).

 Assumptions: delete [] array happens in O(1)
 */

void Dynamic_stack::push(int const &obj) {
    //if array is full, create new one
    if (array_size == count) {
        int *array2 = new int[array_size * 2];
        //fill in from old array
        for (int i = 0; i < count; ++i) {
            array2[i] = array[i];
        }
        //delete old array
        delete[] array;
        //push new value into array
        array2[count] = obj;
        //increment count and array_size
        count++;
        array_size = array_size * 2;
        array = array2;
        //memory leak with extra pointer?
    } else {
        array[count] = obj;
        //increment count
        count++;
    }

}

/*
 * Remove the element at the top of the stack in O(1).
 * This throws an underflow error if the array is empty.
 *
 * Caveats: Have to store top before decrementing count
 */

int Dynamic_stack::pop() {
    if (empty()) {
        throw underflow();
    }
    int popped_element = top();
    count--;
    return popped_element;
}

/*
 * Remove all elements from the stack in O(1). If the current array
size does not equal the initial size, delete the array and create a new array equal to
the initial size.

 Assumptions: delete [] array happens in O(1)
 */

void Dynamic_stack::clear() {
    if (array_size == initial_size) {
        delete[] array;
    } else {
        delete[] array;
        count = 0;
        array = new int[initial_size];
    }
}
#endif
