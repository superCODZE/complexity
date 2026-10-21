#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXI 600000     // taille du tableau (le plus grand intervalle a 586081 premiers)

void RandomVector(long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        int j = i + rand() % (n - i);   // j dans [i, n-1]
        long tmp = tab[i];              // vrai échange
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void) {

    srand(time(NULL));

    char filename[100];
    long Sup = 1000;
    long Inf = 100;
    long count = 0;
    long p;
    static long test2[MAXI];    // grand tableau, "static" obligatoire

    FILE *f = fopen("prime_number.txt", "r");

    if (f == NULL) {
        printf("Error opening prime_number.txt\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {

        while (fscanf(f, "%ld", &p) == 1) {
            if (p >= Sup) break;                  // fichier trié : on s'arrête
            if (p >= Inf && count < MAXI)
                test2[count++] = p;               // on garde le nombre
        }

        RandomVector(test2, count, 10);           // tirage de 10 nombres

        sprintf(filename, "data/test2_%ld-%ld.txt", Inf, Sup - 1);
        FILE *out = fopen(filename, "w");
        if (out == NULL) {
            printf("Error creating %s\n", filename);
            return 1;
        }

        for (int j = 0; j < 10; j++)
            fprintf(out, "%ld\n", test2[j]);      // un nombre par ligne

        fclose(out);
        printf("%s : %ld premiers disponibles\n", filename, count);

        count = 0;          // on vide le tableau pour l'intervalle suivant
        Sup *= 10;
        Inf *= 10;
        rewind(f);          // relire le fichier depuis le début
    }

    fclose(f);
    return 0;
}