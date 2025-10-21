#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void* pBuffer);

int main() {
    void* pBuffer = NULL;

    pBuffer = malloc(2 * sizeof(int));

    if (!pBuffer) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    menu(pBuffer);

    printf("Escolha; %d", *(int*)pBuffer);
    return 0;
}

void menu(void* pBuffer) {
    int* choicePtr = (int*)pBuffer;

    do {
        printf("\n");
        printf("╔══════════════════════════════════╗\n");
        printf("║          Agenda pBuffer          ║\n");
        printf("╠══════════════════════════════════╣\n");
        printf("║ 1 ▸ Adicionar Pessoa             ║\n");
        printf("║ 2 ▸ Remover Pessoa               ║\n");
        printf("║ 3 ▸ Buscar Pessoa                ║\n");
        printf("║ 4 ▸ Listar Todas                 ║\n");
        printf("║ 5 ▸ Sair                         ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", choicePtr);
    } while (*choicePtr < 1 || *choicePtr > 5);
    getchar();
}