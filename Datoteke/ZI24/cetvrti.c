#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool podaciZaKatProizv (char *c, char *category, int *noOfProducts, float *lowest, float *highest) {
    FILE *ulazniTok = fopen(c, "r");

    int numberOf = 0;
    float lowestL = 10000000, highestL = 0;
    
    struct product {
        int code;
        char category[20 + 1]; 
        char prodName[50 + 1];
        float price;

    } proizvod;

    if (ulazniTok == NULL) 
        return 0;

    while (fscanf(ulazniTok, "%d#%[^#]#%[^#]#%f", &proizvod.code, proizvod.category, proizvod.prodName, &proizvod.price) == 4) {
        if (strcmp(proizvod.category, category) != 0) {
            continue;
        }

        if (proizvod.price < lowestL)
            lowestL = proizvod.price;

        if (proizvod.price > highestL)
            highestL = proizvod.price;

        numberOf++;
    }
    *lowest = lowestL;
    *highest = highestL;
    *noOfProducts = numberOf;

    return 1;
}

int main(void){
    char imeDat[128+1];
    char nazKat[20+1];
    printf("Naziv datoteke: ");
    scanf("%s%*c", imeDat);
    printf("Kategorija proizvoda: ");
    scanf("%[^\n]", nazKat);
    int brojProizv;
    float najNizaC, najVisaC;

    if (podaciZaKatProizv(&imeDat[0], &nazKat[0], &brojProizv, &najNizaC, &najVisaC) == 1) {
        if (brojProizv != 0) {
            //printf("%s\n", imeDat);
            //printf("%s\n", nazKat);
            printf("Broj proizvoda, najniza i najvisa cijena: ");
            printf("%d %.2f %.2f", brojProizv, najNizaC, najVisaC);
        } else {
            printf("Nema proizvoda u navedenoj kategoriji.");
        }
    } else {
        printf("Ne postoji datoteka.");
    }

    return 0;
}
