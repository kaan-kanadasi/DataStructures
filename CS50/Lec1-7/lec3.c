#include <stdio.h>
#include <string.h> // strcmp() - comparing strings

// O (big o) == upper bound / in the worst case how fast the algorithm takes
// Ω (omega) == lower bound / in the best case how fast the algorithm takes

void draw(int n);
 
int main() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int n = get_int();
    printf(linear(array, n));

    // 2D array for sotring strings
    char strings[][10] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    for (int i = 0; i<6; i++) {
        if (strcmp(strings[i], "boot") == 0) { // cannot use ==, strcmp(strings[0][i], "boot") = 0 if true
            printf("Found\n");
            return 1;
        }
    }

    int height = get_int("Height: ");
    draw(height);
    return 0;
}


int get_int() 
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    return number;
}


void draw(int n) {
    /*
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<i+1; j++) {
            printf("#");
        }
    } 
    */

   // recursion version
    if(n <= 0) { // if nothing to draw
        return;
    }
    draw(n-1);
    for(int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}


// linear search - O(1) to O(n)
int linear_search(int arr[], int num) {
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // sizeof(arr) == total size of array in bytes - there are 6 integers and sicne each int is 4 bytes the total is 24 bytes
    // sizeof(arr[0]) == size of the first element in array - each element are integers, it is 4 bytes
    // sizeof(arr) / sizeof(arr[0]) = 24/4 = 6; sice of the array
    for (int i = 0; i < arr_size; i++) {
        if(num == arr[i]) {
            printf("Found the number at index: " + i);
            return 0;
        }
    }
    printf("Not found\n");
    return -1;
}


// binary search - O(1) to  O(log n)
int binary_search(int arr[], int target) {
    int size = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            printf("Found the number at index: " + mid);
            return 0;
        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }
    printf("Not found\n");
    return -1;
}


// O(n^2),Ω(n^2)
void selection_sort() {
    int arr[] = {6, 2, 0, 4, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i=0; i < 6; i++) {
        int min_index = i;
        for (int j=i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index]; 
        arr[min_index] = arr[i]; 
        arr[i] = temp;
    }
}


// O(n^2),Ω(n)
void bubble_sort() {
    int arr[] = {6, 2, 0, 4, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// O(nlogn), Ω(nlogn)
void merge_sort(int arr[], int left, int right) { // merge_sort(arr, 0, n - 1);
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}