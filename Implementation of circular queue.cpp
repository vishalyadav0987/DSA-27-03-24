class MyCircularQueue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    MyCircularQueue(int k)
    {
        front = -1;
        rear = -1;
        size = k;
        arr = new int[size];
    }

    bool enQueue(int value)
    {
        // check wheater queue if full;
        if ((rear + 1) % size == front)
        {
            return false;
        }
        // when queue is empty
        // insert element at 1st postion
        if (front == -1)
        {
            front = rear = 0;
            // arr[rear] = value;
        }
        // when rear at size - 1 and front>0
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cylic nature
            // arr[rear] = value;
        }
        // normal condn
        else
        {
            rear++;
            // arr[rear] = value;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        // check emepty or noy
        if (front == -1)
        {
            return false;
            cout << "Queue is empty";
        }
        int ans = arr[front];
        arr[front] = -1;
        // when queue have single element
        if (rear == front)
        {
            rear = front = -1;
        }
        // when front at end pop from end
        else if (front == size - 1)
        {
            front = 0; // maintain cylic order
        }
        else
        {
            front++;
        }
        return true;
    }

    int Front()
    {
        if (front != -1)
        {
            return arr[front];
        }
        return -1;
    }

    int Rear()
    {
        if (rear != -1)
        {
            return arr[rear];
        }
        return -1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        // check wheater queue if full;
        if ((rear + 1) % size == front)
        {
            return true;
            cout << "Queue is full";
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */