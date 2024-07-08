#include <stdio.h>

// Function to print the binary representation of an unsigned int
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
       
    }
    printf("\n");
}

// Function to extract a 4-bit segment and convert it to hexadecimal
char extractHexDigit(unsigned int num, int pos) {
    // Extract the 4 bits starting from the specified position
    unsigned int mask = 0xF; // 4 bits mask (1111 in binary)
    unsigned int extractedBits = (num >> (pos - 3)) & mask;
    // Convert the extracted 4 bits to a hexadecimal character
    if (extractedBits < 10) return '0' + extractedBits;
    else return 'A' + (extractedBits - 10);
}

int main() {
    unsigned int num;
    int position;

    // Input the non-negative integer
    printf("broj > ");
    scanf("%u", &num);

    // Input the starting position
    do {
        printf("pozicija > ");
        scanf("%d", &position);
    } while (position < 3 || position > 31);

    // Print the decimal value
    printf("%u(10)\n", num);

    // Print the binary representation
    printBinary(num);

    // Extract and print the 4-bit segment as a hexadecimal digit
    char hexDigit = extractHexDigit(num, position);
    printf("%c(16)\n", hexDigit);

    return 0;
}
// ILIIIII
#include <stdio.h>
#include <math.h>

int main () {
    int n, pozicija, counter = 0;
    printf("broj > ");
    scanf("%d", &n);

    do {
        printf("pozicija > ");
        scanf("%d", &pozicija);

    } while (pozicija < 3 || pozicija > 31);

    printf("%d(10)\n", n);
    int bitArray[32] = {0}, shiftArray[4];

    while (n > 0) {
        bitArray[31 - counter] = n % 2;
        n /= 2;
        counter++;
    }
    int j = 0, sum = 0;
    for (int i = pozicija; i > pozicija - 4; i--) {
        shiftArray[j] = bitArray[31 - i];
        j++;
    }

    for (int i = 0; i < 32; i++) {
        printf("%d", bitArray[i]);
    }
    printf("(2)\n");
    // for (int i = 0; i < 4; i++) {
    //     printf("%d", shiftArray[i]);
    // }
    int k = 0;
    for(int i = 3; i >= 0; i--) {
        sum += shiftArray[k] * pow(2, i);
        k++;
    }
    printf("%X(16)", sum);
    return 0;
}
