
#include <iostream>
#include "Student.h"
#include "Faculty.h"

using namespace std;

template <class T>
class TreeNode {
	public:
		TreeNode();
		TreeNode(int k, T* d);
		~TreeNode();

		int key;
		T* data;
		TreeNode<T> *left;
		TreeNode<T> *right;

};

template <class T>
TreeNode<T>::TreeNode() {
	key = 0;
	data = T();
	left = NULL;
	right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T* d) {
	key = k;
	data = d;
	left = NULL;
	right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {
	delete left;
	delete right;
	delete data;
}

template <class T>
class BST {
	public:
		BST();
		~BST();

		void insert(TreeNode<T> *node);
		bool deleteNode(int k);
		bool contains(int k);
		T* find(int k);
		TreeNode<T>* getSuccessor(TreeNode<T> *d);

		TreeNode<T>* getRoot();
		int getSize();
		bool isEmpty();
		TreeNode<T>* getMax();
		TreeNode<T>* getMin();

		void printTree(TreeNode<T> *node);
		void printRecursive(TreeNode<T> *node);

	private:
		TreeNode<T> *root;
		int size;
	
};

template <class T>
BST<T>::BST() {
	root = NULL;
	size = 0;
}

template <class T>
BST<T>::~BST() {
	//iterate and delete
}

template <class T>
TreeNode<T>* BST<T>::getRoot() {
	return root;
}

template <class T>
int BST<T>::getSize() {
	return size;
}

template <class T>
bool BST<T>::isEmpty() {
	return (size=0);
}

template <class T>
TreeNode<T>* BST<T>::getMax() {
	TreeNode<T> *curr = root;

	if(root == NULL) {
		return NULL;
	}

	while(curr->right != NULL) {
		curr = curr->right;
	}

	return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMin() {
	TreeNode<T> *curr = root;

	if(root == NULL) {
		return NULL;
	}

	while(curr->left != NULL) {
		curr = curr->left;
	}

	return curr;
}

template <class T>
void BST<T>::printTree(TreeNode<T> *node) { //inorder traversal
	node = root;
	printRecursive(node);

}

template <class T>
void BST<T>::printRecursive(TreeNode<T> *node) { //inorder traversal
	if(node == NULL) {
		return;
	}

	printRecursive(node->left);
	cout << node->key << endl;
	printRecursive(node->right);

}

template <class T>
void BST<T>::insert(TreeNode<T> *node) {
	if(root == NULL) { //if empty tree
		root = node;
	}
	else { //not empty tree
		TreeNode<T> *curr = root;
		TreeNode<T> *parent = NULL;

		while(true) { //iterate and find insertion point
			parent = curr;

			//go left
			if(node->key < curr->key) { 
				curr = curr->left;

				if(curr == NULL) { //found insertion point
					parent->left = node;
					break;
				}
			}
			//go right
			else { 
				curr = curr->right;

				if(curr == NULL) { //found insertion point
					parent->right = node;
					break;
				}
			}
		}
	}
	++size;
}

template <class T>
bool BST<T>::contains(int k) {
	if(root == NULL) { //empty TreeNode
		return false;
	} 
	else {
		TreeNode<T> *curr = root;

		while(curr->key != k) {
			if(k < curr->key) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}

			if(curr == NULL) {
				return false;
			}
		}
	}

	return true;

}

template <class T>
T* BST<T>::find(int k) {
	if(root == NULL) { //empty TreeNode
		return NULL;
	}
	if(contains(k)) {
		TreeNode<T> *curr = root;

		while(curr->key != k) {
			if(k < curr->key) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}

			if(curr == NULL) {
				return false;
			}
		}
		return curr->data;
	} 
	else {
		return NULL;
	}
}

template <class T>
bool BST<T>::deleteNode(int k) {
	if(root == NULL) {
		return false; //empty tree
	}
	TreeNode<T> *curr = root;
	TreeNode<T> *parent = root;
	bool isLeft = true;

	//not empty, so let's find the node we are going to delete
	//we will make use of the contains method

	while(curr->key != k) { //searching for nextToDelete
		parent = curr;

		if(k < curr->key) {
			isLeft = true;
			curr = curr->left;
		}
		else {
			isLeft = false;
			curr = curr->right;
		}

		if(curr == NULL)
			return false;
	}

	//once we get here, we found the node we are looking for
	//WE FOUND THE NODE

	//no children
	if(curr->left == NULL && curr->right == NULL) {
		if(curr == root) {
			root = NULL; //null out the root
		}
		else if(isLeft) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}

	//one child
	//no right child
	else if( curr->right == NULL) {
		if(curr == root) {
			root = curr->left;
		}
		else if(isLeft) {
			parent->left = curr->left;
		}
		else {
			parent->right = curr->right;
		}
	}
	//no left child
	else if( curr->left == NULL) {
		if(curr == root) {
			root = curr->right;
		}
		else if(isLeft) {
			parent->left = curr->right;
		}
		else {
			parent->right = curr->right;
		}
	}
	//two children
	else {
		TreeNode<T> *successor = getSuccessor(curr);

		if(curr == root) {
			root = successor;
		}
		else if(isLeft) {
			parent->left = successor;
		}
		else {
			parent->right = successor;
		}
		//connect successors left child to currents left children
		successor->left = curr->left;
	}

	return true;

}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) { //d is the node to be deleted
	TreeNode<T> *sp = d; //sp is successors parent
	TreeNode<T> *successor = d;
	TreeNode<T> *curr = d->right;

	//loop until we find the successor
	//which will be one right, and then all the way left
	while(curr != NULL) {
		sp = successor;
		successor = curr;
		curr = curr->left;
	}

	//descendant of the right child
	if(successor != d->right) {
		sp->left = successor->right;
		successor->right = d->right;
	}

	return successor;
}




