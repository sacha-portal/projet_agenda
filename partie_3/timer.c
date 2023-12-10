#include <stdio.h>
#include <malloc.h>
#include "timer.h"

// Commencer le timer
void startTimer(){
    _timer._start = clock();
}

// Arrêter le timer et calculer la durée en millisecondes
void stopTimer(){
    _timer._end = clock();
    // calculer la durée en millisecondes par rapport à CLOCKS_PER_SEC
    _timer._msecs = (1000.0 * (double) (_timer._end - _timer._start)) / CLOCKS_PER_SEC;
}

// Affichage de l'heure
void displayTime(){
    // affiche l'heure en utilisant getTimeAsString()
    printf("%s\n", getTimeAsString());
    return;
}

// renvoie une chaîne de caractères contenant le temps en secondes et en millisecondes
char *getTimeAsString(){
    // format : nombres entiers, avec 3 chiffres, remplis avec 0
    // exemple : 001, 123

    // utiliser sprintf pour écrire la chaîne dans un buffer alloué dynamiquement
    char *buffer = (char *)malloc(10*sizeof(char));
    sprintf(buffer, "[%g] %03d,%03d", _timer._msecs, (int)(_timer._msecs)/1000, (int)(_timer._msecs)%1000);

    // retourner le buffer
    return buffer;
}