// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
    T* arr;
    int size;
    int begin,
        end;
    int count;
 public:
    TPQueue(int = 100);
    ~TPQueue();
    void push(const T&);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template<typename T>
TPQueue<T>::~TPQueue() {
    delete[] arr;
}

template<typename T>
void TPQueue<T>::push(const T& item) {
    assert(count < size);

    int i = end;
    while (arr[i-1].prior > 0 && arr[i-1].prior < item.prior) {
        i--;
    }
    for (int j = end - 1; j >= i; j--) {
        arr[j + 1] = arr[j];
    }
    arr[i] = item;
    end++;
    count++;

    if (end > size) end -= size + 1;
}

template<typename T>
T TPQueue<T>::pop() {
    assert(count > 0);
    T item = arr[begin++];
    count--;
    if (begin > size)
        begin -= size + 1;
    return item;
}

template<typename T>
T TPQueue<T>::get() const {
    assert(count > 0);
    return arr[begin];
}

template<typename T>
bool TPQueue<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
bool TPQueue<T>::isFull() const {
    return count == size;
}

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
