#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78330      

// Shuffle the first k values of the array.
void RandomVector(long long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        // Choose a random position among the available values.
        int j = i + rand() % (n - i);   
        long long tmp = tab[i];              
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    // Initialize the random generator with the current time.
    srand(time(NULL));

    // Prepare the array that will contain the selected prime numbers.
    static long long tab[MAX];
    long count = 0;
    long p;
    

    // Open the file containing the prime numbers.
    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening prime_number.txt.\n");
        return 1;
    }
   

    // Keep the prime numbers between 1,000 and 1,000,000.
    while (fscanf(f, "%ld", &p) == 1) {
        if (p > 1000000) break;         
        if (p >= 1000 && count < MAX) {
            tab[count] = p;
            count++;
        }
        
    }
    fclose(f);

    // Shuffle the array to obtain a random selection of 100 values.
    RandomVector(tab, count, 100);
    
    // Create the file containing the 100 selected numbers.
    FILE *out = fopen("data/test1.txt", "w");   
   if (out == NULL) {
       printf("Error creating test1.txt\n");
     return 1;
    }

   // Write one value per line.
   for (int i = 0; i < 100; i++){
     fprintf(out, "%lld\n", tab[i]);
        // One number per line.
    
   }

   fclose(out);

   printf("test1.txt created successfully.\n");
    
    

}