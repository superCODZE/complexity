
#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* out0 = fopen("data/test3_3digits.txt", "w");

    if (out0 == NULL) {
        printf("Error opening test3_3digits.txt\n");
        return 1;
    }
    

    fprintf(out0, "101 103 107 109 113 127 131 137 139 149\n"); 

    fclose(out0);

    FILE* out1 = fopen("data/test3_6digits.txt", "w");

    if (out1 == NULL) {
        printf("Error opening test6_6digits.txt\n");
        return 1;
    }

    fprintf(out1, "100003 100019 100043 100049 100057 100069 100103 100109 100129 100151\n");

    fclose(out1);

    FILE* out2 = fopen("data/test3_9digits.txt", "w");

    if (out2 == NULL) {
        printf("Error opening test3_9digits.txt\n");
        return 1;
    }

    fprintf(out2, "100000007, 100000037, 100000039, 100000049, 100000073, 100000081, 100000123, 100000127, 100000193, 100000213\n");

    fclose(out2);


    FILE* out3 = fopen("data/test3_12digits.txt", "w");

    if (out3 == NULL) {
        printf("Error opening test3_12digits.txt\n");
        return 1;
    }

    fprintf(out3, "100000000003, 100000000019, 100000000057, 100000000063, 100000000069, 100000000073, 100000000091, 100000000103, 100000000129, 100000000171\n");

    fclose(out3);

    printf("test3_3digits.txt, test3_6digits.txt, test3_9digits.txt, test3_12digits.txt created successfully.\n");



   
    return 0;


}