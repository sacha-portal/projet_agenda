#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell* createCell(int val, int level){
    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = val;
    cell->level = level;

    // Création du tableau de pointeurs vers les cellules suivantes
    cell->next = (t_d_cell**) malloc((level+1)*sizeof(t_d_cell*));

    // Initialisation des pointeurs à NULL
    for(int i = 0; i <= level; i++){
        cell->next[i] = NULL;
    }
    return cell;

}