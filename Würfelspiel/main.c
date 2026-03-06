#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wuerfeln() {
    return rand() % 6 + 1;
}

int main() {
    char *spieler[2] = {"Alice", "Bob"};
    int punkte[2] = {0, 0};
    int gewinner_punkte = 100;
    int aktueller_spieler = 0;

    srand(time(NULL));

    while (punkte[0] < gewinner_punkte && punkte[1] < gewinner_punkte) {
        printf("\n%s ist am Zug. Aktuelle Punkte: %d\n", spieler[aktueller_spieler], punkte[aktueller_spieler]);
        int runden_punkte = 0;
        char weiter = 'j';

        while (weiter == 'j' || weiter == 'J') {
            int wurf = wuerfeln();
            printf("%s wuerfelt eine %d\n", spieler[aktueller_spieler], wurf);

            if (wurf == 1) {
                printf("Runde beendet, keine Punkte!\n");
                runden_punkte = 0;
                break;
            } else {
                runden_punkte += wurf;
                printf("Rundenpunkte bisher: %d\n", runden_punkte);
                printf("Moechtest du noch einmal wuerfeln? (j/n): ");
                scanf(" %c", &weiter);
            }
        }

        punkte[aktueller_spieler] += runden_punkte;
        printf("%s hat jetzt %d Punkte\n", spieler[aktueller_spieler], punkte[aktueller_spieler]);

        if (punkte[aktueller_spieler] >= gewinner_punkte) {
            printf("\n%s hat gewonnen mit %d Punkten!\n", spieler[aktueller_spieler], punkte[aktueller_spieler]);
        } else {
            aktueller_spieler = (aktueller_spieler + 1) % 2;
        }
    }

    return EXIT_SUCCESS;
}
