#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell* createCell(void* val, int level){ //Création d'une cellule quelconque
    t_d_cell* cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = val; //Valeur ou information contenue dans la cellule (pointeur)
    cell->level = level; //Niveau de la cellule dans la skiplist
    cell->next = (t_d_cell**) calloc(level+1,sizeof(t_d_cell*)); //Allocation en mémoire de la cellule suivante, vers laquelle un pointeur
    return cell;

}