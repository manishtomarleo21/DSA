#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){

    while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
    }
}

//Case 1: Deleting the first node from the linked list

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head; //We are creating the new pointer to free the memory which is taking extra the deleted head node
    head = head->next;

    free(ptr);
    return head;
}

//Case 2: Deleting the node from the linked list by given index
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
    

}

//Case 3: Deleting the node from the linked list by given element or value
struct Node * deleteByElement(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value){}
    {
        p->next = q->next;
        free(q);
    }
    
    return head;

}

//Case 4: Deleting the LAST node 
struct Node * deleteLastNode(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;

}


int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    (*head).data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    printf("\nLinked list after deletion\n");
    //case 1
    head = deleteFirst(head); //I can run it as many times to delelte the first element in the linked list
    linkedListTraversal(head);

    //case 2 
    //delete at index
   head = deleteAtIndex(head, 1);
    linkedListTraversal(head);

    //CAse 3
    // delete by the value or given element
    head = deleteByElement(head, 11);
    linkedListTraversal(head);

    //CAse 4
    // delete the last node
    head = deleteLastNode(head);
    linkedListTraversal(head);


    //RUN ALL THE CASES ONE BY ONE OR ELSE ELEMENTS WONT BE AVAILABLE

    return 0;
}
