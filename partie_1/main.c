#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    t_d_list l = createList(3);
    t_d_cell *c = createCell(2, 1);
    insertHead(&l,c);
    c = createCell(1, 0);
    insertHead(&l,c);
    c = createCell(4, 2);
    insertCell(&l,c);
    c = createCell(3, 0);
    insertCell(&l,c);
    c = createCell(5, 0);
    insertCell(&l,c);
    c = createCell(6, 1);
    insertCell(&l,c);
    c = createCell(7, 0);
    insertCell(&l,c);
    printf("First display:\n");
    displayOneLevel(l, 0);
    printf("\n\nEntire list (without alignement) :\n");
    displayAllLevels(l);
    printf("\n\nEntire list (with alignement) :\n");
    betterDisplay(l);

    while(l.heads[0] != NULL){
        t_d_cell* temp = l.heads[0];
        l.heads[0] = l.heads[0]->next[0];
        free(temp);
    }
    return 0;
}
