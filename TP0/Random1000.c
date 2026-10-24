#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mélange aléatoirement les N valeurs du tableau avec la méthode de Fisher-Yates.
void RandomVector(long *tab, int N)          // long*
{
    for (int i = 0; i < N; i++) {
        // Choisit une position au hasard parmi les éléments restants.
        int j = i + rand() % (N - i);        // j dans [i, N-1]
        long tmp = tab[i];                   // vrai échange
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    // Initialise le générateur aléatoire avec l'heure courante.
    srand(time(NULL));

    long Random1000[1000];                   // long, pas int

    // Ouvre le fichier contenant les nombres premiers.
    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Lit les 1000 premières valeurs et les stocke dans le tableau.
    for (int i = 0; i < 1000; i++) {
        if (fscanf(f, "%ld", &Random1000[i]) != 1) {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    // Mélange les valeurs avant de les écrire dans le fichier de sortie.
    RandomVector(Random1000, 1000);

   // Crée le fichier de sortie en mode écriture.
   FILE *out = fopen("data/Random1000.txt", "w");   // "w" = créer / écrire
   if (out == NULL) {
      printf("Error creating Random100.txt\n");
     return 1;
    }

   // Écrit une valeur par ligne.
   for (int i = 0; i < 1000; i++)
     fprintf(out, "%ld\n", Random1000[i]);  

   fclose(out);
   printf("Random1000.txt created successfully.\n");
    return 0;
}