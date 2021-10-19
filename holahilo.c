#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10
int saldo;

void *printHola(void *arg){
    int saldoLocal = saldo;
    saldoLocal += 100;
    saldo = saldoLocal;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("El valor del saldo es %d", saldo);

    pthread_exit(NULL);
}