#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

// Functions' declaration. Definition is at the bottom
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char* argv[])
{
 
 /* Create thread IDs */
pthread_t avg_thread, min_thread, max_thread;

/* Create thread attributes */
pthread_attr_t attr;

/* Initialize thread attributes */
pthread_attr_init(&attr);

/* Create threads */
pthread_create(&avg_thread, &attr, avgfunc, argv[1]);//Creates a new thread to run the avgfunc function, passing the program's first argument as an argument to avgfunc.
pthread_create(&min_thread, &attr, minfunc, argv[1]);//Creates a new thread to run the minfunc function, passing the program's first argument to minfunc as an argument.
pthread_create(&max_thread, &attr, maxfunc, argv[1]);//Creates a new thread to run the maxfunc function, passing the program's first argument as an argument to maxfunc.

/* Wait for threads to exit */
pthread_join(avg_thread, NULL);// Waits for avg_thread to exit
pthread_join(min_thread, NULL);// Waits for avg_thread to exit
pthread_join(max_thread, NULL);// Waits for max_thread to exit


printf("%d %d %d", avgNum, minNum, maxNum);
}

void *avgfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed

    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
 
    /* Write the code to calculate the average value and store it in avgNum variable */
 
//Initialize variables for counting and summing the numbers
int count = 0;
int sum = 0;

//Loop through the arguments passed to the program
while (*args)
{
//Add the current number to the sum
    sum += atoi(*args);
    args++;// Move to the next argument
    count++;//Increment the count of numbers processed
}

/* Calculate the average of the numbers */
avgNum = sum / count;

/* Exit the thread with a successful status */
pthread_exit(0);
}

void *minfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed
 
    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
    
    /* Write the code to calculate the minimum value and store it in minNum variable */
 
 /* Initialize the minimum value with the first argument */
 int min = atoi(*args);

 /* Increment the pointer to the next argument */
 args++;

 /* Loop through the remaining arguments */
 while (*args) {
    int sum = atoi(*args); //Convert the argument to integer
    if (num < min) min = sum;//Update the minimum value if the current argument is smaller
    args++; //Increment the pointer to the next argument

 }

}

void *maxfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed
 
    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
    
    /* Write the code to calculate the maximum value and store it in maxNum variable */

/* Initializing the maximum value with the first argument */
 int max = atoi(*args);
 args++; //Moving the pointer to the next argument
 while (*args) {
    int num = atoi(*args); //Converting the current argument to integer
    if (num > max) max = num; //Checking if the current argument is greater than the maximum value & updating the maximum value 
    args++; //Moving the pointer to the next argument

 }

 maxNum = max; //Storing the maximum value in the variable maxNum

 /* Storing the maximum value in the variable maxNum */
 pthread_exit(0);
 

}
