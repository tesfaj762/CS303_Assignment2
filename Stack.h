
#ifndef STACK_H
#define STACK_H

#include <vector>

template<class T>
class Stack {
public:

  Stack();
  Stack(size_t cap);

  ~Stack() = default;

  void push(T item);

  T pop();

  T& top();

  float average();

private:

  std::vector<T> stack;
  size_t size;

};

#include "Stack.tpp"

#endif