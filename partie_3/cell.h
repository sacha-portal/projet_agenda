#ifndef PROJET_AGENDA_S3_CELL_H
#define PROJET_AGENDA_S3_CELL_H

typedef enum { CONTACT, RDV, AGENDA } CELL_TYPE;

typedef struct s_d_cell{
    CELL_TYPE type;
    void* value;
    int level;
    struct s_d_cell **next;
} t_d_cell;

void* createCellValue(CELL_TYPE type);
t_d_cell* createCell(void* val, int nb_level);

#endif