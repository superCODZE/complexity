#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomVector(long *tab, int N)          // long*
{
    for (int i = 0; i < N; i++) {
        int j = i + rand() % (N - i);        // j dans [i, N-1]
        long tmp = tab[i];                   // vrai échange
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    srand(time(NULL));

    long Random100[100];                   // long, pas int

    FILE *f = fopen("primes1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        if (fscanf(f, "%ld", &Random100[i]) != 1) {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    RandomVector(Random100, 100);

   FILE *out = fopen("Random100.txt", "w");   // "w" = créer / écrire
   if (out == NULL) {
      printf("Error creating Random100.txt\n");
     return 1;
    }

   for (int i = 0; i < 100; i++)
     fprintf(out, "%ld\n", Random100[i]);   // un nombre par ligne

   fclose(out);
   
   
    return 0;
}