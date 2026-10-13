
#include <iostream>
using namespace std;

#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1)) {
        cout << "Deque is full\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    dq[front] = x;
}

void insertRear(int x) {
    if ((front == 0 && rear == SIZE - 1) ||
        (front == rear + 1)) {
        cout << "Deque is full\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deleted: " << dq[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deleted: " << dq[rear] << endl;

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        cout << "Deque is empty\n";
        return;
    }

    int i = front;

    cout << "Deque: ";
    while (true) {
        cout << dq[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main() {
    int choice, x;

    do {
        cout << "\n1. Insert Front";
        cout << "\n2. Insert Rear";
        cout << "\n3. Delete Front";
        cout << "\n4. Delete Rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertFront(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
