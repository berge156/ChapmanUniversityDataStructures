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