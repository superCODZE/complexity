#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly shuffle the N array values using the Fisher-Yates method.
void RandomVector(long *tab, int N)          // long*
{
    for (int i = 0; i < N; i++) {
        // Choose a random position among the elements that remain to be shuffled.
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

    long Random100[100];                   // long, not int

    // Open the file containing the 100 prime numbers.
    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the values from the file and store them in the array.
    for (int i = 0; i < 100; i++) {
        if (fscanf(f, "%ld", &Random100[i]) != 1) {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    // Shuffle the numbers before saving them.
    RandomVector(Random100, 100);

   // Create the output file in write mode.
   FILE *out = fopen("data/Random100.txt", "w");   // "w" = create / write
   if (out == NULL) {
      printf("Error creating Random100.txt\n");
     return 1;
    }

   // Write one value per line to the output file.
   for (int i = 0; i < 100; i++) {
     fprintf(out, "%ld\n", Random100[i]);
        // One number per line.
   }

   
   fclose(out);
   printf("Random100.txt created successfully.\n");
   
    return 0;
}