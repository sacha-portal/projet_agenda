#include <stdio.h>
#include <stdlib.h>
#include "rdv.h"

//Création et insertion d'un RDV dans la liste des RDV d'un contact
t_rdv* createRDV(t_date* date, t_horaire* horaire, t_horaire* duree, char* objet){
    t_rdv* new_rdv = (t_rdv*) malloc(sizeof(t_rdv));
    new_rdv->date = date;
    new_rdv->horaire = horaire;
    new_rdv->duree = duree;
    new_rdv->objet = objet;
    return new_rdv;
}

//Création d'une date qui assemble jour, mois et année
t_date* createDate(int jour, int mois, int annee){
    t_date* new_date = (t_date*) malloc(sizeof(t_date));
    new_date->jour = jour;
    new_date->mois = mois;
    new_date->annee = annee;
    return new_date;
}

//Création d'un horaire qui assemble heures et minutes
t_horaire* createHoraire(int heure, int minute){
    t_horaire* new_horaire = (t_horaire*) malloc(sizeof(t_horaire));
    new_horaire->heure = heure;
    new_horaire->minute = minute;
    return new_horaire;
}

//Saisie sécurisée d'un objet de RDV
char* scanObj(){
    char* r = NULL;
    char* str = (char*) malloc(200*sizeof(char));
    while (r == NULL){
        fflush(stdin);
        r = fgets(str, 200, stdin);
    }

    // Tout caractère non imprimable en début de saisie est supprimé
    while (str[0] <= 32) str++;

    // Décompte du nombre de caractère de la chaine
    int i;
    for(i = 0; str[i]=='\0'; i++);

    // Même suppression pour la fin de la chaine de caractères
    while ((str[i-1] <= 32) && (str[i-1])){
        str[i-1] = '\0';
        i--;
    }
    return str;
}

//Saisie sécurisée des informations relatives à un RDV
t_rdv* scanRDV(){
    int r = 0;
    printf("\nDate du rendez-vous (sous forme j/m/a) : ");
    int a = -1, m = -1, j = -1 ;
    fflush(stdin);
    r = scanf("%d/%d/%d", &j, &m, &a);
    while (r < 3 || m < 1 || m > 12 || j < 1 || j > 31 ){
        printf("\nErreur dans la saisie veuillez réessayer (sous forme j/m/a) : ");
        fflush(stdin);
        r = scanf("%d/%d/%d", &j, &m, &a);
    }
    t_date* date_rdv = createDate(j, m, a);

    r = 0;
    printf("\nHeure du rendez vous (sous forme \"heure\"h\"minutes\") :");
    int h1 = -1;
    int m1 = -1;
    fflush(stdin);
    r = scanf("%dh%d", &h1, &m1);
    while (r < 2 || h1 < 0 || h1 > 23 || m1 < 0 || m1 > 59 ){
        printf("\nErreur dans la saisie veuillez réessayer (sous forme \"heure\"h\"minutes\") : ");
        fflush(stdin);
        r = scanf("%dh%d", &h1, &m1);
    }
    t_horaire* heure_rdv = createHoraire(h1,m1);

    r = 0;
    printf("\nDurée du rendez vous (sous forme \"heure\"h\"minutes\") : ");
    int h2 = -1;
    int m2 = -1;
    fflush(stdin);
    r = scanf("%dh%d", &h2, &m2);
    while (r < 2 || h2 < 0 || h2 > 23 || m2 < 0 || m2 > 59 ){
        printf("\nErreur dans la saisie veuillez réessayer (sous forme \"heure\"h\"minutes\") : ");
        fflush(stdin);
        r = scanf("%dh%d", &h2, &m2);
    }
    t_horaire* duree_rdv = createHoraire(h2,m2);

    printf("\nObjet du rendez-vous : ");
    char* obj = scanObj();
    return createRDV(date_rdv,heure_rdv,duree_rdv, obj);
}

//Affichage d'un RDV
void printRDV(t_rdv* rdv){
    printf("\nObjet : %s", rdv->objet);
    printf("\nDébut du rendez-vous : %d/%d/%d à %dh%d", rdv->date->jour, rdv->date->mois, rdv->date->annee, rdv->horaire->heure, rdv->horaire->minute);
    printf("\nDurée du rendez-vous : %dh%d\n", rdv->duree->heure, rdv->duree->minute);
}
