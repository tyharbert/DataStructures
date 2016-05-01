// taken from my own linked list implementation
// https://github.com/tyharbert/REUSE/tree/master/LinkedList/Library

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// List Node Class
template <class T>
struct Node {
    T data;
    Node<T>* next;
    
    Node<T>(T, Node*);
};

// Linked list Class
template <class T>
class LinkedList {
private:
    Node<T>* tail;

public:
    ~LinkedList();
    LinkedList();
    LinkedList(T);
    void push(T);
};

// Node Class constructor
template <class T>
Node<T>::Node(T d, Node* n): data(d), next(n) {}

// Linked List constructor
template <class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr) {}

// Linked List constructor
template <class T>
LinkedList<T>::LinkedList(T d) {
	head = tail = new Node<T>(d, nullptr);
}

#endif
