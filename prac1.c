#include <stdio.h> 
#include<omp.h>
#include <time.h> 
  
// A function that terminates when enter key is pressed 
void fun() 
{ 
    int arr[50000], count0 = 0, count1 = 0, count2 = 0, count3 = 0;
    #pragma omp parallel for
    for(int i = 0; i<52; i++)
    {
        int thread_being_used = omp_get_thread_num();
        arr[i] = 5*i;
        printf("Hello from %d thread\n", thread_being_used);
        if(thread_being_used == 0)
        {
            count0++;
        }
        else if(thread_being_used == 1)
        {
            count1++;
        }
        else if(thread_being_used == 2)
        {
            count2++;
        }
        else
            count3++;
    } 
    printf("Iterations run by thread 0: %d\n", count0);
    printf("Iterations run by thread 1: %d\n", count1);
    printf("Iterations run by thread 2: %d\n", count2);
    printf("Iterations run by thread 3: %d\n", count3);
} 
  
// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    fun(); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("Program took %f seconds to execute \n", time_taken); 
    return 0; 
} 