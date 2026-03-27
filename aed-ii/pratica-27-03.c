#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INSERTION_SIZE 10000

int copiesA, copiesB = 0;

typedef struct {
    int max_size;
    int size;
    int* values;
} VetorDinamico;

void inicializar_vetor(VetorDinamico* vec) {
    vec->max_size = 1;
    vec->size = 0;
    vec->values = (int*)malloc(1 * sizeof(int));  // tamanho inicial de 1 no vetor

    if (vec->values == NULL) {
        exit(1);
    }
}

void inserir(VetorDinamico* vec, int value, int strategy) {
    if (vec->size >= vec->max_size) {
        if (strategy == 1) // tamanho atual + 100 
            vec->max_size += 100;
        else  // dobro do tamanho atual
            vec->max_size *= 2;

        int* new_values = malloc(vec->max_size * sizeof(int));

        if (new_values == NULL) {
            exit(1);
        }

        for (int i = 0; i < vec->size; i++) {
            new_values[i] = vec->values[i];
            if (strategy == 1)
                copiesA++;
            else
                copiesB++;
        }
        free(vec->values);
        vec->values = new_values;
    }

    vec->values[vec->size++] = value;
}

int main() {
    VetorDinamico vecA;
    VetorDinamico vecB;

    inicializar_vetor(&vecA);
    inicializar_vetor(&vecB);

    printf("Inserindo 10.000 elementos nos vetores A e B utilizando diferentes estratégias...\n");
    for (int i = 0; i < INSERTION_SIZE; i++) {
        inserir(&vecA, i, 1);  // estrategia +100
        inserir(&vecB, i, 2);  // estrategia *2
    }

    printf("Número de cópias na estratégia A: %d\n", copiesA);
    printf("Número de cópias na estratégia B: %d\n", copiesB);
    return 0;
}