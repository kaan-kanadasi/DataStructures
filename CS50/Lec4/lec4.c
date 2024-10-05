// hexadecimal math 16(n1) + 1(n2) - 123456789ABCDF
// 0x12 = 16(1) + 1(2) = 18, 0xF = 16(0) + 1(15) = 15

// & -> adress of operator 
// * -> dereferance operator

/* 
Buffer owerflow
 - heap owerflow
 - stack overflow

segmentation fault - when we touch segments of memory that we should't
*/ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // - malloc and free


void swap_reference(int *a, int *b);
void swap_value(int a , int b);

int main(void)
{
    int n = 50;
    printf("%p\n", &n); // printing an adress - 0x7ff7bf63041c

    // pointers - a variable that stores the memory address of another variable
    int *p = &n; // declearing a pointer
    printf("%p\n", p); 

    printf("%i\n", *p); // * in front of a pointer without declearing type means "go there"

    char s[] = "Hi!"; // s is a pointer, points to the beggining of the array - last char (NUL) helps us to know where string ends 

    printf("%p\n", s); // 0x7ff7bb1483fc
    printf("%p\n", &s[0]); // 0x7ff7bb1483fc - SAME adress for s and s[0]
    printf("%p\n", &s[1]); // 0x7ff7bb1483fd - 1 more than s[0]

    char *s_string = "Hi!"; // s_string is the adress of a char
    // double quotes takes care of understading that it puts adress of the first char for you, so
    printf("%s\n", s_string);

    printf("%c", *s_string); // same as printf("%c", s_string[0]);
    printf("%c", *(s_string+1));
    printf("%c\n", *(s_string+2));

    // it will result in printing Different since the memory locations of the two "strings" are different
    char *n = "hi";
    char *m = "hi";
    if(n == m) {
        printf("Same\n");
    } else {
        printf("Different\n");
    }
    
    // since strcmp() compares "stirngs" char by char, it will print Same
    if(strcmp(n,m) == 0) {
        printf("Same\n");
    } else {
        printf("Different\n");
    }

    // assigning a pointer to another pointer makes them share the same memory location
    char *test = "smth";
    char *t = test;
    if(strlen(test) > 0) {
        t[0] = toupper(t[0]); // to make upper-case
    }
    // they print the same thing "Smth" since they point to the saem adresses
    printf("%s\n", test); 
    printf("%s\n", t);


    // malloc() returns a pointer to the beginning of the allocated memory block
    // malloc (Memmory Allocation) takes one argument, number of bytes that you want to define for you
    // more flexibility to use memory
    char *first = "try";
    // duplicate string that is identical but elsewhere in memory
    char *second = malloc(strlen(first)+1); // strlen(first)+1 since (length + 1 for NUL character)
    if (second== NULL) { // if malloc returns NULL there is not enough memory available
        return 1;
    }

    /*
    strcpy() runs this code:
        for(int i = 0, n = strlen(first); i <= n; i++) {    // i <= n to copy the \n 
            second[i] = first[i]; 
        }
    */
    strcpy(first, second);

    if(strlen(first) > 0) {
        second[0] = toupper(second[0]); // to make upper-case
    }
    printf("%s\n", first); 
    printf("%s\n", second);

    // free is the opposite of malloc - to give back the memory to the MacOS
    free(first);


    // use valgrid./(name of the file) to check for memory related bugs in terminal
    int *x = malloc(sizeof(int));
    int *x_array = malloc(3 * sizeof(int));
    x_array[0] = 72;
    x_array[1] = 73;
    x_array[2] = 33;

    free(x);
    free(x_array);


    // garbage values - when you create variables and do not assign them you could not know what is there
    // sometimes it could be 0 but not always
    int scores[10];
    for(int i = 0; i < 10; i++) {
        printf("%i\n", scores[i]);
    }


    int x = 1;
    int y = 2;
    
    printf("x is %i, y is %i\n", x, y); // x is 1, y is 2 
    swap_value(x, y); // scope issue
    printf("x is %i, y is %i\n", x, y); // x is 1, y is 2 
    swap_reference(&x, & y);
    printf("x is %i, y is %i\n", x, y); // x is 2, y is 1


    // get_int
    int n;
    printf("n: ");
    scanf("%i", &n); // we want to pass the address of n
    printf("n: %i\n", n);


    // get_string - wrong
    // char *s; declares a pointer to a character, but it does not allocate memory for storing a string. In this code
    // s is an uninitialized pointer that points to some random memory location. When scanf("%s", s); is called,
    // it tries to store the input string in the location that s points to. However, since s points to an undefined location,
    // this causes undefined behavior, and your program might crash (segmentation fault) or corrupt data in memory.
    char *s; 
    printf("s: ");
    scanf("%s", s); 
    printf("s: %s\n", s); // s is already an adress - no need to add &


    // get_string
    char s[100]; 
    printf("s: ");
    scanf("%s", s); 
    printf("s: %s\n", s); // s is already an adress - no need to add &
    // this could still give segmentation fault if I type somehting more than 100 bytes


    // File I/O
    FILE *file =  fopen("phonBbook.csv", "a"); // fopen() opens the file and returns the adress of ithe file in computers memory
    if(file == NULL) {
        return 1;
    }
    printf("Name: ");
    char *name = get_string();
    printf("\nNumber: ");
    char *number = get_string();

    fprintf(file,"%s,%s\n", name, number);
    fclose(file);
}

// pass by value x pass by reference/pointer
void swap_value(int a , int b) {
    // passing by value
    int temp = a;
    a = b;
    b = temp;
}

void swap_reference(int *a, int *b) { // two addreses of integers
    // passing by value
    int temp = *a;
    *a = *b;
    *b = temp;
}



// ChatGPT
char* get_string(void) { // return value pointer to character - string
    // point to the memory where the input string is stored
    char *str = NULL;
    // store each character read from the input one by one.
    int ch; 
    // size keeps track of the number of characters currently in the string
    // capacity represents the current allocated size of the string
    size_t size = 0, capacity = 1;
    

    // Start with capacity 1 and dynamically expand as needed
    // Initially, capacity is 1, so we allocate space for just 1 character (plus the null terminator)
    str = malloc(sizeof(char) * capacity); // sizeof(char) * capacity allocates memory enough to store capacity number of char
    // If malloc fails (returns NULL), the program prints an error message and exits the function, 
    // returning NULL to indicate memory allocation failure.
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        // If input exceeds current capacity, expand the memory
        if (size + 1 >= capacity) {
            capacity *= 2;  // Double the capacity
            char *new_str = realloc(str, sizeof(char) * capacity);
            if (new_str == NULL) {
                printf("Memory allocation failed\n");
                free(str);  // Free the previously allocated memory
                return NULL;
            }
            str = new_str;
        }

        str[size++] = ch;  // Add character to string
    }

    str[size] = '\0';  // Null-terminate the string

    return str;  // Return the dynamically allocated string
}
