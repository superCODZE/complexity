#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78330      

// Mélange les k premières valeurs du tableau.
void RandomVector(long long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        // Choisit une position au hasard parmi les valeurs disponibles.
        int j = i + rand() % (n - i);   
        long long tmp = tab[i];              
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    // Initialise le générateur aléatoire avec l'heure courante.
    srand(time(NULL));

    // Prépare le tableau qui contiendra les nombres premiers sélectionnés.
    static long long tab[MAX];
    long count = 0;
    long p;
    

    // Ouvre le fichier contenant les nombres premiers.
    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening prime_number.txt.\n");
        return 1;
    }
   

    // Conserve les nombres premiers compris entre 1000 et 1 000 000.
    while (fscanf(f, "%ld", &p) == 1) {
        if (p > 1000000) break;         
        if (p >= 1000 && count < MAX)
            tab[count] = p;


            count++;
        
    }
    fclose(f);

    // Mélange le tableau pour obtenir une sélection aléatoire de 100 valeurs.
    RandomVector(tab, count, 100);
    
    // Crée le fichier contenant les 100 nombres sélectionnés.
    FILE *out = fopen("data/test1.txt", "w");   
   if (out == NULL) {
      printf("Error creating test1.txt\n");
     return 1;
    }

   // Écrit une valeur par ligne.
   for (int i = 0; i < 100; i++){
     fprintf(out, "%lld\n", tab[i]);
        // un nombre par ligne
    
   }

   fclose(out);

   printf("test1.txt created successfully.\n");
    
    

}