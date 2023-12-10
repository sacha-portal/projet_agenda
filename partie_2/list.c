#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list createList(int nb_level){
    t_d_list list;
    list.max_level = nb_level;

    // Création de la liste des cellules en tête
    list.heads = (t_d_cell**) malloc(nb_level*sizeof(t_d_cell*));

    // Initialisation des pointeurs à NULL
    for (int i = 0; i < nb_level; i++){
        list.heads[i] = NULL;
    }
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
        temp_0 = list.heads[0]; // Tête du niveau 0
        printf("[list head_%d @-]--", i);
        temp_n = list.heads[i]; // Tête du niveau courant
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
    int level = cell->level;
    while (1){
        // Si la fin de la liste a été atteinte
        if (temp == NULL){
            // Si la liste est vide
            if (prec == NULL){
                // On ajoute la nouvelle tête
                list->heads[level] = cell;
                if(!(level)) return;
                temp = list->heads[--level];
            }else{
                // Sinon, on l'ajoute après la dernière cellule
                prec->next[level] = cell;
                if(!(level)) return;
                level--;
                temp = prec;
            }
            cell->next[level] = NULL;
        }

        // Si l'emplacement a été dépassée
        else if (temp->value > cell->value){
            // Si la cellule doit être rajoutée en tête
            if (prec == NULL){
                // On remplace la tête actuelle par la nouvelle
                cell->next[level] = list->heads[level];
                list->heads[level] = cell;
                if  (!(level)) return;
                temp = list->heads[--level];
            }else{
                // Sinon, on l'ajoute après la dernière cellule inférieure
                cell->next[level] = prec->next[level];
                prec->next[level] = cell;
                if  (!(level)) return;
                level--;
                temp = prec;
            }
        }else{
            // Progression dans la liste
            prec = temp;
            temp = temp->next[level];
        }
    }
}


int* createComparativeTab(int n){
    //Création d'un tableau contenant les niveaux de chaque cellule
    int i, a;
    int * tab;
    tab = (int*)malloc(n*sizeof(int));
    for (i = 1; i <= n; i++){
        a = i;

        // Niveau de la cellule
        int level = 0;

        // Tant que l'indice est pair, on augmente le niveau
        while (a % 2 == 0){
            a /= 2;
            level++;
        }

        // On enregistre le niveau dans le tableau
        tab[i-1] = level;
    }
    return tab;
}

//Fonction de recherche classique dans une liste chaînée (sur le niveau 0)
int classic_search(t_d_list l, int val){
    t_d_cell* temp = l.heads[0];
    while(temp != NULL){
        if(temp->value == val) return 1; //On a trouvé la valeur
        temp = temp->next[0];
    }
    return 0;
}

//Fonction de recherche à partir du niveau le plus haut
int level_search(t_d_list l, int val){
    if (l.heads[0] == NULL) return 0; //Si la liste est vide, on renvoie 0
    int i = l.max_level-1;
    t_d_cell* prev = NULL; //élément temporaire permettant de revenir à la cellule précédente en cas de besoin
    t_d_cell* temp = l.heads[i];
    while(i >= 0){
        if ((temp == NULL) || (temp->value > val)){ //Si on est arrivé à la fin de la liste, on descend d'un niveau
            if(i == 0)return 0; //Si on est au niveau 0, alors elle n'est pas dans la liste
            if(prev == NULL){ //Si la cellule est la première du niveau, on descend à la première cellule du niveau inférieur
                temp = l.heads[--i];
            }
            else{ //Sinon, on revient à la cellule précédente enregistrée dans temproot et on avance d'une cellule
                temp = prev->next[--i];
            }
        }
        else if(temp->value == val){ //On a trouvé la valeur
            return 1;
        } 
        else if(temp->value < val){ //On continue sur le même niveau
            prev = temp;
            temp = temp->next[i];
        }
    }
    return 0;
}

