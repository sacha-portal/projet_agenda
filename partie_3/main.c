#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
#include "contact.h"
#include "timer.h"

//Projet de gestionnaire d'agendas en C par Mathias BENOIT, Eva MAROT et Sacha PORTAL

int main(){
    initListAgenda();
    int menu = 1;
    int choix = 0;
    int res = 0;
    int *a = NULL, *m = NULL, *j = NULL;
    char* obj = NULL;
    t_contact *cont;
    t_agenda *agenda;
    while(menu){
        printf("\nGESTIONNAIRE D'AGENDAS\n"
               "\t1- Rechercher un contact\n"
               "\t2- Creer un contact\n"
               "\t3- Quitter le programme\n\n"
               "Votre choix : ");
        fflush(stdin);
        res = scanf("%d", &choix);
        while (res < 0 || choix < 1 || choix > 3 ){
            printf("\n\nSaisie incorrecte, veuillez reessayer : ");
            fflush(stdin);
            res = scanf("%d", &choix);
        }
        switch(choix){
            case 1:
                cont = scanContact();
                startTimer();
                agenda = findAgenda(cont->name, cont->first_name);
                stopTimer();
                printf("\nTemps de recherche : %s", getTimeAsString());
                if (!agenda){
                    printf("\nContact non trouve\n");
                    break;
                }
                else while(choix != 4){
                        printf("Contact trouve !\n"
                               "Options :\n"
                               "\t1- Afficher les rendez-vous\n"
                               "\t2- Creer un rendez-vous\n"
                               "\t3- Supprimer un rendez-vous\n"
                               "\t4- Revenir au menu principal\n\n"
                               "Votre choix :");
                        fflush(stdin);
                        res = scanf("%d", &choix);
                        while (res < 0 || choix < 1 || choix > 4 ){
                            printf("\n\nSaisie incorrecte, veuillez reessayer : ");
                            fflush(stdin);
                            res = scanf("%d", &choix);
                        }
                        switch(choix){
                            case 1:
                                printRDVcontact(agenda);
                                break;
                            case 2:
                                insertRDVAgenda(agenda, scanRDV());
                                break;
                            case 3:
                                printf("\n\nObjet du RDV : ");
                                obj = scanObj();
                                t_date date = {-1,-1,-1};
                                printf("\nDate du rendez-vous (sous la forme j/m/a) : ");
                                fflush(stdin);
                                a = &date.annee;
                                m = &date.mois;
                                j = &date.jour;
                                res = scanf("%d/%d/%d", j, m, a);
                                while (res < 3 || *m < 1 || *m > 12 || *j < 1 || *j > 31 ){
                                    printf("\nErreur dans la saisie veuillez réessayer (sous forme j/m/a) : ");
                                    fflush(stdin);
                                    res = scanf("%d/%d/%d", j, m, a);
                                }
                                t_date* date_rdv = createDate(*j, *m, *a);
                                res = delRDVagenda(agenda, obj, date_rdv);
                                if (res) printf("\nRendez-vous supprime\n");
                                else printf("\nRendez-vous non trouve\n");


                            case 4: break;
                        }
                    }
                break;
            case 3:
                menu = 0;
                break;
        }

    }


    return 0;
}
