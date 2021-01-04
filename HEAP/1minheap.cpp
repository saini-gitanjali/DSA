//implementing max heap from scratch using array and recursion

#include<iostream>
using namespace std;

class heap{
    int *arr;
    int s;
    int curr;
    
    public:
        heap(int n);
        void buildheap(int el);
        void print();
        int leftchild(int n);
        int rightchild(int n);
        void heapify( int n);
        void deleteEl(int el);
};

heap :: heap(int n){
    arr = new int[n];
    s = n;
    curr = 1;
}

void heap :: buildheap(int el)
{
    //cout<<curr<<" ";
    int i = curr-1;
    if(i>0&&el>arr[(i-1)/2]){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = el;
    curr++;
    //cout<<arr[curr-1]<<" "<<curr;
}

void heap :: print(){
    cout<<endl<<"Array representation of max-heap is : ";
    for(int i=0; i<s; i++)
        cout<<arr[i]<<" ";
}

int heap :: leftchild(int n){
    return 2*n+1;
}
int heap :: rightchild(int n){
    return 2*n+2;
}

void heap :: deleteEl(int el){
    int temp;
    for(int i=0; i<curr; i++)
        if(el == arr[i])
        {
            
        }

}
void heap :: heapify(int n){

}

int main(){
    int n, data;
    cin>>n; 
    heap h(n);
    for(int i=0;i<n; i++)
    {
        cin>>data;  
        h.buildheap(data);
    }
    h.print();
    return 0;

}