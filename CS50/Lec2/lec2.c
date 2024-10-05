#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    1st step - preprocessing
        #include <cs50.h>
        thinks this header as a decleration of all of the functions inside of its file
        compiler copies and pastes the code inside <cs50.h> to the top of your code so you can access it 
        the process applies for #include <stdio.h> - exmpl: printf()

    2nd step - compiling
        compiler of c compiles c to assembly langauge

    3rd step - assembly 
        converst the assembly langauge to machine code 0s and 1s

    4th step - linling
        links the files that are 0s and 1s (stdio.c, cs50.c, Lec2.c) 
*/

// everys string is n+1 bytes where n == the number of chars the string has
// there is a special value (NUL - not null) at the end of every string in memery, that tells the computer string stops here 


// global variable - sharing a variable accross functions
const int LEN = 3;

// prototypes
void print_column(int height);
int get_int(void);
float average(int length, int array[]);
int length(char arr[]);

// int main(void) == int main(int argc, char *argv[]), we use this form for command line arguments
int main(int argc, char *argv[])
{
    int h = get_int();
    print_column(h);

    // in c, you cannot call a fucntion to learn the length of an array - you can by the library, #include <string.h>
    int scores[LEN];
    for(int i = 0; i < LEN; i++) 
        { scores[i] = get_int(); }
    printf("Average: %.2f\n", average(LEN, scores));

    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("%c%c%c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);

    // in c, there is no data type called string, instead we use array of chars
    char str[] = "HI!";
    printf("%i %i %i %i\n", str[0], str[1], str[2], str[3]);
    printf("%i\n", length(str));
    printf("%i\n", (int)strlen(str)); // from the #include <string.h> library

    // to get 'string' input
    char st[100];  // Allocate enough space for the input
    printf("Enter a string: ");
    fgets(st, sizeof(st), stdin);  // Read input including spaces

    for (int i = 0, n = strlen(st); i < n; i++) { // no i < strlen(st) since fucn would loop and make the program slower
        if(st[i] >= 'a' && st[i] <= 'z') { // if lower case
            printf("%c", st[i] - 32); // making it upper-case, since in ASCI upper-case is 32 lower than lower-case
        } else {
            printf("%c", st[i]);
        }
    }
    printf("\n");

    // <ctype.h> library allows us to use toupper() function which makes the character uppercase if it is lower-case 
    for (int i = 0, n = strlen(st); i < n; i++) { 
        printf("%c", toupper(st[i])); 
    }
    printf("\n");

    // comand line arguments
    if(argc < 2) {
        printf("Missing command-line arguments");
    } else {
            printf("Number of arguments: %d\n", argc);
        // Loop through and print each argument
        for (int i = 0; i < argc; i++) {
            printf("Argument %d: %s\n", i, argv[i]);
        }
    } 
    // to see the previous status code with - echo $? (0 if succeded, 1 if fail)
    return 0;
}

void print_column(int height) 
{
    for(int i = 0; i < height; i++) {
        printf("#\n");
    }
}

int get_int(void) 
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    return number;
}

float average(int length, int arr[]) 
{
    int sum = 0;
    for(int j = 0; j < length; j++) {
        sum += arr[j];
    }
    return (float) sum / length;
}

int length(char arr[]) 
{
    // calculate the length of array
    int count = 0;
    while(arr[count] != '\0') { // check for NUL ( null terminator )
        count++;
    } 
    return count;
} 