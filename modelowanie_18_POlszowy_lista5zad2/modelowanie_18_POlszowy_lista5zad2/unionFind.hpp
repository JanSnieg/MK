//
//  unionFind.hpp
//  modelowanie_18_POlszowy_lista5zad2
//
//  Created by Jan Śnieg on 02/06/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

int hoshen_kopelman(int **matrix, int m, int n);
int uf_find(int x);
int uf_union(int x, int y);
void uf_initialize(int max_labels);
void uf_done(void);
void print_matrix(int **matrix, int m, int n);
int hoshen_kopelman(int **matrix, int m, int n);
void check_labelling(int **matrix, int m, int n);


