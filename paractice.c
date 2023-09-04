#include<stdio.h>
#include<stdlib.h>

//by all three structures we are making array of the linked list 
//Graphs holds the array
//head for particular head nodes in the array
//linked list for the particura arr[i]
//every arr[i] will have individual linked list which is why we are calling the array of the linked list

struct Node
{
    int data; //put the vertex number in the node so we can get at the time of traversal
    struct Node * next; //this will point for the next node linked or show the connection
};

struct List
{
    //Remember we are using here a Node data type head in List structure
    struct Node * head; // This will create the head node in the array for the vertex which holds the 
};

struct Graph
{
    int vertex; //This will hold the number of the vertices in our graph
    struct List * arr; //hold the array of the head of the vertex each will pointing at the connected vertex address 
};

//Remeber to get the array[i] linked list we have to do
//Graph->arr[1].head as array will holds head in all the index

// CREATING A GRAPH

struct Graph * adjacencyGraph(int vertexNum){
    struct Graph * g1 = (struct Graph *) malloc(sizeof(struct Graph));
    g1->vertex = vertexNum;
    //Through graph strucutre we provide list memory and pointeed with the array
    //Now array pointing to the memory of the list
    //Now we can access the head with the array 
    g1->arr = (struct List *) malloc(vertexNum * sizeof(struct List));

    int i;

    for ( i = 0; i < vertexNum; i++)
    {
        //This how we can access the head which is of the list structure and we are accessing with the 
        //help of array indexing and putting all null
        g1->arr[i].head = NULL;  
    }
    //We are putting all null coz if its null we make a linked list with the vertex and all its connected 
    //graph to it like source all the destination routes connected to it like o->1->2 
    //If in case o is connected to both 1 and 2
    //If not null which means we already have visitted this vertex and already found a linked list insidit
    //We travel its linked list to last node till we find a null node pointer and connect a new connenction in
    //there 

    return g1;   

}

struct Node * createNode(int x){
    struct Node * q =(struct Node *) malloc(sizeof(struct Node));
    //X is the value which are the other vertex which shows the connection to the source
    q->data = x;
    q->next = NULL;

    return q;   


}

void addEdge(struct Graph * g, int src, int dest){
    //Adding an edge from source(src) to (dest) 
    //supoose source is 0 and 1 and 2 are the connection which are the destination here
    //Source is added in the beginning of the linked list

    struct Node * temp = createNode(dest);
    temp->next = g->arr[src].head;
    g->arr[src].head = temp; 

}

void printGraph(struct Graph * g){
    int v;
    struct Node * traverse;
    for ( v = 0; v < g->vertex; v++)
    {
        traverse = g->arr[v].head;
        printf("\n ADjacencry List of the vertex %d\n head ", v);
        while (traverse !=NULL)
        {
            printf("->%d", traverse->data);
            traverse = traverse->next;
        }
        
    }
    
}
int main()
{

    //But this adjacency list have problem of duplicacy so check better later
    int v = 5;
    struct Graph * gListGraph = adjacencyGraph(v);
    addEdge(gListGraph, 0, 1);
    addEdge(gListGraph, 0, 4);
    addEdge(gListGraph, 1, 2);
    addEdge(gListGraph, 1, 3);
    addEdge(gListGraph, 1, 4);
    addEdge(gListGraph, 2, 3);
    addEdge(gListGraph, 3, 4);

    printGraph(gListGraph);

    return 0;
}





