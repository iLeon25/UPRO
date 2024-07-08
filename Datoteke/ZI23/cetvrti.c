#include <stdio.h>
#define PRAG 80

int najstudenti(char *txtdat, char *bindat) {
    struct rezultat student;

    FILE *ulazniTok = fopen(txtdat, "r");
    FILE *izlazniTok = fopen(bindat, "wb");

    int brojac = 0;
    if(ulazniTok == NULL || izlazniTok == NULL) {
        return -1;
    }

    while(fscanf(ulazniTok, "%s %d", student.ime, &student.bodovi) == 2) {
        if(student.bodovi >= 80) {
            fwrite(&student, sizeof(student), 1, izlazniTok);
            brojac++;
        }
    }

    

    fclose(ulazniTok);
    fclose(izlazniTok);
    return brojac;
}
