
#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* out0 = fopen("data/test3_3digits.txt", "w");

    if (out0 == NULL) {
        printf("Error opening test3_3digits.txt\n");
        return 1;
    }
    

    fprintf(out0, "101\n103\n107\n109\n113\n127\n131\n137\n139\n149\n"); 

    fclose(out0);

    FILE* out1 = fopen("data/test3_6digits.txt", "w");

    if (out1 == NULL) {
        printf("Error opening test6_6digits.txt\n");
        return 1;
    }

    fprintf(out1, "100003\n100019\n100043\n100049\n100057\n100069\n100103\n100109\n100129\n100151\n");

    fclose(out1);

    FILE* out2 = fopen("data/test3_9digits.txt", "w");

    if (out2 == NULL) {
        printf("Error opening test3_9digits.txt\n");
        return 1;
    }

    fprintf(out2, "100000007\n100000037\n100000039\n100000049\n100000073\n100000081\n100000123\n100000127\n100000193\n10<PASSWORD>213\n");

    fclose(out2);


    FILE* out3 = fopen("data/test3_12digits.txt", "w");

    if (out3 == NULL) {
        printf("Error opening test3_12digits.txt\n");
        return 1;
    }

    fprintf(out3, "100000000003\n100000000019\n100000000057\n100000000063\n100000000069\n100000000073\n100000000091\n10<PASSWORD>171\n");

    fclose(out3);

    printf("test3_3digits.txt, test3_6digits.txt, test3_9digits.txt, test3_12digits.txt created successfully.\n");



   
    return 0;


}