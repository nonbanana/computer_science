#include <stdexcept>

template <typename T> class Node {
  public:
    T data;
    Node *next;
    Node(T data) : data(std::move(data)), next(nullptr) {}
    Node(T data, Node *next) : data(data), next(next) {}
};
template <typename T> class Head {
  public:
    Node<T> *next;
    Head() : next(nullptr) {}
};

template <typename T> class LinkedList {
  private:
    Head<T> *head_;
    size_t size_ = 0;
    inline void check_index(int index)
    {
        if (index < 0 or index > this->size_) {
            throw std::out_of_range("error");
        }
    }
    inline void check_nullptr(Node<T> *node)
    {
        if (node == nullptr) {
            throw std::out_of_range("error");
        }
    }

  public:
    LinkedList() : head_(nullptr) { this->head_ = new Head<T>(); }

    T get(int index)
    {
        check_index(index);
        Node<T> *current_node = reinterpret_cast<Node<T> *>(this->head_);
        for (int i = 0; i <= index; i++) {
            current_node = current_node->next;
            check_nullptr(current_node);
        }
        return current_node->data;
    }
    T get() { this->get(0); }

    void insert(int index, T data)
    {
        check_index(index);
        Node<T> *pre_node = reinterpret_cast<Node<T> *>(this->head_);
        ;
        for (int i = 0; i < index; i++) {
            pre_node = pre_node->next;
            check_nullptr(pre_node);
        }
        Node<T> *new_node = new Node<T>(data);
        new_node->next = pre_node->next;
        pre_node->next = new_node;
        this->size_++;
    }
    void insert(T data) { this->insert(0, data); }

    void erase(int index)
    {
        check_index(index);
        Node<T> *pre_node = reinterpret_cast<Node<T> *>(this->head_);
        ;
        Node<T> *to_delete = pre_node->next;
        if (to_delete == nullptr) {
            throw std::out_of_range("error");
        }
        for (int i = 0; i < index; i++) {
            pre_node = to_delete;
            to_delete = pre_node->next;
            check_nullptr(to_delete);
        }
        pre_node->next = to_delete->next;
        delete to_delete;
        this->size_--;
    }
    // void erase() { this->erase(0); }
    size_t size() { return this->size_; }
    friend std::ostream &operator<<(std::ostream &os,
                                    LinkedList<T> const &linked_list)
    {
        for (int i = 0; i < linked_list.size(); i++) {
            os << linked_list.get(i) << " ";
        }
        return os;
    }
};
