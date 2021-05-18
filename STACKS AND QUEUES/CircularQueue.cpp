#include<iostream>

using namespace std;
class queue {
    int size, front, rear;
    int *arr;
    public:
    queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    void enqueue(int);
    int  dequeue();
    void print();
};


void queue :: enqueue(int data) {
    if((front == -1)&&(rear == -1))
    {
        arr[++rear] = data;
        front = 0;
        return;
    }
    if((front == 0 && rear == size-1) || (front == rear+1))
    {
        cout<<"queue Full!!";
        return;
    }
    arr[++rear] = data;
}

int queue :: dequeue() {
    int res ;
    if(front == -1)
       res = -1;
    res = arr[front];

    if(front ==  rear){
        front = -1;
        rear = -1;
    }
    else if(front == size-1)
        front = 0;
    else
        front++;
    return res;
}

void queue :: print() {
     if(front < rear)
        for(int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
    else {
        for (int i = front; i < size-1; i++)
            cout<<arr[i]<<" ";
        for(int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
        
    }
}

int main() {
    int elt, choice, n, qq;
    cin>>n;
    queue q(n);
    cin>>qq;
    cin>>choice;
    for(int i =0; i<qq; i++)
    {
        cout<<"bvhj";
        if(choice == 1){
            cin>>elt;
            q.enqueue(elt);
        }
        else if(choice == 2)
            {
                int a = q.dequeue();
                if(a == -1)
                    cout<<"queue empty";
                else
                    cout<<a;
            }
        else
            q.print();
        cin>>choice;
    }
    return 0;
}