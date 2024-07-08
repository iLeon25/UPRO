#include <stdio.h>
#define MAX 40
int placeAdreseZaposlenika(char *dat1, char *dat2) {
    FILE *input1 = fopen(dat1, "r");
    FILE *input2 = fopen(dat2, "r");
    int counter = 0;
    float total = 0;

    if (input1 == NULL || input2 == NULL)
        return -1;


    struct place_s {
        int sifra;
        float placa;
    } place;

    struct osobniPodatci_s {
        int sifra;
        int postanskiBroj;
        char name[MAX + 1];
        char address[MAX + 1];
        char city[MAX + 1];
    } podatci;

    while (fscanf(input1, "%d#%f", &place.sifra, &place.placa) == 2) {
        fseek(input2, 0L, SEEK_SET);
        //printf("Tu sam");
        while (fscanf(input2, "%d,%[^,],%[^,],%d %[^,],\n", &podatci.sifra, podatci.name, podatci.address, &podatci.postanskiBroj, podatci.city) == 5) {
            if (place.sifra == podatci.sifra) {
                counter++;
                total += place.placa;
                printf("%d. %d, %s, %s, %d %s, %.2f\n", counter, podatci.sifra, podatci.name
                                                     , podatci.address, podatci.postanskiBroj
                                                     , podatci.city, place.placa);
            }
        }
    }
    printf("Ukupno: %.2f\n", total);
    fclose(input1);
    fclose(input2);
    return counter;
}
