#include <omp.h>
#include <cmath>
#include <stdio.h>

#define N 12
unsigned A [] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12};

int main(int argc, char** argv) {
    int max_thread = omp_get_max_threads();
    printf("Find %d thread\n", max_thread);
    if (max_thread > 4) {
        omp_set_num_threads(4);
    }
    int i;
    float a2;
    printf("Is square of n from N:");
    #pragma omp parallel for  private(i, a2) shared(A)
    for (i = 0; i < N; i++) {
        a2 = sqrt(A[i]);
        if (round(a2) * round(a2) == A[i])
        #pragma omp critical
        {
            printf(" %d", A[i]);
        }
    }
    return 0;
}