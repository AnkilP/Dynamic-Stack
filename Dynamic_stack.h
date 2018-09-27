/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  a293pate @uwaterloo.ca
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
		int *array;
		int count;		
		int array_size;
		int initial_size;
	
	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
			
		void push( int const & );
		int pop();
		void clear();		
};

Dynamic_stack::Dynamic_stack( int n ):
count( 0 ),
array_size( n ),
initial_size(n)
{
	array = new int[array_size];
}


Dynamic_stack::~Dynamic_stack() {
	delete [] array;
}


int Dynamic_stack::top() const {
	return array[count - 1];
}


int Dynamic_stack::size() const {
	return  count;
}


bool Dynamic_stack::empty() const {
	if(count == 0){
		return true;
	}
	else{
		return false;
	}
}


int Dynamic_stack::capacity() const {
	return array_size;
}


void Dynamic_stack::push( int const &obj ) {
	//if array is full, create new one
	if(array_size == count){
		int * array2 = new int[array_size*2];
		//fill in from old array
		for(int i = 0; i < count; ++i){
			array2[i] = array[i];
		}
		//delete old array
		//TODO: am i deleting every element or am i just deleting the pointer
		delete [] array;
		//push new value into array
		array2[count] = obj;
		//increment count and array_size and array
		count++;
		array_size = array_size * 2;
		array = array2;
		//initialize new array?
	}
	else{
		array[count] = obj;
		//increment count and array_size
		count++;
	}

}


int Dynamic_stack::pop() {
	int popped_element = top();
	//array[count - 1] = 0;
	count--;
	return popped_element;
}

void Dynamic_stack::clear() {
	if(array_size > initial_size){
		delete [] array;
	}
	else{
		delete [] array;
		//I dont know if this is O(n)
		count = 0;
		array = new int[initial_size];
	}
}
#endif
