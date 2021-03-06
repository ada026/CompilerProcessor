#include <stdlib.h>
#include <stdio.h>
// Groupe 21
typedef struct Element Element;
struct Element
{
    int adr;
    char* type;
    char* id;
    int depth;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
    int adr;
};

Pile * initPile(){
  Pile* pile = malloc(sizeof(Pile));
  pile->premier = NULL;
  pile->adr = 0;
  return pile;
}

int empiler(Pile* pile, char* type, char* id, int depth){

  Element* element = malloc(sizeof(Element));

  element->adr = pile->adr;
  pile->adr++;
  element->type = type;
  element->id = id;
  element->depth = depth;
  element->suivant = pile->premier;
  pile->premier = element;
  return element->adr;
}

void depiler(Pile* pile){

  Element* thingToDepile = pile->premier;

  if(pile != NULL || pile->premier != NULL){
    pile->premier = pile->premier->suivant;
    free(thingToDepile);
  }

}
