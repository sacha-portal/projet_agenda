#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list* createList(int nb_level){
    t_d_list* list = malloc(sizeof(t_d_list));
    list->max_level = nb_level;

    // Création de la liste des cellules en tête
    list->heads = (t_d_cell**) calloc(nb_level,sizeof(t_d_cell*));
    return list;
}
