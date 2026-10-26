#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

bool estPremierA1(long N) {
    if (N == 0 || N == 1) { return false; }
    
    for (long i = 2; i <= N-1; i++) { // (n-1)-(2)+1 iterations, from (b-a)+1 when a < b
        if (N % i == 0) { 
            return false;
        }
    } 
    return true; 
}
// Complexity = (n-2) ---> O(n)

bool estPremierA2(long N) {
    if (N == 0 || N == 1) { return false; }
    
    for (long i = 2; i <= N/2; i++) { // (n/2)-(2)+1 iterations = (n/2)-1
        if (N % i == 0) { 
            return false;
        }
    } 
    return true; 
}
// O(n/2) --> O(n)

bool estPremierA3(long N) {
    if (N <= 1) return false;
    for (long i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
}
// O(sqrt(n))



bool estPremierA4(long N) {
    if (N == 2) return true;
    if (N < 2 || N % 2 == 0) return false;

    for (long i = 3; i <= sqrt(N); i+=2) { // += 2 tests only odd numbers (3, 5, 7, ...)
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
// O(sqrt(n))


double measure_total_time(long *nums, int size, bool (*algo)(long)) {

    clock_t start = clock();
    for (int i = 0; i < size; i++)
        algo(nums[i]);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}


int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Please provide the TXT file as an argument.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("The file does not exist.\n"); return 1;
    }

    long* nums = malloc(sizeof(long) * 10000);
    char buffer[100];
    int size = 0;

    while (size < 10000 && fgets(buffer, 100, file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        nums[size++] = atol(buffer);
    }
    fclose(file);

    bool (*algos[4])(long) = { estPremierA1, estPremierA2, estPremierA3, estPremierA4 };
    const char* names[4]   = { "A1", "A2", "A3", "A4" };

    for (int a = 0; a < 4; a++) {
        char f2[256];
        sprintf(f2, "DataTest-results/%s_detailed_results.txt", names[a]);

        FILE* r2 = fopen(f2, "w");
        if (!r2) return 1;

        double T_total = measure_total_time(nums, size, algos[a]);
        printf("%s | TOTAL for %d numbers = %f s\n", names[a], size, T_total);
        fprintf(r2, "%s | TOTAL for %d numbers = %f s\n", names[a], size, T_total);



        fclose(r2);
    }

    free(nums);
    return 0;
}
