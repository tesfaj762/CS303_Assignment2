

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <memory>

template<typename T>
struct Node {

  T data;
  std::shared_ptr<Node<T>> next;

  Node(T value, std::shared_ptr<Node<T>> next) : data(value), next(next) {}

};

template<class T>
class SinglyLinkedList {
public:

  SinglyLinkedList();
  explicit SinglyLinkedList(T);

  SinglyLinkedList(const SinglyLinkedList&);
  SinglyLinkedList& operator=(const SinglyLinkedList&);

  SinglyLinkedList(SinglyLinkedList&&);
  SinglyLinkedList& operator=(SinglyLinkedList&&);

  ~SinglyLinkedList() = default;

  void push_front(const T& data);
  
  void push_back(const T& data);

  void pop_front();
  
  void pop_back();

  Node<T>& front();

  Node<T>& back();

  void insert(size_t index, const T& item);

  bool remove(size_t index);

  size_t find(const T& item);

  bool empty();

  std::shared_ptr<Node<T>>& head_ptr() {
    return head;
  }

  std::shared_ptr<Node<T>>& tail_ptr() {
    return tail;
  }

  size_t size;

  
private:

  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;

  
};

#include "SinglyList.tpp"

#endif