#ifndef PROJET_AGENDA_S3_CELL_H
#define PROJET_AGENDA_S3_CELL_H

typedef struct s_d_cell{
    int value;
    int level; // Niveau de la cellule (0 étant le plus bas)
    struct s_d_cell **next;
} t_d_cell;

t_d_cell* createCell(int val, int nb_level);

#endif