#include <stdio.h>

void compress(unsigned char *p, int len) {
    int i, j = 0;
    
    // Iteracija kroz polje s korakom 2
    for (i = 0; i < len; i += 2) {
        unsigned char left, right;
        
        // Ako je preostao samo jedan element (neparna duljina)
        if (i + 1 < len) {
            left = p[i] & 0x0F;      // Desna polovica prvog elementa
            right = p[i + 1] & 0x0F; // Desna polovica drugog elementa
            p[j] = (left << 4) | right; // Kombiniraj ih
        } else {
            left = p[i] & 0x0F;      // Desna polovica zadnjeg elementa
            p[j] = (left << 4);      // Pomakni u lijevu polovicu
        }
        j++;
    }
}
