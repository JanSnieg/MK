//
//  unionFind.cpp
//  modelowanie_18_POlszowy_lista5zad2
//
//  Created by Jan Śnieg on 02/06/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include "unionFind.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NDEBUG

int *labels;
int  n_labels = 0;


int uf_find(int x)
{
    int y = x;
    while (labels[y] != y)
        y = labels[y];
    
    while (labels[x] != x)
    {
        int z = labels[x];
        labels[x] = y;
        x = z;
    }
    return y;
}

int uf_union(int x, int y)
{
    return labels[uf_find(x)] = uf_find(y);
}

int uf_make_set(void) {
    labels[0] ++;
    assert(labels[0] <= n_labels);
    labels[labels[0]] = labels[0];
    return labels[0];
}

/*  uf_intitialize sets up the data structures needed by the union-find implementation. */

void uf_initialize(int max_labels) {
    n_labels = max_labels;
    labels = (int*)calloc(sizeof(int), n_labels);
    labels[0] = 0;
}

/*  uf_done frees the memory used by the union-find data structures */

void uf_done(void) {
    n_labels = 0;
    free(labels);
    labels = 0;
}

/* End Union-Find implementation */

#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

/* print_matrix prints out a matrix that is set up in the "pointer to pointers" scheme
 (aka, an array of arrays); this is incompatible with C's usual representation of 2D
 arrays, but allows for 2D arrays with dimensions determined at run-time */

void print_matrix(int **matrix, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf("%3d ",matrix[i][j]);
        printf("\n");
    }
}


/* Label the clusters in "matrix".  Return the total number of clusters found. */

int hoshen_kopelman(int **matrix, int m, int n) {
    
    uf_initialize(m * n / 2);
    
    /* scan the matrix */
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (matrix[i][j]) {                        // if occupied ...
                
                int up = (i==0 ? 0 : matrix[i-1][j]);    //  look up
//                int upleft = (i==0 && j==0 ? 0 : matrix[i-1][j-1]); //look upleft
                int left = (j==0 ? 0 : matrix[i][j-1]);  //  look left
                
                switch (!!up + !!left){//} + !!upleft) {
                        
                    case 0:
                        matrix[i][j] = uf_make_set();      // a new cluster
                        break;
                        
                    case 1:                              // part of an existing cluster
                        matrix[i][j] = max(up,left);       // whichever is nonzero is labelled
                        break;
                        
                    case 2:                              // this site binds two clusters
                        matrix[i][j] = uf_union(up, left);
                        break;
                }
                
            }
    
    /* apply the relabeling to the matrix */
    
    /* This is a little bit sneaky.. we create a mapping from the canonical labels
     determined by union/find into a new set of canonical labels, which are
     guaranteed to be sequential. */
    
    int *new_labels = (int*)calloc(sizeof(int), n_labels); // allocate array, initialized to zero
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (matrix[i][j]) {
                int x = uf_find(matrix[i][j]);
                if (new_labels[x] == 0) {
                    new_labels[0]++;
                    new_labels[x] = new_labels[0];
                }
                matrix[i][j] = new_labels[x];
            }
    
    int total_clusters = new_labels[0];
    
    free(new_labels);
    uf_done();
    
    return total_clusters;
}

/* This procedure checks to see that any occupied neighbors of an occupied site
 have the same label. */

void check_labelling(int **matrix, int m, int n) {
    int N,S,E,W;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (matrix[i][j]) {
                N = ( i==0 ? 0 : matrix[i-1][j] );
                S = ( i==m-1 ? 0 : matrix[i+1][j] );
                E = ( j==n-1 ? 0 : matrix[i][j+1] );
                W = ( j==0 ? 0 : matrix[i][j-1] );
                
                assert( N==0 || matrix[i][j]==N );
                assert( S==0 || matrix[i][j]==S );
                assert( E==0 || matrix[i][j]==E );
                assert( W==0 || matrix[i][j]==W );
            }
}

