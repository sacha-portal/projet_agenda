#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"


static t_d_list* list_agenda = NULL;

// Initlialise la liste des agendas statique
t_d_list* initListAgenda(){
    list_agenda = createList(LEVEL_AGENDA);
    return list_agenda;
}

// Création d'un agenda contenant le contact associé et en créant la liste de RDV du contact
t_agenda* createAgenda(t_contact* contact){
    t_agenda* new_agenda = (t_agenda*) malloc(sizeof(t_agenda));
    new_agenda->contact = contact;
    new_agenda->rdvs = createList(1);
    return new_agenda;
}

//Recherche d'un agenda à partir du nom et prénom d'un contact
t_agenda* findAgenda(char* name, char* first_name){
    //Parcours de la liste d'agendas pour trouver le contact demandé
    int comp_name, comp_fn;
    int level = LEVEL_AGENDA-1;
    t_d_cell *temp = list_agenda->heads[level];
    t_d_cell *prev = NULL;
    while(1){
        while (temp == NULL){
            if (!level) return NULL;
            if(prev == NULL){ //Si la cellule est la première du niveau, on descend à la première cellule du niveau inférieur
                temp = list_agenda->heads[--level];
            }
            else{ //Sinon, on revient à la cellule précédente enregistrée dans temproot et on avance d'une cellule
                temp = prev->next[--level];
            }
        }
        comp_name = strcmp(((t_contact*)temp->value)->name, name);
        comp_fn = strcmp(((t_contact*)temp->value)->first_name, first_name);
        if(!comp_name){
            if (!comp_fn) return temp->value;
            else comp_name = comp_fn;
        } if (comp_name > 0){
            //Même comportement que pour temp == NULL
            if (!level) return NULL;
            if(prev == NULL){
                temp = list_agenda->heads[--level];
            }
            else{
                temp = prev->next[--level];
            }
        }else if(comp_name < 0){ //On continue sur le même niveau
            prev = temp;
            temp = temp->next[level];
        }
        temp=temp->next[level];
    }
}

//Insertion d'un nouvel agenda dans la liste d'agendas
void insertAgenda(t_agenda* new_agenda){
    //Parcours de la liste d'agendas pour trouver le contact demandé
    int comp_name, comp_fn;
    int level = LEVEL_AGENDA-1;
    t_d_cell *new_cell = createCell(new_agenda, 3);
    t_d_cell *temp = list_agenda->heads[level];
    t_d_cell *prev = NULL;
    while(1){
        // Si la fin de la liste a été atteinte
        while (temp == NULL){
            // Si la liste est vide
            if (prev == NULL){
                // On ajoute la nouvelle tête
                list_agenda->heads[level] = new_cell;
                if(!(level)) return;
                temp = list_agenda->heads[--level];
            }else{
                // Sinon, on l'ajoute après la dernière cellule
                prev->next[level] = new_cell;
                if(!(level)) return;
                level--;
                temp = prev;
            }
            new_cell->next[level] = NULL;
        }
        comp_name = strcmp(((t_contact*)temp->value)->name, new_agenda->contact->name);
        comp_fn = strcmp(((t_contact*)temp->value)->first_name, new_agenda->contact->first_name);
        if (comp_name > 0){
            // Si la cellule doit être rajoutée en tête
            if (prev == NULL){
                // On remplace la tête actuelle par la nouvelle
                new_cell->next[level] = list_agenda->heads[level];
                list_agenda->heads[level] = new_cell;
                if  (!(level)) return;
                temp = list_agenda->heads[--level];
            }else if (level) {
                if (((t_contact *) prev->value)->name[3 - level] < new_agenda->contact->name[3 - level]) {
                    new_cell->next[level] = prev->next[level];
                    prev->next[level] = new_cell;
                    level--;
                    temp = prev;
                }
            }else{
                new_cell->next[level] = prev->next[level];
                prev->next[level] = new_cell;
                return;

            }
        }else if(comp_name < 0){ //On continue sur le même niveau
            prev = temp;
            temp = temp->next[level];
        }
        temp=temp->next[level];
    }
}

//Insertion d'un RDV dans un agenda
void insertRDVAgenda(t_agenda* agenda, t_rdv* rdv){
    t_d_cell* new_cell = createCell(rdv, 0);
    new_cell->next[0] = agenda->rdvs->heads[0];
    agenda->rdvs->heads[0] = new_cell;
}

// Affichage de tous les RDV d'un contact
void printRDVcontact(t_agenda* agenda){
    for(t_d_cell* cell_rdv = agenda->rdvs->heads[0]; cell_rdv != NULL; cell_rdv = cell_rdv->next[0]){
        printRDV(cell_rdv->value);
    }
}

//Suppression d'un RDV d'un agenda
int delRDVagenda(t_agenda* agenda, char* objet, t_date* date){
    t_rdv* rdv;
    t_d_cell *cell_rdv = agenda->rdvs->heads[0];
    t_d_cell *prev = NULL;
    while(cell_rdv != NULL){
        rdv = (t_rdv*) cell_rdv->value;
        if (strcmp(objet, rdv->objet) == 0 && date->annee == rdv->date->annee && date->mois == rdv->date->mois && date->jour == rdv->date->jour){
            free(rdv->objet);
            free(rdv);
            if (prev == NULL) agenda->rdvs->heads[0] = cell_rdv->next[0];
            else prev->next[0] = cell_rdv->next[0];
            return 1;
        }
        cell_rdv = cell_rdv->next[0];
    }
    return 0;
}