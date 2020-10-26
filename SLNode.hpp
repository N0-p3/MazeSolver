template <typename T>
class SLNode {
public:
  T data;
  SLNode<T>* next;

  SLNode(T d, SLNode<T>* n) {
    data = d;
    next = n;
  }
};
