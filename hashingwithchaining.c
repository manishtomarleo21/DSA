#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

//This is second kind check the first one which is hashing with linear probbing
//AS this is with
//EXternal chaininh with linked list


//Hasinh is key value and hashmap is function which is in c++.  Here we are seeinh hshing in c with collison 

#define MAX_NAME 256
#define TABLE_SIZE 10

//3.
// Now we are getting the hash key from the name randomly and will get the same evertytime we put the right name
//SO we create a hash Table with the help of array pointer
//here person is struct which is coz we are using the typedef struct gives the nicknames
//ITS a struct type array 
//We are also making a pointer incase its empty we can point at in by NULL
struct Person * hash_table[TABLE_SIZE];



// 1
struct Person
{
    char name[MAX_NAME];
    int age;
    struct Person * next; // for extrenal chaining only
};


//2
//Hash function it will convert a name into hash so it can genrate a unique key so which can store in the
//HASH table
unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME); //getting lenth of the name
    //We created a positive integer initialized to 0
    unsigned int hash_value = 0;
    //AS we knoq ki hr letter ki ek ASCAII value hoti h 
    //vh hr ek letter ki hm add krte jaunge jb the letter length hogi loop add krta rhega
    //value are like of the letter is j = 74,c = 88, 
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        //printf("%d, ", name[i]);//ASCAII vals
        
        //THe value are still small and we need more random so we multiply as well to get more random numa
        //hash_value = hash_value * name[i]; //Now this will give me the large num as  2450819062 but we need
        
        //around the table size as we use modulus % with the Table size which is 10 which will give remainder
        hash_value = (hash_value * name[i]) % TABLE_SIZE; //now i will get from 0 to 9 only 
    }

    //We are returninh the names value which will provide letter the  search key
    //which we will take out mod and convert it into the hash key
    return hash_value; 
}

//4. INITIALIZIG hast\h table with NULL in start
void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    //now table is empty
    

}

//5 
//WE will print the table fully if there is in something
void print_table(){
    printf("Start\n"); //MArker for output only
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---", i);
        }
        else{
            printf("\t%i\t ", i);
            struct Person * temp = hash_table[i];
            while (temp!=NULL)
            {
                printf("%s - ", temp->name);
                temp = temp->next;
            }
            
        printf("\n");   
        }
        printf("\n");  
    }
    printf("End\n"); //MArker for output only
}

//6
//Insert function by which we can enter the person in the table
//as we know this function will return true or false on the succession or failure

bool hash_table_insert(struct Person * p){
    //if the struct person is null it will return false or not entered in the table
    if (p == NULL) return false;
    //We saw already that hash function convert the name and return the hash key which mod by size 
    //and we call as hash key which is from 0-9 here we use as index in the hash table
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    
    return true;
   
    
}

//8.
//Lookup or search function 
//Find a person in the table by the name which return pointer struct and takes name address
struct Person * hash_table_lookup(char *name){
    int index = hash(name); //This will give hash key again we type any name 
    struct Person * temp = hash_table[index];
    while (temp != NULL && strncmp(temp->name, name, MAX_NAME) !=0)
    {
        temp = temp->next;
    }
    return temp;
    

    
}

//10.
//Delete Function
//Its same like insert func
//As we again have to search to delete right
struct Person * hash_table_delete(char *name){
    int index = hash(name); //This will give hash key again we type any name 
    struct Person * temp = hash_table[index];
    struct Person * prev = NULL;
    while (temp != NULL && strncmp(temp->name, name, MAX_NAME) !=0)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return NULL;
    if(prev == NULL){
        //deleting the head
        hash_table[index] = temp->next;
    }else{
        prev->next = temp->next;
    }
    return temp;
    
}


int main()
{
    //WE start with the clean slate so in the beginning of the program we run this
    // to make it NULL
    init_hash_table();
    print_table();


    //7.
    //Now add preson with the help of funciotn
    struct Person Jacob = {.name = "Jacob", .age=25}; 
    struct Person Nick = {.name = "Nick", .age=26}; 
    struct Person Abel = {.name = "Abel", .age=31}; 
    struct Person Justin = {.name = "Justin", .age=29}; 
    struct Person Joe = {.name = "Joe", .age=32}; 
    struct Person Randy = {.name = "Randy", .age=42}; 
    struct Person Alexa = {.name = "Alexa", .age=32}; 
    struct Person Demi = {.name = "Demi", .age=33}; 
    struct Person Manish = {.name = "Manish", .age=33}; 
   
    hash_table_insert(&Jacob);
    hash_table_insert(&Nick);
    hash_table_insert(&Abel);
    hash_table_insert(&Justin);
    hash_table_insert(&Manish);
    hash_table_insert(&Joe);
    hash_table_insert(&Randy);
    hash_table_insert(&Alexa);
    hash_table_insert(&Demi);

    print_table();

    //9.
    // Now We try to lookup a person in in their in the table or not
    struct Person * temp = hash_table_lookup("Selena");
    if(temp == NULL){
        printf("Not Found\n");
    }else{
        printf("Found : %s\n", temp->name);
    }

    //Same for the person if name is there
    temp = hash_table_lookup("Abel");
    if(temp == NULL){
        printf("Not Found\n");
    }else{
        printf("Found : %s\n", temp->name);
    }

    // 11 
    // let delete a name
    hash_table_delete("Jacob");
    print_table();

    /*
    Now evrythinh with the hashtable has done onlu reamining thing is the collision which is done by two 
    diffrent mathods 1. extrernal chaining which is basically linked list takes extra space
    2. is open addressing will moved to next slop if collided n next slot is empty 
    //Open addressing are of three typed Linear probing, Quadratic probing, double hashing

    */

    // printf("Jacob => %u\n", hash("Jacob"));


    //*****************ENDING***********************
    //THEre is advantage or disadvantage of the linear probbing
    //ADV is it doesnt take space as external chaining as linear uses next empty slot incase of collision
    //DIs advantage is array can be fulled as we cannot change size of the array

    return 0;
}

