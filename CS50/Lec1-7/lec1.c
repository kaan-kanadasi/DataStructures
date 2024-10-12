#include <stdio.h>
// #include <cs50.h>

// Function prototypes
// this is a hint to the compiler that the meow() doesn't exist yet, but it will
// if we don't type this the compiler gives an error since meow() is not declared 
// other solution is to tpy ethe meow() function at top of main()
void meow(int n);
void meow(int n);
void example_meow(void);
int add(int a, int b);
int get_int(void);
void example_add(void);

int main(void) {
    // Example function calls
    example_meow();
    example_add();

    printf("Hello, World!\n");

    char c = 'a';
    if (c == 'y' || c == 'Y') 
        printf("Agreed\n");
    else if (c == 'n' || c == 'N') 
        printf("Not agreed\n");

    int i = 3;
    while (i > 0) {
        printf("meow\n");
        i--;
    }

    for (int i = 0; i < 3; i++) {
        printf("meow\n");
    }

    for (int i = 0; i < 4; i++) {
        printf("?");
    }
    printf("\n");

    // Validating input using a do-while loop
    int m;
    do {
        m = get_int();
    } while (m < 1);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("#");
        }
        printf("\n");
    }

    // Demonstrating integer division vs. float division
    int first = get_int();
    int second = get_int();

    if (second == 0) {
        printf("Division by zero is undefined.\n");
    } else {
        float result_1 = first / second; // Integer division
        printf("%f\n", result_1);
        
        float result_2 = (float) first / (float) second; // Float division
        printf("%.5f\n", result_2);
    }
}

// Function definitions
void meow(int n) {
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}

void example_meow(void) {
    meow(3);
}

int add(int a, int b) {
    return a + b;
}

void example_add(void) {
    int x = get_int();
    int y = get_int();

    if (x == -1 || y == -1) {
        printf("Error in input, cannot add.\n");
    } else {
        printf("%i\n", add(x, y));
    }
}

int get_int(void) {
    int number;
     // scanf reads and stores the input directly into number
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Exiting.\n");
        return -1;
    }
    return number;
}