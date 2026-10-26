#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* tarea_hilo(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo;

    if (pthread_create(&hilo, NULL, tarea_hilo, NULL) != 0) {
        perror("Error");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Principal %d\n", i);
    }

    pthread_join(hilo, NULL);

    printf("\n finalizado\n");
    return 0;
}
