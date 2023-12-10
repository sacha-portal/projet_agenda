#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list createList(int nb_level){
    t_d_list list;
    list.max_level = nb_level;

    // Création de la liste des cellules en tête
    list.heads = (t_d_cell**) calloc(nb_level,sizeof(t_d_cell*));
    return list;
}

void displayOneLevel(t_d_list list, int level){
    printf("[list head_%d @-]-->", level);
    // Affichage des valeurs de chaque cellule
    t_d_cell* temp = list.heads[level];
    while(temp != NULL){
        printf("[%-3d|@-]-->", temp->value);
        temp = temp->next[level]; // Progression dans la liste
    }
    printf("NULL\n");
}

void displayAllLevels(t_d_list list){
    // Appel de la fonction précédente autant de fois qu'il y a de niveaux
    for(int i = 0; i < list.max_level; i++) displayOneLevel(list, i);
}

void betterDisplay(t_d_list list){
    displayOneLevel(list, 0); // Premier affichage inchangé
    t_d_cell *temp_0, *temp_n;
    for(int i = 1; i < list.max_level; i++){
        temp_0 = list.heads[0]; // Cellules du niveau 0
        printf("[list head_%d @-]--", i);
        temp_n = list.heads[i];
        while(temp_0 != NULL){
            // Si la cellule du niveau 0 a atteint celle du niveau courant
            if (temp_0 == temp_n){
                printf(">[%-3d|@-]--", temp_n->value);
                // Passage à la prochaine cellule du niveau 0 et du niveau courant
                temp_0 = temp_0->next[0];
                temp_n = temp_n->next[i];
            // Sinon
            }else{
                printf("-----------");
                // Passage à la prochaine cellule du niveau 0
                temp_0 = temp_0->next[0];
            }
        }
        printf(">NULL\n");
    }
}

void insertHead(t_d_list* list, t_d_cell* cell){
    for(int i = 0; i <= cell->level; i++){

        //Interchangage de l'ancienne tête de chaque niveau avec la nouvelle tête
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}

void insertCell(t_d_list* list, t_d_cell* cell){
    t_d_cell* temp = list->heads[cell->level];
    t_d_cell* prec = NULL;
    while (1){
        // Si la fin de la liste a été atteinte
        if (temp == NULL){
            // Si la liste est vide
            if (prec == NULL){
                list->heads[cell->level] = cell;
                if  (!(cell->level)) return;
                cell->level--;
                temp = list->heads[cell->level];
            }else{
                prec->next[cell->level] = cell;
                if  (!(cell->level)) return;
                cell->level--;
                temp = prec;
            }
            cell->next[cell->level] = NULL;
        }
        // Si l'emplacement a été dépassée
        else if (temp->value > cell->value){
            // Si la cellule doit être rajoutée en tête
            if (prec == NULL){
                cell->next[cell->level] = list->heads[cell->level];
                list->heads[cell->level] = cell;
                if  (!(cell->level)) return;
                cell->level--;
                temp = list->heads[cell->level];
            }else{
                cell->next[cell->level] = prec->next[cell->level];
                prec->next[cell->level] = cell;
                if  (!(cell->level)) return;
                cell->level--;
                temp = prec;
            }
        }else{
            // Progression dans la liste
            prec = temp;
            temp = temp->next[cell->level];
        }
    }
}