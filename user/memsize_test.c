#include "user.h"

int main(int argc, char *argv[]) {
    printf("memsize: %d\n", memsize());
    void *memory = malloc(20000);
    printf("memsize: %d\n", memsize());
    free(memory);
    printf("memsize: %d\n", memsize());
    return 0;
}