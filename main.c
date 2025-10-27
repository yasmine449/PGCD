#include <stdio.h>
int main() {
    int a, b, reste;

    // Lecture des deux entiers
    printf("Entrez deux entiers positifs : ");
    scanf("%d %d", &a, &b);

    printf("\n--- Calcul du PGCD de %d et %d ---\n", a, b);

    // Sauvegarde des valeurs initiales pour l'affichage final
    int x = a, y = b;

    // Algorithme d’Euclide avec boucle TANT QUE
    while (b != 0) {
        reste = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, reste); // Étapes intermédiaires
        a = b;
        b = reste;
    }

    // Affichage du résultat
    printf("\nLe PGCD de %d et %d est : %d\n", x, y, a);

    return 0;
}
