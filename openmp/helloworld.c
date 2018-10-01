#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
#pragma omp parallel
    printf("Hello, World! : Printed by : %d\n", omp_get_thread_num());
}

/** 
 * Output
 * Hello, World! : Printed by : 3
 * Hello, World! : Printed by : 0
 * Hello, World! : Printed by : 1
 * Hello, World! : Printed by : 2
 * 
 * Because, the machine has 4 Cores and thus,
 * OpenMP creates 4 threads
*/