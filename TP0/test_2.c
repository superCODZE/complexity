#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXI  50847534 

// Mélange les k premières valeurs du tableau.
void RandomVector(long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        // Choisit une position au hasard parmi les valeurs disponibles.
        int j = i + rand() % (n - i);   
        long tmp = tab[i];              
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void) {

    // Initialise le générateur aléatoire avec l'heure courante.
    srand(time(NULL));

    // Définit les bornes de l'intervalle de nombres premiers à traiter.
    char filename[100];
    long Sup = 1000;
    long Inf = 100;
    long count = 0;
    long p;
    static long test2[MAXI];    // grand tableau, "static" obligatoire

    // Ouvre le fichier contenant les nombres premiers.
    FILE *f = fopen("prime_number.txt", "r");

    if (f == NULL) {
        printf("Error opening prime_number.txt\n");
        return 1;
    }

    for (int i = 0; i < 7; i++) {

        // Charge les nombres premiers appartenant à l'intervalle courant.
        while (fscanf(f, "%ld", &p) == 1) {
            if (p >= Sup) break;                  // fichier trié : on s'arrête
            if (p >= Inf && count < MAXI)
                test2[count] = p; 
                count++;              // on garde le nombre
        }

        // Mélange le tableau pour tirer 10 nombres au hasard.
        RandomVector(test2, count, 10);           // tirage de 10 nombres

        // Construit le nom du fichier correspondant à l'intervalle.
        sprintf(filename, "data/test2_%ld-%ld.txt", Inf, Sup - 1);
        FILE *out = fopen(filename, "w");
        if (out == NULL) {
            printf("Error creating %s\n", filename);
            return 1;
        }

        // Écrit les 10 nombres sélectionnés, un par ligne.
        for (int j = 0; j < 10; j++)
         fprintf(out, "%ld\n", test2[j]);      // un nombre par ligne





        fclose(out);
        printf("%s : 10 premiers disponibles\n", filename);

        // Réinitialise les bornes et le compteur pour l'intervalle suivant.
        count = 0;          // on vide le tableau pour l'intervalle suivant
        Sup *= 10;
        Inf *= 10;
        rewind(f);          // relire le fichier depuis le début
    }

    fclose(f);
    return 0;
}