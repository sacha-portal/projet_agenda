#ifndef PROJET_AGENDA_S3_RDV_H
#define PROJET_AGENDA_S3_RDV_H

#include "list.h"
#include "contact.h"

//Définition de la structure date, utilisée pour les dates des RDV
typedef struct s_date{
    int jour;
    int mois;
    int annee;
} t_date;

//Définition de la structure horaire, utilisée pour l'horaire du début d'un RDV et pour sa durée
typedef struct s_horaire{
    int heure;
    int minute;
} t_horaire;

//Définition de la structure RDV
typedef struct s_rdv{
    t_date* date;
    t_horaire* horaire;
    t_horaire* duree;
    char* objet;
} t_rdv;

//Création d'un RDV qui assemble date, horaire, durée et objet
t_rdv* createRDV(t_date* date, t_horaire* horaire, t_horaire* duree, char* objet);

//Création d'une date qui assemble jour, mois et année
t_date* createDate(int jour, int mois, int annee);

//Création d'un horaire qui assemble heures et minutes
t_horaire* createHoraire(int heure, int minute);

//Affichage d'un RDV
void printRDV(t_rdv* rdv);

//Saisie sécurisée d'un objet de RDV
char* scanObj();

//Saisie sécurisée des informations relatives à un RDV
t_rdv* scanRDV();

#endif