#include <iostream>
#include <memory>

using std::string;

template <typename T>
struct LinkedList {
  T              value;
  LinkedList<T>* next;
};

template <typename T> LinkedList<T>* create(T val);
template <typename T> LinkedList<T>* push(LinkedList<T>*, T val);
template <typename T> LinkedList<T>* pop(LinkedList<T>* l);
template <typename T> int            length(LinkedList<T>* l);
template <typename T> T              get(LinkedList<T>* l, int position);

typedef std::shared_ptr<LinkedList<string> > StringListPtr;


int main() {
  int count = 0;
  /*while(count < 100) {
    LinkedList* l = create(1);
    std::cout << "val: " << get(l, 0) << std::endl;

    LinkedList* l2 = push(l, 3);
    std::cout << "val2:  " << get(l2, 0) << " " << get(l2, 1) << std::endl;
    count += l2->value;
    std::cout << count << std::endl;
    LinkedList* l3 = pop(l2);
    LinkedList* l4 = pop(l3);
    std::cout << "val: " << get(l4, 0) << std::endl;

  }*/
  LinkedList<string> * l1 = create(string("abc"));
  //std::shared_ptr<LinkedList<string> > l(l1);
  StringListPtr l(l1);
  l->value = 1;
  std::weak_ptr<LinkedList<string> > l2 = l;

  //l->value = 10;
  //delete l.get();
  //l.reset();

  std::shared_ptr<LinkedList<string> > l3 = l2.lock();
  l3->value = "def";
  //std::cout << "val: " <<l ->value << std::endl;
  std::cout << "val: " << l3->value << std::endl;

  //l2.reset();
  return count;
}


template <typename T>
LinkedList<T>* create(T val) {
  LinkedList<T>* l = new LinkedList<T>;
  l->value = val;
  l->next  = 0;
  return l;
}

template <typename T>
LinkedList<T>* push(LinkedList<T>* l, T val) {
  LinkedList<T>* l2 = new LinkedList<T>;
  l2->value = val;
  l2->next  = l;
  return l2;
}

template <typename T>
LinkedList<T>* pop(LinkedList<T>* l) {
  LinkedList<T>* l2 = l->next;
  delete l;
  return l2;
}

template <typename T>
int length(LinkedList<T>* l) {
  if (l == 0) {
    return 0;
  } else {
    return 1 + length(l->next);
  }
}

template <typename T>
T get(LinkedList<T>* l, int position) {
  if(l == 0) {
    throw;
  }

  if(position == 0) {
    return l->value;
  } else {
    return get(l->next, position - 1);
  }
}
