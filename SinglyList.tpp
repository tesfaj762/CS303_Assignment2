

#include "SinglyList.h"
#include <stdexcept>



//default constructor
template<class T>
SinglyLinkedList<T>::SinglyLinkedList() 
: head(nullptr)
, tail(nullptr)
, size(0)  
{

}


//parameterized constructor
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(T item) 
: head(std::make_shared<Node<T>>(item, nullptr))
, tail(head)
, size(1)  
{

}



//copy constructor
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& other)
: head(nullptr)
, tail(nullptr)
, size(other.size)
{

  if (!other.head) {
    return;
  }

  head = std::make_shared<Node<T>>(other.head->item, nullptr);
  std::shared_ptr<Node<T>> temp = head;

  for (auto it = other.head->next; it != nullptr; it = it->next) {

    temp->next = std::make_shared<Node<T>>(it->item, nullptr);
    temp = temp->next;

  }

  tail = temp;
  
}


//copy assignment operator
template<class T>
SinglyLinkedList<T>& 
SinglyLinkedList<T>::operator=(const SinglyLinkedList& other) {

  if (!other.head) {
    return nullptr;
  }

  head = std::make_shared<Node<T>>(other.head->item, nullptr);
  std::shared_ptr<Node<T>> temp = head;

  for (auto it = other.head->next; it != nullptr; it = it->next) {

    temp->next = std::make_shared<Node<T>>(it->item, nullptr);
    temp = temp->next;

  }

  tail = temp;
  size = other.size;

}



//move constructor
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList&& other)
: head(std::move(other.head))
, tail(std::move(other.tail))
, size(other.size) {

  other.size = 0;

}


//move assignment operator
template<class T>
SinglyLinkedList<T>& 
SinglyLinkedList<T>::operator=(SinglyLinkedList&& other) {

  head = std::move(other.head);
  tail = std::move(other.tail);
  size = std::move(other.size);

}



template<class T>
bool
SinglyLinkedList<T>::empty() {

  if (size == 0) return true;

  return false;
  
}


template<class T>
void 
SinglyLinkedList<T>::push_front(const T& data) {

  size++;

  //if list is empty, assign head and tail to new node
  if (!head) { 

    head = std::make_shared<Node<T>> (data, nullptr);
    tail = head;
    return;

  }


  //otherwise only reassign head pointer
  head = std::make_shared<Node<T>>(data, head);

}


template<class T>
void
SinglyLinkedList<T>::push_back(const T& data) {


  size++;

  //if list is empty, create a new node and assign head and tail
  if (!head) {

    head = std::make_shared<Node<T>> (data, nullptr);
    tail = head;
    return;

  }


  //create new node then reassign tail pointer
  tail->next = std::make_shared<Node<T>> (data, nullptr);
  tail = tail->next;

}


template<class T>
void
SinglyLinkedList<T>::pop_front() {

  if (!head) {
    throw std::runtime_error("List is empty");
  }

  if (head == tail) { //if list only has one node

      head = nullptr;
      tail = nullptr;
      size = 0;
      return;

  }

  head = head->next;
  size--;

}

template<class T>
void
SinglyLinkedList<T>::pop_back() {

  if (!head) {

    throw std::runtime_error("List is empty");

  }

  if (tail == head) {

    head = nullptr;
    tail = nullptr;
    size = 0;
    return;

  }

  std::shared_ptr<Node<T>> new_tail = head;

  //traverse to the node that precedes the last node
  for (auto it = head; it->next != tail; it = it->next) {

    new_tail = new_tail->next;

  }

  new_tail->next = nullptr;
  tail = new_tail;
  size--;

}

template<class T>
Node<T>& 
SinglyLinkedList<T>::front() {

  return *head;

}

template<class T>
Node<T>& 
SinglyLinkedList<T>::back() {

  return *tail;

}


template<class T>
void 
SinglyLinkedList<T>::insert(size_t index, const T& item) {


  size++;

  //if list empty
  if (empty()) {

    head = std::make_shared<Node<T>>(item, nullptr);
    tail = head;
    return;

  }


  //if user inserts at end
  if (index == size - 1) {

    tail->next = std::make_shared<Node<T>>(item, nullptr);
    tail = tail->next;
    return;

  }


  //otherwise traverse to index
  auto iter = head;
  for (size_t i = 0; i < index - 1; i++) {

    iter = iter->next;

  }

  std::shared_ptr temp(iter->next);

  iter->next = std::make_shared<Node<T>> (item, temp);

}


template<class T>
bool 
SinglyLinkedList<T>::remove(size_t index) {

  if (empty()) {
    return false;
  }

  if (index >= size) {// if out of bounds
    return false;
  }

  if (index == 0) { // if trying to remove from front of list

    try {

      this->pop_front();

    } catch (std::runtime_error& e) {

        return false;

    }
    
    return true;

  } else if (index == size - 1) { //if trying to remove from back of list

    try {

      this->pop_back();

    } catch (std::runtime_error& e) {

      return false;

    }

    return true;

  }

  auto it = head;

  for (size_t i = 0; i < index - 1; i++) {

    it = it->next;

  }

  it->next = it->next->next;

  size--;

  return true;
}


template<class T>
size_t 
SinglyLinkedList<T>::find(const T& item) {

  if (empty()) {
    return -1;
  }

  auto it = head;

  for (size_t i = 0; i < size - 1 && it != nullptr; i++, it = it->next) {

    if (it->data == item) {
      return i;
    }

  }

  return -1;

}