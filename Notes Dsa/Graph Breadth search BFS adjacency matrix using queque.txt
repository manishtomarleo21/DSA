#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int r; //rear tracker for index when pushing it goes up,, initially -1
    int f; // for front when we pop the element from the queue it goes up the 1
    int * arr;
};

int isFull(struct Queue * q){
    if (q->r == q->size-1)
    {
        return 1;
    }
    return 0;
    
}

int isEmpty(struct Queue * q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
    
}



void enqueue(struct Queue * q, int val){
    if (isFull(q))
    {
        printf("This Queue is Full");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
    
}

int dequeue(struct Queue * q){
    int a =-1;
    if (isEmpty(q))
    {
        printf("This Queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}   

int main()
{
    struct Queue q;
    q.size = 200;
    q.r = q.f = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    // Breadth First Search Implementation 
    int u; //this will the exporation index also for the matrix left side index which will choose which row
    int i = 1;

    int visited[7] = {0,0,0,0,0,0,0};
    //Adjacency Matrix 7 by 7

    //This is Adjacency Matrix 7 by 7 representation for the graph the node which is connected mark by the 1
    //the one are not marked by the 0
    int a[7][7] = {
     
        {0,1,1,1,0,0,0}, //0
        {1,0,0,1,0,0,0}, //1
        {1,0,0,1,1,0,0}, //2
        {0,1,1,0,1,0,0}, //3
        {0,0,1,1,0,1,1}, //4
        {0,0,0,0,1,0,0}, //5
        {0,0,0,0,1,0,0}  //6
    };

    printf("%d, ", i);
    visited[i] = 1;

    enqueue(&q, i);

    while (!isEmpty(&q))
    {
        u = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[u][j] == 1 && visited[j] == 0)
            {
                printf("%d, ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
            
        }
        
    }
    

    return 0;
}
