#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* lista = (List *) malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}

void * firstList(List * list) {
  if(list->head){
    list->current = list->head;
  }
  else return NULL;
  return (list->head->data);
}

void * nextList(List * list) {
  if(!list->current) 
    return NULL; //ver si existe
  if(!list->current->next) 
    return NULL; // ver si existe
  list->current = list->current->next;
  return (list->current->data);
}

void * lastList(List * list) {
  if(!list->tail) 
    return NULL;
  if(!list->current) 
    return NULL;
  list->current = list->tail;
  return (list->tail->data);
}

void * prevList(List * list) {
  if(!list->current)
    return NULL;
  if(!list->current->prev) 
    return NULL;
  list->current = list->current->prev;
  return (list->current->data);
  return NULL;
}

void pushFront(List * list, void * data) {
  Node *n = createNode(data);
  n->next = list->head;
  if(list->head){
    list->head->prev = n;
  }
  list->head = n;
  list->tail = n;
  n->prev = NULL;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * nodo = createNode(data);
  nodo->next = list->current;
  nodo->prev = list->head;
  if(list->current){
    list->current->next = nodo;
  }
  list->tail->prev = nodo
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(list->current->prev){
    list->current->prev->next = list->current->next;
  }
  else list->head = list->current->next;
  if(list->current->next){
    list->current->next->prev = list->current->prev;
  }
  return (list->current->data);
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}