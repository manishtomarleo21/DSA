#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

//Hasinh is key value and hashmap is function which is in c++.  Here we are seeinh hshing in c with collison 

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (struct Person*) (0xFFFFFFFFFFFFFFFULL)

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
    //add another stuff later
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
        }else if (hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>", i);
        }else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
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

    //12.Starts 
    //This is later version for the collision resolution in the table with open addression 
    //Linear probing
    //This loop is probbing with the hash key as we saw the implementation that
    //If collision happend we add i int the index and mode it with the 10 or table size again 
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE; ///This is the formula i is 0 here so if found null at 0 it will
        //put the value in the array other wise will go to next slot and check its empty or not till find slot
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
        
    }
    
    /*

    //IF table index is not null measn already a data is stored at index that means a collision
    //We will check open hashing and open addression to solve collision later
    if (hash_table[index] != NULL)
    {
        return false;
    }
    //If its null then its free index so
    hash_table[index] = p; // basically the person structure pointer which we pass when calling
    return true;
    
    Dont need this code as we selected collision resolution loop above which resovlve just return false like no 
    //need to write else if null 
    //12 END
    */

   return false;
   
    
}

//8.
//Lookup or search function 
//Find a person in the table by the name which return pointer struct and takes name address
struct Person * hash_table_lookup(char *name){
    int index = hash(name); //This will give hash key again we type any name 

    //13 Start
    //STart for collision resolution
    //Adding the same logic which we added in the insert to avoid collision
    //In this if we insert at next slot we also have to check the next slot as well
    //so we keep add i untill we match the slot
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false;
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0)
    {
        return hash_table[try]; //As we know array is struct person we are returning the same at index
    }
        
    }
    return NULL;
    

    /*
    //Now we compare that the index is available or not in the table of not null and
    // strncmp is string compare function whixh is comparing the name at index and we have given is matching
    //or equal to 0 means it true matched
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE)==0)
    {
        return hash_table[index]; //As we know array is struct person we are returning the same at index
    }
    else{
        return NULL;
    }
    */

   //13 codes end 
    
}

//10.
//Delete Function
//Its same like insert func
//As we again have to search to delete right
struct Person * hash_table_delete(char *name){
    int index = hash(name); //This will give hash key again we type any name 

    //14 STARTS
    //collision deleting liner probbing
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0)
        // if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE)==0)
    {
        struct Person * temp = hash_table[try];
        //Now inplace of set of NULL we have set delted node beccause in linear probbing we have to
        //check our whole table which will make it slower tp avoid that
        //if we are checking and found that a node is deleted we will continue checking
        //if found a null slot means node usse aage nhi milega coz linear covers all
        hash_table[try] = DELETED_NODE;
        return temp; //As we know array is struct person we are returning the same at index
    }
        
    }
    return NULL;

    
    /*
    //Now we compare that the index is available or not in the table of not null and
    // strncmp is string compare function whixh is comparing the name at index and we have given is matching
    //or equal to 0 means it true matched
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE)==0)
    {
        struct Person * temp = hash_table[index]; //We found the struct index of the person and saved in temp
        hash_table[index] = NULL; //nullify in the array marked as delete 
        return temp; // returnig the deleted struct of person index
    }
    else{
        return NULL;
    }
    */
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

