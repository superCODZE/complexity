#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly shuffle the N array values using the Fisher-Yates method.
void RandomVector(long *tab, int N)          // long*
{
    for (int i = 0; i < N; i++) {
        // Choose a random position among the remaining elements.
        int j = i + rand() % (N - i);        // j in [i, N-1]
        long tmp = tab[i];                   // actual swap
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    // Initialize the random generator with the current time.
    srand(time(NULL));

    long Random1000[1000];                   // long, not int

    // Open the file containing the prime numbers.
    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the first 1000 values and store them in the array.
    for (int i = 0; i < 1000; i++) {
        if (fscanf(f, "%ld", &Random1000[i]) != 1) {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    // Shuffle the values before writing them to the output file.
    RandomVector(Random1000, 1000);

   // Create the output file in write mode.
   FILE *out = fopen("data/Random1000.txt", "w");   // "w" = create / write
   if (out == NULL) {
      printf("Error creating Random1000.txt\n");
     return 1;
    }

   // Write one value per line.
   for (int i = 0; i < 1000; i++)
     fprintf(out, "%ld\n", Random1000[i]);  

   fclose(out);
   printf("Random1000.txt created successfully.\n");
    return 0;
}