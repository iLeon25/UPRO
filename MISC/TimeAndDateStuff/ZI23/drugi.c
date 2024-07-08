void danMjesec(int rbrDanGodina, int *dan, int *mjesec) {

    int brojevi_Dana[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;

    // Racunanje mjeseca

    int broj_Mjeseci = 0;
    int redni_Broj = rbrDanGodina;

    while (redni_Broj > 0)
    {
        redni_Broj -= brojevi_Dana[broj_Mjeseci];

        broj_Mjeseci++;
    }
    
    *mjesec = broj_Mjeseci;

    // Racunanje dana

    for (i = 0; i < broj_Mjeseci; i++)
    {
        if (rbrDanGodina - brojevi_Dana[i] > 0)
        {
            rbrDanGodina -= brojevi_Dana[i];
        }
        else
        {
            break;
        }
    }
    
    *dan = rbrDanGodina;

    return;
}
