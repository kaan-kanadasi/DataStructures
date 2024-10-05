// abstrack data types: example. - queues and stacks

#include <stdio.h>
#include <stdlib.h> 
#define CAPACITY 50

typedef struct
{
    char *name;
    char *number;
}
Person;

/* queues charesteristic called FIFO (first in first out)
    - enqueue
    - dequeue
waiting for a dining hall line
shipping cargo to firstly to the first buyer
*/ 

typedef struct
{
    Person people[CAPACITY];
    int size;
} queue;


/* staks charesteristic called LIFO (last in first out)
    - push 
    - pop
gmail - we want to see the eamils that came at last
spotify - we want to see the most recent liked songs 
*/ 
typedef struct
{
    Person people[CAPACITY];
    int size;
} stack;


/* 
linked list - what if our data in the memory is not contiguous like an array
ex. there are three integers in seperated places of the memory 
to link these integers we should assign pointers to each of the integers
    - first int is assigned the second int's adress
    - second int is assigned the third int's adress
    - third int is assigned the NULL (0x0) to terminate the list
    - one extra poitner is used to find the first int 
the integers are data that we use and the adresses that we keep with each int is the meta data of that int
*/
typedef struct node // if we didn't had the name "node" here, the node variable within the node wouldn't exist
{
    int number;
    struct node *next; // This is how the linked list will "link" each node to the next one
} node;


/*
array - {1,2,3,4,5,6,7}
binary search trees - 
               4
           2       6
         1   3   5   7
*/
typedef struct node_tree 
{
    int number;
    struct node_tree *left; 
    struct node_tree *right; 
} node_tree;


// dictionaries - keys: values

// hashing - taking some number of inputs and mapping it to a finite number of outputs
// HASH TABLE -> vetical: array - horizontal: linked list / array of linked lists 
// hash table is O(n) since an array could have only one element in the array with the linked list
typedef struct node_hash
{
    int *name;
    char *number;
    struct node_hash *next; 
} node_hash;


// trie - tree of arrays 
// takes hughe memeory but has O(1)
typedef struct node_trie
{
    struct node_hash *children[26]; 
    char *number;
} node_trie;




int main(int argc, char *argv[]) 
{
    int *list = malloc(3 * sizeof(int)); // asking mallock for a size of three integers
    if(list == NULL) { // error checking
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // realizing that we actually needed 4 integers
    int *tmp = malloc(4 * sizeof(int));
    if(tmp == NULL) { // error checking
        free(list); // if we get up to this stage, the memory for list has been used and we must free it before aborting the program
        return 1;
    }

    for(int i = 0; i<3; i++) {
        tmp[i] = list[i];
    }
    tmp[3] = list[3];

    free(list); // clean the data of the original list
    list = tmp; // to point the tmp to list

    for(int i = 0; i<4; i++) {
        printf("%i\n", list[i]);
    }
    free(list); // clean the data of the pointed list
    


    // reverse order - prepending (O(1))
    node *list2 = NULL; // This initializes list as a pointer to the first node in the linked list.

    // for loop starts from i = 1 because argv[0] contains the program name
    for(int i=1; i < argc; i++) {
        int number = atoi(argv[i]); // use atoi() (ASCII to Integer) to convert from char* to int
        node *n = malloc(sizeof(node));
        if(n == NULL) {
            free(n);
            return 1;
        }
        n->number = number; // n->number equals (*n).number = 1;
        n->next = list2; // the next pointer of the new node is set to point to the current head of the list (list).
        list2 = n; // makes list poitn to the same thing that n points to 
    }
    node *ptr = list2;
    while(ptr != NULL) // so that the poitner is not at the end of the list
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // Move ptr from the current node to the next one in the chain
    }



    // sorted order - appending (O(N))
    node *list3 = NULL; // Memmory for numbers

    for(int i=1; i < argc; i++) {
        int number = atoi(argv[i]); 
        node *n = malloc(sizeof(node));
        if(n == NULL) {
            free(n);
            return 1;
        }
        n->number = number;
        n->next = NULL; 

        // If list is empty
        if(list3 == NULL) {
            // This node is the whole list
            list3 = n;
        } 
        // if number belongs at the beggining of the list
        else if (n->number < list3->number) {
            n->next = list3;
            list3 = n;
        }
        // if number belongs ater in the list
        else {
            // Iterate over nodes in list
            for(node *ptr= list3; ptr != NULL; ptr = ptr->next) {
                // If at end of lsit
                if(ptr->next == NULL) {
                    // Append node
                    ptr->next = n;
                    break;
                }

                if(n->number < ptr->next->number) {
                    n->next= ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }
} 

// binary search tree - python
/* 
bool search(node_tree *tree, int number) {
    if(tree == NULL) {
        return false; 
    } else if(number < tree->number) {
        return search(tree->left, number); // recursion
    } else if(number > tree->number) {
        return search(tree->right, number); // recursion
    } else {
        return true;
    }
}
*/ 