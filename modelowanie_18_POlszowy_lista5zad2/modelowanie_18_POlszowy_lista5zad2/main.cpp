//
//  main.cpp
//  modelowanie_18_POlszowy_lista5zad2
//
//  Created by Jan Śnieg on 02/06/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include <iostream>
#include "unionFind.hpp"

int main(int argc, char **argv) {
    
    int m,n;
    int **matrix;
    
    /* Read in the matrix from standard input
     The whitespace-deliminated matrix input is preceeded
     by the number of rows and number of columns */
    
    while (2 == scanf("%d %d",&m,&n)) {  // m = rows, n = columns
        
        matrix = (int **)calloc(m, sizeof(int*));
        
        for (int i=0; i<m; i++) {
            matrix[i] = (int *)calloc(n, sizeof(int));
            for (int j=0; j<n; j++)
                scanf("%d",&(matrix[i][j]));
        }
        
        printf(" --input-- \n");
        
        print_matrix(matrix,m,n);
        
        printf(" --output-- \n");
        
        /* Process the matrix */
        
        int clusters = hoshen_kopelman(matrix,m,n);
        
        /* Output the result */
        
        print_matrix(matrix,m,n);
        
        check_labelling(matrix,m,n);
        
        printf("HK reports %d clusters found\n", clusters);
        
        for (int i=0; i<m; i++)
            free(matrix[i]);
        free(matrix);
    }
    
    return 0;
}
