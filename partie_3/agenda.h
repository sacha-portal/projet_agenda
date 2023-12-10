#ifndef PROJET_AGENDA_S3_AGENDA_H
#define PROJET_AGENDA_S3_AGENDA_H

#include "rdv.h"
#include "contact.h"

//Définition de la structure agenda
typedef struct s_agenda{
    t_contact* contact;
    t_d_list* rdvs;
} t_agenda;

#define LEVEL_AGENDA 4 //Il y a 4 niveaux dans la skiplist d'agendas

// Initlialise la liste des agendas statique
t_d_list* initListAgenda();

// Création d'un agenda contenant le contact associé et en créant la liste de RDV du contact
t_agenda* createAgenda(t_contact* contact);

//Recherche d'un agenda à partir du nom et prénom d'un contact
t_agenda* findAgenda(char* name, char* first_name);

//Insertion d'un nouvel agenda dans la liste d'agendas
void insertAgenda(t_agenda* new_agenda);

//Insertion d'un RDV dans la liste de RDV d'un agenda
void insertRDVAgenda(t_agenda* agenda, t_rdv* rdv);

//Affichage de tous les RDV d'un contact
void printRDVcontact(t_agenda* agenda);

//Supression d'un RDV d'un agenda
int delRDVagenda(t_agenda* agenda, char* objet, t_date* date);

#endif