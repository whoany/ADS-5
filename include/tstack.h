// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T data[size];
    int top;

 public:
    TStack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }

    void push(T value) {
        if (!isFull()) {
            top++;
            data[top] = value;
        }
    }

    T pop() {
        T value = data[top];
        top--;
        return value;
    }

    T peek() const {
        return data[top];
    }
};

#endif  // INCLUDE_TSTACK_H_
