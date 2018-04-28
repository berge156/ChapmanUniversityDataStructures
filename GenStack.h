/*
Cole Gotelli
Student ID: 2268217
Student Email: gotel100@mail.chapman.edu
CPSC 350-01
*/


#ifndef GEN_STACK_H
#define GEN_STACK_H

#include <iostream>

using namespace std;

template <class T>

class GenStack {

	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();

		void push(T data);
		T pop();
		T peek();
		bool isEmpty();
		bool isFull();
		int getSize();
		void increaseSize();

		T *myArray;
		T *tempArray;
		int top;
		int size;
		
};

template <class T>
GenStack<T>::GenStack() { //default constructor

}

template <class T>
GenStack<T>::GenStack(int maxSize) { //overlaod constructor
	myArray = new T[maxSize];
	size = maxSize;
	top = -1;
	tempArray = new T[size];

}

template <class T>
GenStack<T>::~GenStack() { //deconstuctor

	delete myArray;
	delete tempArray;
	cout << "The stack has been deleted" << endl;
}

template <class T>
void GenStack<T>::push(T data) {
	//make necessary error checks
	if(isFull()) {
		increaseSize();
		push(data);
	}
	else {
		myArray[++top] = data;
	}
	
}

template <class T>
T GenStack<T>::pop() {
	return myArray[top--];
}

template <class T>
T GenStack<T>::peek() {
	return myArray[top];
}

template <class T>
bool GenStack<T>::isFull() {
	return (top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty() {
	return (top == - 1);
}

template <class T>
void GenStack<T>::increaseSize() {
    tempArray = new T[size];

    for (int i = top; i > -1; --i) {
        tempArray[i] = myArray[i];
    }

    size += 1;
    myArray = new T[size];

    for (int i = top; i > -1; --i) {
        myArray[i] = tempArray[i];
    }
}

#endif
