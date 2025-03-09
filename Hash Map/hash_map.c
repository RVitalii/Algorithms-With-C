#include "hash_map.h"

void init(HashMap* map, size_t capacity){
   map->capacity = capacity;
   map->size = 0;
   map->table = (Node**)malloc(capacity * sizeof(Node*));
   if (!map->table) {
      fprintf(stderr, "Memory allocation failed");
      exit(1);
   }
   for (size_t i=0; i<capacity; i++) {
      map->table[i] = NULL; 
   }
}

void destroy(HashMap* map){
   for (size_t i=0; i <map->capacity; i++){
      Node* current = map->table[i];
      while (current) {
         Node* tmp = current;
         current = current->next;
         free(tmp->key);
         free(tmp);
      }
   }
   free(map->table);
}

size_t hash(const char* key, size_t capacity) {
   size_t hash_value = 0;
   while (*key) {
      hash_value = (hash_value * 31) + *key++;
   }
   return hash_value % capacity;
}

void set(HashMap* map, const char* key, int value) {
   size_t index = hash(key, map->capacity);
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->key = strdup(key);
   newNode->value = value;
   newNode->next = map->table[index];
   map->table[index] = newNode;
   map->size++;
}

int get(HashMap* map, const char* key) {
   size_t index = hash(key, map->capacity);
   Node* node = map->table[index];
   while (node) {
      if (strcmp(node->key, key) == 0) {
         return node->value;
      }
      node = node->next;
   }
   return -1;
}

void pop(HashMap* map, const char* key){
   size_t index = hash(key, map->capacity);
   Node* currentNode = map->table[index];
   Node* previousNode = NULL;
   while (currentNode) {
      if (strcmp(currentNode->key, key) == 0) {
         if(previousNode){
            previousNode->next = currentNode->next;
         } else {
            map->table[index] = currentNode->next;
         }
         free(currentNode->key);
         free(currentNode);
         map->size--;
         return;
      }
   }
}

void display(HashMap* map){
   printf("[");
   size_t count = 0;
   for (size_t i=0; i<map->capacity; i++){
      Node* currentNode = map->table[i];
      while(currentNode){
         if (++count == map->size) {
            printf("(%s, %d)", currentNode->key, currentNode->value);
         } else {
            printf("(%s, %d), ", currentNode->key, currentNode->value);
         }
         currentNode = currentNode->next;
      }
   }
   printf("]\n");
}
