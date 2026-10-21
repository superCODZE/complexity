#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78330      // il y a 78330 premiers dans [1000, 1000000]

void RandomVector(long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        int j = i + rand() % (n - i);   // j dans [i, n-1]
        long tmp = tab[i];              // vrai échange
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    srand(time(NULL));

    static long tab[MAX];
    long test1[100];
    int n = 0;
    long p;

    FILE *f = fopen("primes1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(f, "%ld", &p) == 1) {
        if (p > 1000000) break;         // fichier trié : on peut s'arrêter
        if (p >= 1000 && n < MAX)
            tab[n++] = p;
    }
    fclose(f);

    printf("%d premiers dans [1000, 1000000]\n", n);

    RandomVector(tab, n, 100);
    
    for (int i = 0; i < 100; i++) {
        test1[i] = tab[i];
    }

    FILE *out = fopen("test1.txt", "w");   // "w" = créer / écrire
   if (out == NULL) {
      printf("Error creating test1.txt\n");
     return 1;
    }

   for (int i = 0; i < 100; i++)
     fprintf(out, "%ld\n", test1[i]);   // un nombre par ligne

   fclose(out);
    
    

}