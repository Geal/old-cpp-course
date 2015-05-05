#include <iostream>
#include <memory>

using std::string;

template<class T>
class Option {
  public:
    virtual bool is_some() = 0;
    virtual T    get()     = 0;
};

template<class T>
class None: public Option<T> {
  public:
                 None<T>();
    virtual bool is_some();
    virtual T    get();
};

template<class T>
None<T>::None() {
}

template<class T>
bool None<T>::is_some() {
  return false;
}

template<class T>
T None<T>::get() {
  throw;
}

template<class T>
class Some: public Option<T> {
  private:
    T value;

  public:
                 Some<T>(T val);
    virtual bool is_some();
    virtual T    get();
};

template<class T>
Some<T>::Some(T val) {
  this->value = val;
}

template<class T>
bool Some<T>::is_some() {
  return true;
}

template<class T>
T Some<T>::get() {
  return value;
}

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
  void       push(T val);
  void       pop();
  int        length();
  Option<T>* get(int position);
};


int main() {
  int count = 0;
  LinkedList<string> l1 = LinkedList<string>(string("abc"));

  l1.push("def");

  Option<string>* res = l1.get(1);
  if(res->is_some()) {
    std::cout << "val: " << res->get() << std::endl;
  }

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
Option<T>* LinkedList<T>::get(int position) {
  Node<T>* tmp = this->list;
  int val = 0;
  while(tmp != 0) {
    if(val == position) {
      return new Some<T>(tmp->value);
    }

    tmp = tmp->next;
    val++;
  }

  return new None<T>();
}
