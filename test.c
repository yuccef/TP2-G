#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<assert.h>
#include<math.h>
#include <stdbool.h>



  
#define MAX_VERTICES 100 // Définir ici la taille maximale du graphe
// int graph[MAX_VERTICES][MAX_VERTICES];

   int graph[8][8] = {    //The matrix that we will test (Annex)
        {0,0,1,0,0,1,0,0},
        {0,0,0,0,0,0,1,1},
        {1,0,0,1,1,1,0,1},
        {0,0,1,0,0,0,1,0},
        {0,0,1,0,0,0,0,0},
        {1,0,1,0,0,0,1,1},
        {0,1,0,1,0,1,0,0},
        {0,1,1,0,0,1,0,0}
    };


int colors[MAX_VERTICES];
int nbr_sommets;



// test if the color is already used
bool is_color_used(int vertex, int color) {
    for (int i = 0; i < nbr_sommets; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return true;
        }
    }
    return false;
}

//choose the next color 
int get_next_color(int vertex) {
    int color = 1;
    while (is_color_used(vertex, color)) {
        color++;
    }
    //printf("the number of color is %d  \n",color);
    return color;
    
}

//color the graph
void color_graph() {
    for (int i = 0; i < nbr_sommets; i++) {
        colors[i] = get_next_color(i);
    }
}

/*the number of colors used*/
int nbr_color(){
    int min=0;
    for (int i = 0; i < nbr_sommets; i++) {
     if(colors[i] >= min) min=colors[i];
      }
    return min;
}



bool is_planar() {
    // Vérification du nombre de sommets
    if (nbr_sommets <= 4) {
        return true;
    }
    // Vérification du nombre d'arêtes
    int nbr_aretes = 0;
    for (int i = 0; i < nbr_sommets; i++) {
        for (int j = i+1; j < nbr_sommets; j++) {
            if (graph[i][j]) {
                nbr_aretes++;
            }
        }
    }
    if (nbr_aretes > (3 * nbr_sommets - 6)) { //ne contient ni  K5 ni K3,3
        return false;
    }
    // Vérification des sous-graphes complets
    for (int i = 0; i < nbr_sommets; i++) {
        for (int j = i+1; j < nbr_sommets; j++) {
            if (graph[i][j]) {
                for (int k = j+1; k < nbr_sommets; k++) {
                    if (graph[i][k] && graph[j][k]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/*test */
int main() {



    /*Partie 1 , Question 1*/
    printf("\n");
    printf(" le nombre monochromatique est le nombre de couleurs qu'on peut utilise \n pour colorier tous les sommets d'un graphe ,\n le nombre monochromatique est definie par \n Taille_Max_Clique(graph) < nombre monochromatique < D(graph)+1");
    printf("\n");


    /*Partie 1 , Question 2*/

    nbr_sommets = 8;

    // Coloration des sommets du graphe
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
