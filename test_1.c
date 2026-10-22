#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78330      

void RandomVector(long long *tab, int n, int k)
{
    for (int i = 0; i < k; i++) {
        int j = i + rand() % (n - i);   
        long long tmp = tab[i];              
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int main(void)
{
    srand(time(NULL));

    static long long tab[MAX];
    long count = 0;
    long p;
    

    FILE *f = fopen("prime_number.txt", "r");
    if (f == NULL) {
        printf("Error opening prime_number.txt.\n");
        return 1;
    }
   

    while (fscanf(f, "%ld", &p) == 1) {
        if (p > 1000000) break;         
        if (p >= 1000 && count < MAX)
            tab[count] = p;


            count++;
        
    }
    fclose(f);

   
    RandomVector(tab, count, 100);
    
   

    FILE *out = fopen("data/test1.txt", "w");   
   if (out == NULL) {
      printf("Error creating test1.txt\n");
     return 1;
    }

   for (int i = 0; i < 100; i++){
     fprintf(out, "%lld\n", tab[i]);
        // un nombre par ligne
    
   }

   fclose(out);

   printf("test1.txt created successfully.\n");
    
    

}