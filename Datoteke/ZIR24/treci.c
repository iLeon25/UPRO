#include <stdio.h>
#include <string.h>
#define LOCATION 40
#define DATE 15
#define MAXNAME 20

struct dataPoints_s {
    int sifra;
    char opisLokacije[LOCATION + 1];
    char datumMjerenja[DATE + 1];
    float koncentracije[4];
};

int main () {
    struct dataPoints_s podatak;
    char imeDatoteke[MAXNAME + 1], mjesto[MAXNAME + 1];
    float granicnaVrijednost;
    printf("Unesite ime datoteke > ");
    scanf("%s", imeDatoteke);

    FILE *inputStream = fopen (imeDatoteke, "rb");

    printf("Unesite mjesto > ");
    scanf("%s", mjesto);

    printf("Unesite granicnu vrijednost > ");
    scanf("%f", &granicnaVrijednost);

    float avg, sum, counter = 0;

    printf("Sifra|Srednja koncentracija\n");
    while (fread(&podatak, sizeof(podatak), 1, inputStream) == 1) {
        sum = 0;
        if (strstr(podatak.opisLokacije, mjesto) != NULL) {
            for (int i = 0; i < 4; i++) {
                sum += podatak.koncentracije[i];
            }
            avg = sum / 4;
                if (avg > granicnaVrijednost) {
                    printf("%d|%.1f\n", podatak.sifra, avg);
                }
        }
    }
    fclose(inputStream);

    return 0;
}
