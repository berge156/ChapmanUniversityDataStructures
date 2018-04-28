#include <iostream>

using namespace std;

template <class T>
class ListNode {
	
	public:
		ListNode();
		ListNode(T d);
		~ListNode();

		T data;
		ListNode<T> *next;
		ListNode<T> *prev;

};

template <class T>
ListNode<T>::ListNode() {
	data = 0;
	next = NULL;
	prev = NULL;

}

template <class T>
ListNode<T>::~ListNode() {
	if(next != NULL) {
		next = NULL;
		prev = NULL;

		delete next;
		delete prev;
	}
}

template <class T>
ListNode<T>::ListNode(T d) {
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T>
class DoublyLinkedList {

	private:
		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		virtual void insertFront(T data);
		virtual void insertBack(T data);
		virtual T getFront();

		virtual T removeFront();
		virtual T removeBack();

		virtual void printList();
		virtual int find(int data);
		virtual unsigned int getSize();
		virtual bool isEmpty();

		virtual int deletePos(int pos);
		int remove(int key);
		int removeAt(int data);
		
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	size = 0;
	front = NULL;
	back = NULL;

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

	if(front != NULL) {
		delete front;

	}

}

template <class T>
void DoublyLinkedList<T>::printList() {

	if(front == NULL) {
		cout << "There is no data to print" << endl;
	}

	ListNode<T> *curr = front;

	while(curr->next != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}

template <class T>
void DoublyLinkedList<T>::insertFront(T data) {
	
	ListNode<T> *node = new ListNode<T>(data);
	if(isEmpty()) {
		back = node;
	}
	else { //not empty
		front->prev = node;
	}
	node->next = front;
	front = node;
	++size;

}

template <class T>
void DoublyLinkedList<T>::insertBack(T data) {

	ListNode<T> *node = new ListNode<T>(data);

	//Check for empty or full
	if(isEmpty()) {
		front = node;
	}
	else { //not empty
		back->next = node;
		node->prev = back;
	}

	back = node;
	++size;

}

template <class T>
T DoublyLinkedList<T>::removeFront() {

	if(!isEmpty()) {
		int td = front->data;
		ListNode<T> *ft = front;

		if(front->next == NULL) {
			back = NULL;
		}
		else {
			ft->next->prev = NULL;
		}

		front = front->next;
		--size;

		delete ft;
		return td;
	}
	else {
		return T();
	}
}

template <class T>
T DoublyLinkedList<T>::getFront() {
	return front->data;
}

template <class T>
int DoublyLinkedList<T>::remove(int key) {
	int pos = find(key);
	deletePos(key);
}

template <class T>
int DoublyLinkedList<T>::find(int d) {
	int idx = -1;
	ListNode<T> *curr = front;

	while(curr != NULL) {
		++idx;
		if(curr->data == d) {
			break;
		}
		else {
			curr = curr->next;
		}
	}

	if(curr == NULL) {
		idx = -1;
	}

	return idx;
}

template <class T>
int DoublyLinkedList<T>::deletePos(int pos) {
	int idx = 0;

	ListNode<T> *curr = front;
	ListNode<T> *prev = front;

	while(idx != pos) { //This method updates the pointers
		prev = curr;
		curr = curr->next;
		++idx;
	}

	prev->next = curr->next;
	curr->next = NULL;
	int td = curr->data;

	delete curr;
	--size;
	return td;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
	return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
	return size;
}
