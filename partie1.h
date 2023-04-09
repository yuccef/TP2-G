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

