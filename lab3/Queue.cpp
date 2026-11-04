#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int count;
    int first;

public:
    Queue(int maxSize) {
        capacity = maxSize;
        arr = new int[capacity];
        count = 0;
        first = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    int& enqueue(int value) {
        if (isFull()) {
            throw "Queue is full!";
        }

        int pos = (first + count) % capacity;
        arr[pos] = value;
        count++;

        return arr[pos];
    }

    int dequeue() {
        if (isEmpty()) {
            throw "Queue is empty!";
        }

        int value = arr[first];
        first = (first + 1) % capacity;
        count--;

        return value;
    }

    const int& front() const {
        if (isEmpty()) {
            throw "Queue is empty!";
        }

        return arr[first];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }

    const int& get(int index) const {
        if (index < 0 || index >= count) {
            throw "Invalid index!";
        }

        return arr[(first + index) % capacity];
    }
};

void mergeQueues(const Queue& q1,
                 const Queue& q2,
                 Queue& result) {

    int n1 = q1.size();
    int n2 = q2.size();

    int maxSize = (n1 > n2) ? n1 : n2;

    for (int i = 0; i < maxSize; i++) {

        if (i < n1) {
            result.enqueue(q1.get(i));
        }

        if (i < n2) {
            result.enqueue(q2.get(i));
        }
    }
}

int main() {

    Queue q1(3);
    Queue q2(3);
    Queue result(6);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);

    mergeQueues(q1, q2, result);

    cout << "Merged queue: ";

    while (!result.isEmpty()) {
        cout << result.dequeue() << " ";
    }

    return 0;
}
