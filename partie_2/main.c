#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"

int main(){


     /* //DEMONSTRATION PARTIE 1 TETE

    t_d_list l = createList(3);
    t_d_cell *c = createCell(1, 0);
    insertHead(&l, c);
    c = createCell(2, 2);
    insertHead(&l, c);
    c = createCell(3, 1);
    insertHead(&l, c);

    printf("\nInsertion des cellules 1, 2 et 3 (niveaux 0, 2 et 1) :\n");
    displayAllLevels(l);


    //FIN PARTIE 1 TETE */


     /* //DEMONSTRATION PARTIE 1 INSERTION

    t_d_list l2 = createList(3);
    t_d_cell *c = createCell(1, 0);
    insertCell(&l2, c);

    printf("\nCellule 1 inseree, niveau 0 :\n");
    displayAllLevels(l2);
    c = createCell(2, 2);
    insertCell(&l2, c);
    printf("\nCellule 2 inseree, niveau 2 :\n");
    displayAllLevels(l2);
    c = createCell(3, 1);
    insertCell(&l2, c);
    printf("\nCellule 3 inseree, niveau 1 :\n");
    displayAllLevels(l2);
    c = createCell(4, 1);
    insertCell(&l2, c);
    c = createCell(5, 2);
    insertCell(&l2, c);
    c = createCell(6, 0);
    insertCell(&l2, c);
    c = createCell(7, 1);
    insertCell(&l2, c);

    printf("\nAprès ajout de 4 autres cellules, liste complete :\n");
    displayAllLevels(l2);

    printf("\nNiveau 2 : \n");
    displayOneLevel(l2, 2);

    printf("\nAffichage aligne : \n");
    betterDisplay(l2);

    //FIN PARTIE 1 INSERTION */


    /* //DEMONSTRATION PARTIE 2 RECHERCHE

    int n = 0;
    printf("Entrez le nombre de niveaux de la liste (min 1):");
    char s[100];
    while(n < 1){
        scanf("%s", s);

        // Conversion de la chaine de caractères en entier
        n = strtol(s, NULL,10);
    }

    t_d_list l = createList(n);

    int p = 1;
    for(int i = 0; i < n; i++){
        p*=2;
    }
    p--;
    printf("Nombre de cellules : %d\n", p);

    int cell_val[p];
    for(int i = 0; i < p; i++){
        cell_val[i] = i+1;
    }
    printf("\nTableau des valeurs : \n");
    for(int i = 0; i < p; i++){
        printf("%d ", cell_val[i]);
    }
    printf("\n");

    int* level_tab = createComparativeTab(p);
    printf("\nTableau des niveaux : \n");
    for(int i = 0; i < p; i++){
        printf("%d ", level_tab[i]);
    }
    printf("\n");

    // Creation des cellules et insertion dans la liste
    t_d_cell *c;
    for (int i = 0; i < p; i++){
        c = createCell(cell_val[i], level_tab[i]);
        insertCell(&l, c);
    }
    printf("\nListe complete :\n");
    betterDisplay(l);

    printf("\nRecherche de la cellule 1 : \n");
    printf("Recherche classique : Present ? \n");
    if(classic_search(l, 1) == 1) printf("Oui\n");
    else printf("Non\n");
    printf("Recherche par niveau : Present ? \n");
    if(level_search(l, 1) == 1) printf("Oui\n");
    else printf("Non\n");

    printf("\nRecherche de la cellule 9 : \n");
    printf("Recherche classique : Present ? \n");
    if(classic_search(l, 9) == 1) printf("Oui\n");
    else printf("Non\n");
    printf("Recherche par niveau : Present ? \n");
    if(level_search(l, 9) == 1) printf("Oui\n");
    else printf("Non\n");


    printf("\nRecherche de la cellule 2 : \n");
    classic_search(l, 2);

    //FIN PARTIE 2 RECHERCHE */


      //DEMONSTRATION COMPLEXITE

    /*int n = 0;
    printf("Entrez le niveau de la liste :");
    char s[100];
    while(n < 1){
        scanf("%s", s);

        // Conversion de la chaine de caractères en entier
        n = strtol(s, NULL,10);
    }

    t_d_list l = createList(n);

    int p = 1;

    // Mesure du temps + ouverture du fichier de log
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;

    srand(time(NULL));
    for(int k = 1; k <= n; k++){

        // Multiplication par 2 du nombre de cellules à chaque niveau
        p*=2;
        int cell_val[p-1];
        for(int i = 1; i <= p-1; i++){
            cell_val[i-1] = i;
        }
        int* level_tab = createComparativeTab(p);

        // Creation des nouvelles cellules et insertion dans la liste
        t_d_cell *c;
        for (int i = p/2-1; i < p-1; i++){
            c = createCell(cell_val[i], level_tab[i]);
            insertCell(&l, c);
        }

        // Recherche de nb_max éléments aléatoires dans la liste
        long nb_max = 100000;
        printf("Level : %d\n", k);

        // Recherche classique
        startTimer();
        for(int j = 0; j < nb_max; j++) classic_search(l, rand() % p);
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString(); // fonction du module timer

        // Recherche par niveau
        startTimer();
        for(int j = 0; j  < nb_max; j++) level_search(l, rand() % p);
        stopTimer();
        displayTime();
        time_all_levels = getTimeAsString();

        // Ecriture dans le fichier de log
        fprintf(log_file,format,k,time_lvl0, time_all_levels);
        free(level_tab);
        level_tab = NULL;

    }

    // Fermeture du fichier de log
    fclose(log_file);

    //FIN PARTIE COMPLEXITE */
    return 0;

}
