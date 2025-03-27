

#include "Stack.h"
#include <numeric>


template<class T>
Stack<T>::Stack()
: stack()
, size(0)
{
}



template<class T>
Stack<T>::Stack(size_t cap)
: stack(cap)
, size(0)
{
}



template<class T>
void
Stack<T>::push(T item)
{
  stack.push_back(item);
  size++;
}



template<class T>
T
Stack<T>::pop()
{

  if (stack.empty()) {
    throw std::runtime_error("Stack is empty");
  } 

  int val = stack[size - 1]; 
  stack.pop_back(); //remove top element
  size--;

  return val; 

}



template<class T>
T&
Stack<T>::top()
{

  if (stack.empty()) { //check if empty

    throw std::runtime_error("Stack is empty");

  }

  return stack[size - 1]; //return top

}


template<class T>
float
Stack<T>::average()
{
  
  if (stack.empty()) {

    return 0;
  }

  float sum = std::accumulate(stack.begin(), stack.end(),0);
  return sum / size;

}



