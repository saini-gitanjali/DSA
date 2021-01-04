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
        //int leftchild(int n);
        //int rightchild(int n);
        void heapify(int i);
        void deleteEl(int el);
        int getMax();
};

heap :: heap(int n){
    arr = new int[n];
    s = n;
    curr = 0;
}

void heap :: buildheap(int el)
{
    //cout<<curr<<" ";
    if(curr>=s)
    {
        cout<<"\nHeap capacity full";
        return;
    }
    int i = curr;
    if(i>0&&el>arr[(i-1)/2]){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = el;
    curr++;
//  cout<<arr[curr-1]<<" ";
//   cout<<curr;
}

void heap :: print(){
    cout<<endl<<"Array representation of max-heap is : ";
    for(int i=0; i<curr; i++)
        cout<<arr[i]<<" ";
}

/*int heap :: leftchild(int n){
    return 2*n+1;
}
int heap :: rightchild(int n){
    return 2*n+2;
}
*/
void heap :: deleteEl(int el){
    int present = 0;
    for(int i=0; i<curr; i++)
        if(el == arr[i])
        {
            present = 1;
            swap(arr[i], arr[curr-1]);
        }
        if(present == 0)
        {
            cout<<"Element not present in heap";
            return;
        }
        curr--;
        cout<<"\nelement deleted";
        //print();
        heapify(0);
}

void heap :: heapify(int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int max;
    if(l <curr && arr[i] < arr[l])
        max = l;
    else 
        max = i;
    if(r <curr && arr[i] < arr[r])
        max = r;
    if(max != i){
        swap(arr[i], arr[max]);
    heapify(max);
    }
}

int heap:: getMax()
{
    return arr[0];
}
int main(){
    int n, data;
    cout<<"\nenter size of heap : ";
    cin>>n; 
    heap h(n);
    int choice1=0, choice2=0;
    do {
        cout<<"\n1.insert element into heap"
            <<"\n2. delete element from heap"
            <<"\n3. get Max element"
            <<"\n4. print array representaion of Max-heap"
            <<"\nEnter your choice : ";
        cin>>choice1;
        switch (choice1)
        {
        case 1: cout<<"\nEnter element to insert in heap : ";
                cin>>data;  
                h.buildheap(data);
                break;
        case 2: cout<<"\nEnter element to delete : ";
                cin>>data;
                h.deleteEl(data);
                break;
        case 3: cout<<h.getMax();
                break;
        case 4: h.print();
            break;
        default: cout<<"\n EXITING!!!";
                exit(0);
                break;
        }
        cout<<"\n enter 1 to continue : ";
        cin>>choice2;
    }while(choice2==1);
    /*
    for(int i=0;i<n; i++)
    {
        cin>>data;  
        h.buildheap(data);
    }
    h.print();
    int el;
    cin>>el;
    h.deleteEl(el);
    h.print();
    cout<<h.getMax();
    */return 0;

}