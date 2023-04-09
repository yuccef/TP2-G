#ifndef __TP2_H__
#define __TP2_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define N 8


int color[N][N];
int colors[50];
int Mat[N][N]; // Graphe aléatoire
int M[8][8] = { // Graphe de l'annexe
        {0,0,1,0,0,1,0,0},
        {0,0,0,0,0,0,1,1},
        {1,0,0,1,1,1,0,1},
        {0,0,1,0,0,0,1,0},
        {0,0,1,0,0,0,0,0},
        {1,0,1,0,0,0,1,1},
        {0,1,0,1,0,1,0,0},
        {0,1,1,0,0,1,0,0}};
        

// Partie 2
bool is_color_used_arete(int i, int j, int color, int M[N][N]); // Retourne vrai si la couleur est utilisée, faux sinon
int couleur_suivante_arete(int i, int j, int M[N][N]); // Retourne une nouvelle couleur
void heuristique_gloutonne_arete(int M[N][N]); // Colorie les arêtes avec une heuristique gloutonne
int nb_color_arete(); // Retourne le nombre de couleur utilisées

// Tool box
void generate_graph(float p, int M[N][N]); // Génère une matrice aléatoire de densité p
void afficher_matrice(int M[N][N]); // Afficher la matrice M


bool is_color_used_arete(int i, int j, int couleur, int M[N][N]) 
{
    for(int k = 0; k < N; k++)
        if(color[i][k] != 0 && color[i][k] == couleur)
            return true;
    for(int ii = 0; ii < N; ii++)
        if(color[ii][j] != 0 && color[ii][j] == couleur)
            return true;
    return false;
}

int couleur_suivante_arete(int i, int j, int M[N][N])
{
    int color = 1;
    while (is_color_used_arete(i, j, color, M))
        color++;    
    return color;
}

void heuristique_gloutonne_arete(int M[N][N]) 
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            if (M[i][j])
                color[i][j] = couleur_suivante_arete(i, j, M);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (M[i][j] == 1)
                    printf("%d -> %d : couleur %d\n", i+1, j+1, color[i][j]);
        }
    }
}

int nb_color_arete()
{
    int min=0;
    for (int i = 0; i < N; i++)
        for(int j = 0; j<N; j++)
            if(color[i][j] >= min) 
                min=color[i][j];
    return min;
}

int nb_color()
{
    int min=0;
    for (int i = 0; i < N; i++)
     if(colors[i] >= min) 
        min=colors[i];
    return min;
}

bool is_color_used(int vertex, int color, int M[N][N])
{
    for (int i = 0; i < N; i++)
        if (M[vertex][i] && (colors[i] == color))
            return true;
    return false;
}

int couleur_suivante(int vertex, int M[N][N])
{
    int color = 1;
    while (is_color_used(vertex, color, M))
        color++;
    return color;
}

void heuristique_gloutonne(int M[N][N]) 
{
    for (int i = 0; i < N; i++) 
        colors[i] = couleur_suivante(i, M);
}

void generate_graph(float p, int M[N][N])
{
    if(p>1)
        exit(1);
    srand(time(NULL));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            double v = rand();
            float u = v/RAND_MAX;
            if(u<p)
                M[i][j] = 1;
            else
                M[i][j] = 0;
        }
    }
}

void afficher_matrice(int M[N][N])
{
    int i, j ;
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ; j++)
        {
            printf("%d  ", M[i][j]) ;
        }
        printf("\n") ;
    }
    printf("\n\n") ;
}

#endif