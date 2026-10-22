
#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* out0 = fopen("data/test3_3digits.txt", "w");

    if (out0 == NULL) {
        printf("Error opening test3_3digits.txt\n");
        return 1;
    }
    

    fprintf(out0, "300 452 999 123 758 147 632 753 951 139\n"); 

    fclose(out0);

    FILE* out1 = fopen("data/test3_6digits.txt", "w");

    if (out1 == NULL) {
        printf("Error opening test6_6digits.txt\n");
        return 1;
    }

    fprintf(out1, "300000 452000 999999 123456 758321 147852 632147 753951 951753 139258\n");

    fclose(out1);

    FILE* out2 = fopen("data/test3_9digits.txt", "w");

    if (out2 == NULL) {
        printf("Error opening test3_9digits.txt\n");
        return 1;
    }

    fprintf(out2, "300000000 452000000 999999999 123456789 758321456 147852963 632147852 753951456 951753258 139258147\n");

    fclose(out2);


    FILE* out3 = fopen("data/test3_12digits.txt", "w");

    if (out3 == NULL) {
        printf("Error opening test3_12digits.txt\n");
        return 1;
    }

    fprintf(out3, "300000000000 452000000000 999999999999 123456789012 758321456789 147852963456 632147852963 753951456789 951753258467 139258147654\n");

    fclose(out3);

    printf("test3_3digits.txt, test3_6digits.txt, test3_9digits.txt, test3_12digits.txt created successfully.\n");



   
    return 0;


}