#include <iostream>
using namespace std;

template<typename T>
struct Node {
  Node(T val) : value{val}, next{nullptr} {} 
  T value;
  Node<T> *next;
};

template<typename T>
class Stack {
private:
  Node<T> *first;
  Node<T> *last;
  size_t length; 

public:
  Stack() : first{nullptr}, last{nullptr}, length{0} {}

  Node<T> *pickFirst() { 
    return first != nullptr ? first : new Node<T>(-1); 
  }
  Node<T> *pickLast() { 
    return last != nullptr ? last : new Node<T>(-1);
  }

  void push(T val) {
    Node<T> *newNode = new Node<T>(val);

    if (length == 0) {
      first = newNode;
      last = newNode;
    } else {
      Node<T> *tempNode = first;
      first = newNode;
      first->next = tempNode;
    }

    length++;
  }

  Node<T> *pop() {
    if (!length) return new Node<T>(-1);

    Node<T> *poppedNode = first;

    if (first == last) last = nullptr;
    first = first->next;

    length--;
    return poppedNode;
  }

  void print() {
    size_t t = length;
    Node<T> *node = first;
    while (t--) {
      cout << node->value << " ";
      node = node->next;
    }
    cout << endl;
  }

};

template<typename T>
class Queue {
private:
  Node<T> *first;
  Node<T> *last;
  size_t len;

public:
  Queue() : first{nullptr}, last{nullptr}, len{0} {}

  Node<T> *getFirst() {
    return first != nullptr ? first : new Node<T>(-1);
  }

  Node<T> *getLast() {
    return last != nullptr ? last : new Node<T>(-1);
  }

  void push(T val) {
    Node<T> *newNode = new Node<T>(val);

    if (!len) {
      first = newNode;
      last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }

    len++;
  }

  Node<T> *pop() {
    if (!len) return new Node<T>(-1);

    Node<T> *poppedNode = first;

    if (first == last) last = nullptr;
    first = first->next; 

    len--;
    return poppedNode;
  }

  void print() {
    Node<T> *node = first;

    while (node != nullptr) {
      cout << node->value << " ";
      node = node->next;
    }

    cout << endl;
  }
};

int main() {
  return 0;
}