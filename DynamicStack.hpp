#include "SLNode.hpp"
#include <stdlib.h>

template <typename T>
class Stack {
private:
  SLNode<T>* sp;
  size_t count;

public:
  Stack() {
    sp = nullptr;
    count = 0;
  }

  ~Stack() {
    while (sp)
      pop();
  }

  void push(T data) {
    sp = new SLNode<T>(data, sp);
    count++;
  }

  void pop() {
    if (sp) {
      SLNode<T>* toDelete = sp;
      sp = toDelete->next;
      delete toDelete;
      count--;
    }
  }

  T top() {
    return (sp) ? sp->data : NULL;
  }

  size_t size() {
    return count;
  }
};
