#include <bits/stdc++.h>
using namespace std;

class CircularDeque
{
public:
    int *arr;
    int front, rear, size;
    int K;

    CircularDeque(int k)
    {
        arr = new int[k];
        front = rear = -1;
        size = 0;
        K = k;
    }

    bool insertAtFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + K) % K;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertAtLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % K;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % K;
        }
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + K) % K;
        }
        size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getBack()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == K; }

    void printDeque(CircularDeque &dq)
    {
        if (dq.isEmpty())
        {
            cout << "Deque is empty.\n";
            return;
        }

        int i = dq.front;
        while (true)
        {
            cout << dq.arr[i] << " ";

            if (i == dq.rear)
                break;
            i = (i + 1) % dq.K;
        }
        cout << endl;
    }
};

int main()
{

    CircularDeque cDeque(10);
    cDeque.insertAtFront(5);
    cDeque.insertAtFront(7);
    cDeque.insertAtFront(2);
    cDeque.insertAtFront(1);
    cDeque.insertAtFront(8);

    cout << endl;

    cDeque.insertAtLast(10);
    cDeque.insertAtLast(1);
    cDeque.insertAtLast(3);
    cDeque.insertAtLast(14);

    cout << endl;

    cout << "Front Element : " << cDeque.getFront() << endl;
    cout << "Rear Element : " << cDeque.getBack() << endl;

    cout << endl;

    cDeque.printDeque(cDeque);
    return 0;
}