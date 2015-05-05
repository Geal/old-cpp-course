#include <iostream>
#include <memory>

#include "option.hpp"
#include "result.hpp"

using std::string;
template<class T>
struct Node {
  T value;
  Node<T>* next;
};

template <typename T>
class LinkedList {
  private:
  Node<T>* list;

  public:
                    LinkedList<T> (T val);
  void              push(T val);
  void              pop();
  int               length();
  Result<T,string>* get(int position);
};


int main() {
  int count = 0;
  LinkedList<string> l1 = LinkedList<string>(string("abc"));

  l1.push("def");

  Result<string,string>* res = l1.get(1);
  if(res->is_ok()) {
    std::cout << "val: " << res->get() << std::endl;
  }
  Option<string>* opt = res->to_option();
  if(opt->is_some()) {
    std::cout << "val: " << opt->get() << std::endl;
  }
  delete opt;
  delete res;

  std::cout << "length: " << l1.length() << std::endl;

  l1.pop();
  //l2.reset();
  return count;
}


template <typename T>
LinkedList<T>::LinkedList(T val) {
  Node<T>* l = new Node<T>;
  l->value = val;
  l->next  = 0;
  this->list = l;
}

template <typename T>
void LinkedList<T>::push(T val) {
  Node<T>* l2 = new Node<T>;
  l2->value = val;
  l2->next  = this->list;

  this->list = l2;
}

template <typename T>
void LinkedList<T>::pop() {
  if(this->list == 0) {
    throw;
  }

  Node<T>* l = this->list->next;
  delete this->list;

  this->list = l;
}

template <typename T>
int LinkedList<T>::length() {
  Node<T>* tmp = this->list;
  int val = 0;
  while(tmp != 0) {
    tmp = tmp->next;
    val++;
  }

  return val;
}

template <typename T>
Result<T,string>* LinkedList<T>::get(int position) {
  Node<T>* tmp = this->list;
  int val = 0;
  while(tmp != 0) {
    if(val == position) {
      return new Ok<T,string>(tmp->value);
    }

    tmp = tmp->next;
    val++;
  }

  return new Err<T,string>("not found");
}
