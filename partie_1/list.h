#ifndef PROJET_AGENDA_S3_LIST_H
#define PROJET_AGENDA_S3_LIST_H

#include "cell.h"

typedef struct s_d_list{
    t_d_cell **heads;
    int max_level;
} t_d_list;

t_d_list createList(int nb_level);
void insertHead(t_d_list* list, t_d_cell* cell);
void displayOneLevel(t_d_list list, int level);
void displayAllLevels(t_d_list list);
void betterDisplay(t_d_list list);
void insertCell(t_d_list* list, t_d_cell* cell);

#endif