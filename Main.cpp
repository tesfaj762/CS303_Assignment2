#include <iostream>
#include "SinglyList.h"
#include "Stack.h"

using list = SinglyLinkedList<int>;


void test_stack();
void test_list();

int main () {

  test_stack();
  test_list();

  return 0;
}

void test_stack() {

  Stack<int> stack1;
  std::cout << "\n\n----------------------------------Stack----------------------------------\n";
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);
  stack1.push(4);

  std::cout << "Current top: " << stack1.top() << std::endl;

  stack1.pop();
  stack1.pop();

  stack1.push(2);
  stack1.push(3);
  stack1.push(5);

  std::cout << "Current top: " << stack1.top() << std::endl;
  std::cout << "Current average: " << stack1.average() << std::endl;


}

void test_list() {

  list list;
  std::cout << "\n\n------------------------------------List--------------------------------\n";

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_back(0);

  list.push_back(-1);
  list.push_back(-2);
  list.push_back(-3);

  std::cout << "Current List: ";
  for (auto it = list.head_ptr(); it != nullptr; it = it->next) {

    std::cout << it->data << " ";

  }

  list.pop_back();
  list.pop_back();
  list.pop_front();
  list.pop_front();

  std::cout << "\nCurrent List after pops: ";
  for (auto it = list.head_ptr(); it != nullptr; it = it->next) {

    std::cout << it->data << " ";

  }

  std::cout << "\nFinding 100...\n";
  if(int index = list.find(100) > 0) {
    std::cout << "\nFound 100\n";
  } else {
    std::cout << "\nCould not find 100\n";
  }

  std::cout << "Finding 1...\n";
  if(int index = list.find(100) > 0) {
    std::cout << "Found 1 at index: " << index << "\n";
  } else {
    std::cout << "Could not find 1\n";
  }

  std::cout << "Removing first index...\n";
  list.remove(0);
  std::cout << "Current front node: " << list.front().data << std::endl;

  std::cout << "Inserting 100 at index 1\n";
  list.insert(1, 100);

  std::cout << "inserting 200 at index 1 again...\n";
  list.insert(1, 200);


  std::cout << "Current List: ";
  for (auto it = list.head_ptr(); it != nullptr; it = it->next) {

    std::cout << it->data << " ";

  }

  std::cout << "\nRemoving index 2...\n";
  list.remove(2);

  std::cout << "Current List: ";
  for (auto it = list.head_ptr(); it != nullptr; it = it->next) {

    std::cout << it->data << " ";

  }

  std::cout << std::endl;




}