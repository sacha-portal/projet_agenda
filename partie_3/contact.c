#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

//Création d'un contact
t_contact* createContact(char* first_name, char* name){
    t_contact* new_contact = (t_contact*) malloc(sizeof(t_contact));
    new_contact->first_name = first_name;
    new_contact->name = name;
    return new_contact;
}

// Saisie sécurisée du prénom et du nom d'un contact
t_contact* scanContact(){
    char* r = NULL;
    printf("\nSaisie du prénom : ");
    char* fn = (char*) malloc(100*sizeof(char));
    fflush(stdin);
    r = fgets(fn, 100, stdin);
    while (r == NULL){
        printf("\nErreur dans la saisie du prénom, veuillez réessayer : ");
        fflush(stdin);
        r = fgets(fn, 100, stdin);
    }

    // Tout caractère non imprimable en début de saisie est supprimé
    while (fn[0] <= 32) fn++;

    // Décompte du nombre de caractère de la chaine
    int i;
    for(i = 0; fn[i]=='\0'; i++);

    // Même suppression pour la fin de la chaine de caractères
    while (fn[i-1] <= 32){
        fn[i-1] = '\0';
        i--;
    }
    r = NULL;
    printf("\nSaisie du nom : ");
    char* name = (char*) malloc(100*sizeof(char));
    fflush(stdin);
    r = fgets(name, 100, stdin);
    while (r == NULL){
        printf("\nErreur dans la saisie du nom, veuillez réessayer : ");
        fflush(stdin);
        r = fgets(name, 100, stdin);
    }

    while (name[0] <= 32) name++;
    i = 0;
    for(i = 0; name[i]=='\0'; i++);
    while (name[i-1] <= 32){
        name[i-1] = '\0';
        i--;
    }
    return createContact(fn,name);
}