#include "hash_map.h"

int main() {
    HashMap map;
    init(&map, 10);

    set(&map, "Alice", 25);
    set(&map, "Bob", 30);

    printf("DISPLAY TEST\n");
    display(&map);

    printf("GET TEST\n");
    printf("Alice's age: %d\n", get(&map, "Alice"));

    printf("POP TEST\n");
    pop(&map, "Alice");
    display(&map);

    destroy(&map);

    return 0;
}
