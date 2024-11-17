#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 20  // Set a limit for the numbers

// Global variables to store the results
int odd_sum = 0;
int even_sum = 0;
int odd_numbers[MAX_NUM];
int even_numbers[MAX_NUM];
int odd_count = 0;
int even_count = 0;

// Function to find the sum of odd numbers and store them
void* sum_odd(void* arg) {
    for (int i = 1; i <= MAX_NUM; i++) {
        if (i % 2 != 0) {
            odd_sum += i;
            odd_numbers[odd_count++] = i;  // Store the odd number
        }
    }
    pthread_exit(NULL);
}

// Function to find the sum of even numbers and store them
void* sum_even(void* arg) {
    for (int i = 1; i <= MAX_NUM; i++) {
        if (i % 2 == 0) {
            even_sum += i;
            even_numbers[even_count++] = i;  // Store the even number
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, sum_odd, NULL);
    pthread_create(&thread2, NULL, sum_even, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Display the results
    printf("Sum of odd numbers: %d\n", odd_sum);
    printf("Odd numbers: ");
    for (int i = 0; i < odd_count; i++) {
        printf("%d ", odd_numbers[i]);
    }
    printf("\n");

    printf("Sum of even numbers: %d\n", even_sum);
    printf("Even numbers: ");
    for (int i = 0; i < even_count; i++) {
        printf("%d ", even_numbers[i]);
    }
    printf("\n");

    return 0;
}
