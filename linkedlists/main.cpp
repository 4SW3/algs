#include <iostream>
using namespace std;

template<typename T>
struct Node {
  Node() {}
  Node(T val) : value{val}, next{nullptr} {}
  T value;
  Node<T> *next;
};

template<typename T>
class SinglyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t len;

public:
  SinglyLinkedList() : head{nullptr}, tail{nullptr}, len{0} {}

  Node<T> *getHead() {
    return head != nullptr ? head : new Node<T>();
  }

  Node<T> *getTail() {
    return tail != nullptr ? tail : new Node<T>();
  }

  size_t length() {
    return len;
  }

  void push(T val) {
    Node<T> *node = new Node<T>(val);

    if (len == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }

    len++;
  }

  Node<T> *getNodeByIdx(size_t idx) {
    if (idx >= len || idx < 0 || len == 0) return new Node<T>();
    Node<T> *tempNode = head;
    while (idx--) tempNode = tempNode->next; 
    return tempNode;
  }

  Node<T> *pop() {
    if (len == 0) return new Node<T>();

    Node<T> *poppedNode = tail;

    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node<T> *tempNode = getNodeByIdx(len - 2);
      tail = tempNode;
      tail->next = nullptr;
    }

    len--;
    return poppedNode;
  }

  Node<T> *shift() {
    if (len == 0) return new Node<T>();

    Node<T> *shiftedNode = head;
    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }

    len--;
    return shiftedNode;
  }

  void unshift(T val) {
    if (len == 0) {
      push(val);
      return;
    }
    Node<T> *newHead = new Node<T>(val);
    newHead->next = head;
    head = newHead;
    len++;
  }

  void set(size_t idx, T val) {
    Node<T> *node = getNodeByIdx(idx);
    if (node != nullptr) node->value = val;
  }

  void insert(size_t idx, T val) {
    if (idx == 0) unshift(val);
    else if (idx == len) push(val);
    else {
      Node<T> *newNode = new Node<T>(val);
      Node<T> *tempNode = getNodeByIdx(idx - 1);
      newNode->next = tempNode->next;
      tempNode->next = newNode;
    }
    len++;
  }

  Node<T> *remove(size_t idx) {
    Node<T> *removedNode = new Node<T>(); 
    if (idx == 0) {
      removedNode = shift();
      return removedNode;
    }

    if (idx == len - 1) {
      removedNode = pop();
      return removedNode;
    }

    if (idx >= 0 && idx < len) {
      Node<T> *tempNode = getNodeByIdx(idx - 1);
      removedNode = tempNode->next;
      tempNode->next = tempNode->next->next;
    }

    return removedNode;
  }

  void recurPrint(Node<T> *node) {
    cout << node->value << " ";
    if (node->next != nullptr) recurPrint(node->next);
    if (node == head) cout << endl;
  }

  void print() {
    Node<T> *tempHead = this->head;
    recurPrint(tempHead);
  }

  // reverse() rotate(number)
};

int main() {
  SinglyLinkedList<int> *ll = new SinglyLinkedList<int>();
  ll->push(10);
  ll->push(20);
  ll->push(30);
  ll->push(40);
  ll->push(50);
  cout << "-> " << ll->remove(10)->value << endl;  
  ll->print();
  return 0;
}