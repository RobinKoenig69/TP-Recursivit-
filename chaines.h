//
// Created by DB9ga on 02/03/2023.
//
#include <string.h>
#include <stdlib.h>

#ifndef LISTES_CHAINEES_CHAINES_H
#define LISTES_CHAINEES_CHAINES_H


typedef struct M{
    int nb;
    char nom[100];
    struct M*next;
}Maillon;

void ajouterMaillon(Maillon** m, int n, char*s){
    if(*m == NULL){
        *m=malloc(1*sizeof (Maillon));
        (*m)->nb =n;
        strcpy((*m)->nom, s);
        (*m)->next = NULL;
    }
    else if (n<(*m)->nb){
        Maillon*tmp=malloc(sizeof(Maillon));
        tmp->nb = n;
        strcpy(tmp->nom, s);
        tmp->next = *m;
        *m = tmp;
    }
    else {
        ajouterMaillon(&(*m)->next, n, s);
    }
};
void freeMaillon(Maillon**m){       //attention cette méthode ne marche que si on a plus de 1 valeur
    if((*m)->next !=0){
        freeMaillon(m);
        free(m);
    }
}
/*void afficherRecurs(Maillon*m){
    if (m!=NULL){
        printf("%s : %d \n", m->nom, m->nb);
        afficherRecurs(m->next);
    }

    void AfficherIt(Maillon*p){
        while (p !=NULL){
            printf("%d ...", p->nb);
            p=p->next;
        }
        //ou//
        for (;p !=NULL; p=p->next){
            printf("%d ...", p->nb)
        }
    }
};*/

#endif //LISTES_CHAINEES_CHAINES_H
