#include <iostream>
#include <memory>

typedef struct LinkedList {
  int         value;
  LinkedList* next;
} LinkedList;

LinkedList* create(int val);
LinkedList* push(LinkedList*, int val);
LinkedList* pop(LinkedList* l);
int         length(LinkedList* l);
int         get(LinkedList* l, int position);

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
  LinkedList * l1 = create(1);
  std::shared_ptr<LinkedList> l(l1);
  l->value = 1;
  std::weak_ptr<LinkedList> l2 = l;

  //l->value = 10;
  //delete l.get();
  //l.reset();

  std::shared_ptr<LinkedList> l3 = l2.lock();
  l3->value = 3;
  //std::cout << "val: " <<l ->value << std::endl;
  std::cout << "val: " << l3->value << std::endl;

  //l2.reset();
  return count;
}



LinkedList* create(int val) {
  LinkedList* l = new LinkedList;
  l->value = val;
  l->next  = 0;
  return l;
}

LinkedList* push(LinkedList* l, int val) {
  LinkedList* l2 = new LinkedList;
  l2->value = val;
  l2->next  = l;
  return l2;
}

LinkedList* pop(LinkedList* l) {
  LinkedList* l2 = l->next;
  delete l;
  return l2;
}

int length(LinkedList* l) {
  if (l == 0) {
    return 0;
  } else {
    return 1 + length(l->next);
  }
}

int get(LinkedList* l, int position) {
  if(l == 0) {
    return -1;
  }

  if(position == 0) {
    return l->value;
  } else {
    return get(l->next, position - 1);
  }
}
