#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_SIZE (sizeof(char) * 50)
#define BUFFER_INITIAL_SIZE (sizeof(int) + sizeof(size_t) + STR_MAX_SIZE * 2)
// choice, peoplesSize, nameTemp, emailTemp
// int, int, char[50], char[50],

void menu(void* pBuffer);
bool getPersonByEmail(void* pBuffer);
void addPerson(void** pBuffer);
void clearStdinBuffer(void);

int main() {
    void* pBuffer = malloc(BUFFER_INITIAL_SIZE);

    if (!pBuffer) {
        printf("Memória insuficiente!\n");
        return 1;
    }

    // Zerar as variaveis
    int* choice = (int*)pBuffer;
    size_t* peopleSize = (size_t*)((char*)pBuffer + sizeof(int));
    char* nameTemp = (char*)((char*)peopleSize + sizeof(size_t));
    char* emailTemp = (char*)(nameTemp + STR_MAX_SIZE);

    *choice = 0, *peopleSize = 0;
    nameTemp[0] = emailTemp[0] = '\0';

    while (1) {
        if (*choice == 5)
            break;

        menu(pBuffer);

        choice = (int*)pBuffer;
        switch (*choice) {
            case 1:
                addPerson(&pBuffer);
                break;
            case 2:
                printf("Remover Pessoa.\n");
                break;
            case 3:
                printf("Buscar Pessoa.\n");
                break;
            case 4:
                printf("Listar todos.\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
        }
    }
    int *age = (int *)((char *)pBuffer+BUFFER_INITIAL_SIZE);
    printf("%d", *age);

    free(pBuffer);
    return 0;
}

void menu(void* pBuffer) {
    int* choicePtr = (int*)pBuffer;

    do {
        printf("\n");
        printf("╔════════════════════════╗\n");
        printf("║     Agenda pBuffer     ║\n");
        printf("╠════════════════════════╣\n");
        printf("║ 1 ▸ Adicionar Pessoa   ║\n");
        printf("║ 2 ▸ Remover Pessoa     ║\n");
        printf("║ 3 ▸ Buscar Pessoa      ║\n");
        printf("║ 4 ▸ Listar Todas       ║\n");
        printf("║ 5 ▸ Sair               ║\n");
        printf("╚════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", choicePtr);
    } while (*choicePtr < 1 || *choicePtr > 5);
    getchar();
}

void clearStdinBuffer() {
    while (1) {
        switch (getchar()) {
            case '\n':
            case EOF:
                return;
        }
    }
}

bool getPersonByEmail(void* pBuffer) {
    size_t* peopleSize = (size_t*)((char*)pBuffer + sizeof(int));
    // printf("", *peopleSize);

    if (!*peopleSize) {
        return false;
    }

    char* emailTemp = (char*)(pBuffer + BUFFER_INITIAL_SIZE - STR_MAX_SIZE);

    printf("%s", emailTemp);

    return true;
}

void addPerson(void** pBuffer) {
    char* nameTemp = (char*)((char*)*pBuffer + sizeof(int) + sizeof(size_t));
    char* emailTemp = (char*)(nameTemp + STR_MAX_SIZE);

    printf("Nome: ");
    scanf(" %49[^\n]", nameTemp);
    clearStdinBuffer();

    printf("Email: ");
    scanf(" %49[^\n]", emailTemp);
    clearStdinBuffer();

    if (getPersonByEmail(*pBuffer)) {
        printf("Já existe uma pessoa com este email!");
        return;
    }

    size_t* peopleSize = (size_t*)((char*)*pBuffer + sizeof(int));
    // pBuffer = tamanho_fixo + tamanho_pessoas + 1 int + (nome+\0) + (email+\0)
    *pBuffer = realloc(*pBuffer, BUFFER_INITIAL_SIZE + *peopleSize + sizeof(int) + ((strlen(nameTemp) + strlen(emailTemp) + 2) * sizeof(char)));

    if (!*pBuffer) {
        printf("Memória insuficiente!");
        return;
    }

    peopleSize = (size_t*)((char*)*pBuffer + sizeof(int));
    nameTemp = (char*)((char*)*pBuffer + sizeof(int) + sizeof(size_t));
    emailTemp = (char*)(nameTemp + STR_MAX_SIZE);

    int* age = (int*)((char*)*pBuffer + BUFFER_INITIAL_SIZE + *peopleSize);
    char* name = (char*)((char*)age + sizeof(int));
    char* email = (char*)(name + ((strlen(nameTemp) + 1) * sizeof(char)));

    strcpy(name, nameTemp);
    strcpy(email, emailTemp);

    printf("Idade: ");
    scanf("%d", age);
    clearStdinBuffer();

    *peopleSize += sizeof(int) + (strlen(nameTemp) + 1) + (strlen(emailTemp) + 1);
    nameTemp[0] = '\0';
    emailTemp[0] = '\0';
}