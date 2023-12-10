#ifndef PROJET_AGENDA_S3_CONTACT_H
#define PROJET_AGENDA_S3_CONTACT_H

#include "list.h"

//Définition de la structure contact
typedef struct s_contact{
    char* first_name;
    char* name;
} t_contact;

//Création d'un contact
t_contact* createContact(char* first_name, char* name);

//Saisie d'un contact
t_contact* scanContact();


#endif