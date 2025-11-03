#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    int x0, y0, q, r;
    int a1, b1;
    int d;

    // Saisie des valeurs
    printf("Entrez les valeurs de a, b et c : ");
    scanf("%d %d %d", &a, &b, &c);

    // Étape 1 : Calcul du PGCD avec l’algorithme d’Euclide
    a1 = a;
    b1 = b;
    while (b1 != 0) {
        r = a1 % b1;
        a1 = b1;
        b1 = r;
    }
    d = a1;
    printf("\nPGCD(%d, %d) = %d\n", a, b, d);

    // Étape 2 : Verifier l’existence de solution
    if (c % d != 0) {
        printf("Pas de solution entiere, car %d ne divise pas %d.\n", d, c);
        return 0;
    }

    // Étape 3 : Trouver une solution particuliere avec l’algorithme d’Euclide étendu (version simple)
    int u1 = 1, v1 = 0, u2 = 0, v2 = 1;
    int aa = a, bb = b;
    while (bb != 0) {
        q = aa / bb;
        r = aa % bb;
        int u = u1 - q * u2;
        int v = v1 - q * v2;
        aa = bb;
        bb = r;
        u1 = u2;
        v1 = v2;
        u2 = u;
        v2 = v;
    }

    // Solution particuliere
    x0 = u1 * (c / d);
    y0 = v1 * (c / d);

    printf("\nUne solution particuliere est : (x, y) = (%d, %d)\n", x0, y0);

    // Étape 4 : Solution generale
    printf("La solution generale est :\n");
    printf("x = %d + k*(%d)\n", x0, b / d);
    printf("y = %d - k*(%d)\n", y0, a / d);
    printf("où k est un entier)\n");

    return 0;
}
