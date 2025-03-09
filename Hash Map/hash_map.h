#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
   char* key;
   int value;
   struct Node* next;
} Node;

typedef struct HashMap {
   Node** table;
   size_t capacity;
   size_t size;
} HashMap;

void init(HashMap* map, size_t capacity);
void destroy(HashMap* map);
size_t hash(const char* key, size_t capacity);
void set(HashMap* map, const char* key, int value);
int get(HashMap* map, const char* key);
void pop(HashMap* map, const char* key);
void display(HashMap* map);

#endif
