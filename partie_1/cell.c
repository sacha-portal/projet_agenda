#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell* createCell(int val, int level){
    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = val;
    cell->level = level;
    cell->next = (t_d_cell**) calloc(level,sizeof(t_d_cell*));
    return cell;

}