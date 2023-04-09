#include"partie1.h"

/*test */
int main() {



    /*Partie 1 , Question 1*/
    printf("\n");
    printf(" le nombre monochromatique est le nombre de couleurs qu'on peut utilise \n pour colorier tous les sommets d'un graphe ,\n le nombre monochromatique est definie par \n Taille_Max_Clique(graph) < nombre monochromatique < D(graph)+1");
    printf("\n");


    /*Partie 1 , Question 2*/

    nbr_sommets = 8;

    // Coloration des sommets du graphe
    // la fonction si dessous s'occupe de la coloration de graphe
    color_graph();
    int  n= nbr_color();

    // Affichage des couleurs attribuées à chaque sommet
    printf("Couleurs attribuees aux sommets :\n");
    for (int i = 0; i < nbr_sommets; i++) {
        printf("Sommet %d : couleur %d\n", i+1, colors[i]);
    }
    
    printf("\n");
    printf("le nombre de couleurs utilises est %d \n", n);


    /*Partie 1 , Question 3 */
        
    printf("\n");
    printf(" Un graphe planaire est un graphe qui peut etre dessine sur un plan \n de telle maniere que ses aretes ne se croisent jamais \n. Autrement dit, il peut etre represente sans que ses aretes ne se superposent.\n");
    printf("\n");
    printf("\n");


    printf("Si un graphe est planaire, alors il est toujours possible \n de le colorier avec au plus 4 couleurs, de telle sorte \n que deux sommets adjacents ne soient jamais de la meme couleur.\n Cette propriete est connue sous le nom de theoreme des quatre couleurs,\n et elle est l'un des resultats les plus celebres de la theorie des graphes. \n");

    printf("\n");
    printf("\n");

    if (is_planar()) {
        printf("Le graphe est planaire.\n");
    } else {
        printf("Le graphe n'est pas planaire.\n");
    }
    
    /*Partie 1 , Question 4  */

 
    return 0;
}
