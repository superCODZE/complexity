
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Create a single file containing all four Test 3 samples.
    FILE *out0 = fopen("data/test3.txt", "w");

    if (out0 == NULL) {
        printf("Error creating data/test3.txt\n");
        return 1;
    }

    // Sample of three-digit prime numbers.
    fprintf(out0, "101\n103\n107\n109\n113\n127\n131\n137\n139\n149\n"); 
    // Sample of six-digit prime numbers.
    fprintf(out0, "100003\n100019\n100043\n100049\n100057\n100069\n100103\n100109\n100129\n100151\n");
    // Sample of nine-digit prime numbers.
    fprintf(out0, "100000007\n100000037\n100000039\n100000049\n100000073\n100000081\n100000123\n100000127\n100000193\n100000213\n");
    // Sample of twelve-digit prime numbers.
    fprintf(out0, "100000000003\n100000000019\n100000000057\n100000000063\n100000000069\n100000000073\n100000000091\n100000000097\n");

    fclose(out0);

    printf("test3.txt created successfully.\n");
    return 0;
}
