#include<iostream>
#include<queue>

using namespace std;

//This is max heap in it get assumed like a complete binary tree
//alwasy parent node will be bigger than the children node
//We insert one by one and save it in an arrray and increase the array size one by one
//We always insert in the end and compare with the parent node if the insertion is bigger or not frmo the parent
//if its we will swap to parent and do it till it satisfy the conditions
//to get the parent node alway devide the index by 2 
//INserion time complexity O(log-n)

class Heap
{
    public:
    int arr[50];
    int size;
    Heap(){
        arr[0] = -1; //we use heap from array from 1 index
        size = 0;

    }

    void insert(int val){
        size = size + 1; //Whenever we insert in the heap it will put in this poistion meand last index
        int index  = size; //this  will index that we wanna put in
        arr[index] = val;


    
        while (index > 1) //till we go to root node
        {   //parent will always be index(i)/2 left node will be 2*i and right node will be 2*i+1
            int parent = index/2;//we are getting parent node by the index

            //for max heap
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                //updating the index 
                //now index will point at parent so now after swapping we can check that upper node is 
                //lie in same condition or not //that its bigger or not of its new poistion parent
                index = parent;
            }
            else{
                return ;
            }
        }
        
    }

    //IN deelteion we need four steps 
    // 1. deletion of the root node
        //a. put last index vaalue of the array to index one so this will overright the root node value 
        //b free(lastindex) or delete it 
        //c. now again comapre the new last indexwhihch is root node now to make it max heap again
        //compare and swith the bigger value to upwards
    void deletefromHeap(){
        if (size==0)
        {
            cout<<"Nothig to delete Heap empty"<<endl;
        }
        arr[1] = arr[size];//putting last node to one to delete the root node
        size--; //making not acesable the last value or deleting

        //now c step to compare and put it on the right place of its
        int i=1;
        while (i<size)
        {
            int leftIndex = 2*i; //as we know this will give the left side node of every level
            int rightIndex = 2*i+1; //this will give the right node of the evry CBT

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return ;
            }
            
        }
        

        
    }


    void printHeap(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }

};

//Heapify basically checks the node and put the node  in right positoin and CBT into
//Heap max or heap min which depends
//in an array length of n -> (n/2+1 to n) are leaf nodes in last which we dont have to check
//so we put heapify process from 1 to n/2

//From an array ercursively we can convert it into heap

void heapify(int arr[], int size, int ind){ //index which we wanna heapyfiy
    int largestVal = ind;
    int leftINd = 2*ind;
    int rightINd = 2*ind+1;

    if (leftINd <= size && arr[largestVal] < arr[leftINd])
    {
        largestVal = leftINd;
    }
    if (rightINd <= size && arr[largestVal] < arr[rightINd])
    {
        largestVal = rightINd;
    }
    if (largestVal!=ind)
    {
        swap(arr[largestVal], arr[ind]);
        heapify(arr, size, largestVal);

    }
 
}

//heap sort
//this will sort in ascending order the heapify created heap max in sorted array
// TC O(nlogn)
void heapSort(int arr[], int size){
    //first step swap the last insed to first then and heapify again till largest val come to the top
    //and we will size-- so next time we sort till n-1
    // and we run this till size is equal to one
    while (size>1)
    {
        //swapping
        swap(arr[size], arr[1]);
        size--;

        //heapifying again
        heapify(arr, size, 1);//it will heapif from one index n put into its orginal postion 
        //here 1 will be the last index val which is swapped
    }
    
}





int main()
{
    Heap h;
    h.insert(60);
    h.insert(40);
    h.insert(50);
    h.insert(45);
    h.insert(42);
    h.printHeap();

    h.deletefromHeap();
    h.printHeap();

    int arr[6] = {-1, 60, 40, 50, 45, 42};
    int n = 5;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout<<"printing the heapify sorted array"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"Heap sort"<<endl;
    heapSort(arr, n);
     for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }


    //To use this all function with STL include queue
    //maxheap
    // priority_queue<int> pq;
    // pq.push(5);
    // pq.push(10);
    // pq.top();
    // pq.pop();
    
    //minHeap
    // priority_queue<int, vector<int>, greater<int> > minhp;
    //this will create minheap
    
    return 0;
}
