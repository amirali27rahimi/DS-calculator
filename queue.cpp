#include <iostream>
using namespace std;

// Template class for Node
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // Constructor
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Template class for Queue
template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    // Constructor
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~Queue() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Enqueue method to add an element to the end of the queue
    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Dequeue method to remove an element from the front of the queue
    T dequeue() {
        if (head == nullptr) {
            throw out_of_range("Queue is empty");
        }
        Node<T>* temp = head;
        T data = head->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return data;
    }

    // Method to display the contents of the queue
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display queue
    cout << "Queue contents: ";
    queue.display();  // Output: 10 20 30

    // Dequeue elements
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 10
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 20

    // Display queue
    cout << "Queue contents after dequeuing: ";
    queue.display();  // Output: 30

    return 0;
}
