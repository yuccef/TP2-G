#include "partie2.h"

int main()
{   
   
    printf("------Matrice de l'annexe :------\n");
    afficher_matrice(M);
    
    // Coloriage de la matrice
    heuristique_gloutonne(M);
    
    // Calcul et affichage du nombre d'arete
    printf("\n------Coloriage des aretes------\n");
    heuristique_gloutonne_arete(M);
    printf("Nombres de couleurs utilisées : %d \n", nb_color_arete());
    
    return 0;
}