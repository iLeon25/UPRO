#include <stdio.h>

int brojJednakih(char *trgovina1, char *trgovina2) {
    FILE *store1 = fopen (trgovina1, "r");
    FILE *store2 = fopen (trgovina2, "r");

    struct artikl_s {
        int sifra;
        double price;
    } artikl, pomocniArtikl;

    if (store1 == NULL || store2 == NULL) 
        return -1;

    int counter = 0, roundOfLoop = 0;

    while (fscanf(store1, "%d#%lf", &artikl.sifra, &artikl.price) == 2) {
        fseek(store2, 0L, SEEK_SET);
        while (fscanf(store2, "%d#%lf", &pomocniArtikl.sifra, &pomocniArtikl.price) == 2) {
            if (pomocniArtikl.sifra == artikl.sifra) {
                counter++;
            }
        }
    }

    fclose(store1);
    fclose(store2);
    return counter;

}
