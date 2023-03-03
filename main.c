#include <stdio.h>
#include "chaines.h"

int main() {
    Maillon*liste=NULL;
    ajouterMaillon(&liste, 50, "Titi");
    freeMaillon(&liste);
}
