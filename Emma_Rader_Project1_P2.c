// Emma Rader
// Project 1 pt.2

// Header files
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// declare 2 functions which called using thread
void *first_function(void *arg);
void *second_function(void *arg);

// function1
void *first_function(void *arg) { 
  
  // declare array
  int arr1[] = {3, 8, 12, 21, 1};
  int sum = 0;
  
  // calculate length of the array
  int length = sizeof(arr1) / sizeof(int);
  
  // using for loop
  for (int i = 0; i < length; i++) {
    sum = sum + arr1[i];
  }
  printf("\nSum of Value from the first function: %d\t", sum);
  
  // once function is done exit the thread
  pthread_exit(NULL);
}

// function2
void *second_function(void *arg) {
  
  // declare array
  int arr2[] = {7, 23, 18, 15, 10};
  
  // calculate length
  int length = sizeof(arr2) / sizeof(int);
  int sum = 0;

  // using loop calculate sum
  for (int i = 0; i < 5; i++) {
    sum = sum + arr2[i];
  }
  printf("\nSum of Value from the second function: %d\t", sum);
  
  // exit the thread
  pthread_exit(NULL);
}

// main function
int main() {
  
  // create thread 1 to call function1
  pthread_t my_thread1;
  pthread_create(&my_thread1, NULL, &first_function, NULL); 
  pthread_join(my_thread1, NULL);
  
  // create thread 2 to call function2
  pthread_t my_thread2;
  pthread_create(&my_thread2, NULL, &second_function, NULL); 
  pthread_join(my_thread2, NULL);

  return 0;
}