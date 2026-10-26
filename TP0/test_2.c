#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXI  50847534 

// Shuffle the first k values of the array.
void RandomVector(long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        // Choose a random position among the available values.
        int j = i + rand() % (n - i);   
        long tmp = tab[i];              
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void) {

    // Initialize the random generator with the current time.
    srand(time(NULL));

    // Define the bounds of the prime number samples to create.
    char filename[100];
    long Sup = 1000;
    long Inf = 100;
    long count = 0;
    long p;
    static long test2[MAXI];    // Array containing the numbers in the interval.

    // Open the source file containing all prime numbers.
    FILE *f = fopen("prime_number.txt", "r");

    if (f == NULL) {
        printf("Error opening prime_number.txt\n");
        return 1;
    }

    // Create a single file containing all Test 2 samples.
    sprintf(filename, "data/test2.txt");
    FILE *out = fopen(filename, "w");

    if (out == NULL) {
        printf("Error creating data/test2.txt\n");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < 7; i++) {

        // Load the prime numbers in the current interval.
        while (fscanf(f, "%ld", &p) == 1) {
            if (p >= Sup) break;                  // The file is sorted.
            if (p >= Inf && count < MAXI) {
                test2[count] = p; 
                count++;
            }
        }

        // Shuffle the array and select 10 random numbers.
        RandomVector(test2, count, 10);

        // Add the 10 selected numbers to the single output file.
        for (int j = 0; j < 10; j++)
            fprintf(out, "%ld\n", test2[j]);

        printf("%s: 10 numbers from the interval [%ld, %ld[\n",
               filename, Inf, Sup);

        // Prepare the next interval.
        count = 0;
        Sup *= 10;
        Inf *= 10;
        rewind(f);
    }

    fclose(f);
    fclose(out);
    return 0;
}