
#include <stdio.h>
#include <stdlib.h>


int main(void){

    int Random100[100];
    int Random1000[1000];
    int test1[78330];


    FILE *f = fopen("primes1.txt", "r");

    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    unsigned long long p;
    unsigned long long count = 0;
    char buffer[265];
    
    for (int i=0 ; i < 100; i++) {
       if (fscanf(f, "%llu", &p) == 1) {
            Random100[i] = p;
        } else {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }   
    }

    

    for (int i = 0; i < 1000; i++) {
        if (fscanf(f, "%llu", &p) == 1) {
            Random1000[i] = p;
        } else {
            printf("Error reading prime number from file.\n");
            fclose(f);
            return 1;
        }
    }
    
    rewind(f); // Reset file pointer to the beginning of the file

    while (fscanf(f, "%llu", &p) == 1) {
    if (p > 1000000) break;         
    if (p >= 1000) {
        test1[count++] = p;
    }
}
    



    

   fclose(f);

  printf("Random100 : %d ... %d\n", Random100[0], Random100[99]);
  printf("Random1000: %d ... %d\n", Random1000[0], Random1000[999]);
  printf("test1     : %llu elements, %d ... %d\n", count, test1[0], test1[count - 1]);
   return 0;
}