#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_SIZE (sizeof(char) * 50)
#define BUFFER_INITIAL_SIZE (sizeof(int) + sizeof(size_t) + STR_MAX_SIZE * 2)
// choice, peoplesSize, nameTemp, emailTemp
// int, int, char[50], char[50],

void menu(void* pBuffer);
void* getPersonByEmail(void* pBuffer);
void clearStdinBuffer(void);
void addPerson(void** pBuffer);
void printPerson(void* pBuffer);
void listPeople(void* pBuffer);
void deletePerson(void** pBuffer);

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
        choice = (int*)pBuffer;

        if (*choice == 5)
            break;

        menu(pBuffer);

        switch (*choice) {
            case 1:
                printf("\n---[ 1. ADICIONAR PESSOA ]---\n");
                addPerson(&pBuffer);
                break;
            case 2:
                printf("\n---[ 2. REMOVER PESSOA ]---\n");
                deletePerson(&pBuffer);
                break;
            case 3:
                printf("\n---[ 3. BUSCAR PESSOA POR EMAIL ]---\n");
                printPerson(pBuffer);
                break;
            case 4:
                printf("\n---[ 4. LISTAR TODAS AS PESSOAS ]---\n");
                listPeople(pBuffer);
                break;
            case 5:
                printf("\nSaindo da agenda... Até logo!\n\n");
                break;
        }
    }

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

void* getPersonByEmail(void* pBuffer) {
    size_t* peopleSize = (size_t*)((char*)pBuffer + sizeof(int));

    if (!*peopleSize)
        return NULL;

    char* emailTemp = (char*)(pBuffer + BUFFER_INITIAL_SIZE - STR_MAX_SIZE);

    void* currentPtr = (char*)pBuffer + BUFFER_INITIAL_SIZE;
    void* endPtr = (char*)currentPtr + *peopleSize;

    while (currentPtr < endPtr) {
        char* currentName = (char*)((char*)currentPtr + sizeof(int));
        char* currentEmail = (char*)(currentName + strlen(currentName) + 1);

        if (strcmp(currentEmail, emailTemp) == 0)
            return currentPtr;

        currentPtr = (void*)((char*)currentEmail + strlen(currentEmail) + 1);
    }

    return NULL;
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

    if (getPersonByEmail(*pBuffer) != NULL) {
        printf("Já existe uma pessoa com este email!");
        nameTemp[0] = '\0';
        emailTemp[0] = '\0';
        return;
    }

    size_t* peopleSize = (size_t*)((char*)*pBuffer + sizeof(int));
    // pBuffer = tamanho_fixo + tamanho_pessoas + 1 int + (nome+\0) + (email+\0)
    *pBuffer = realloc(*pBuffer, BUFFER_INITIAL_SIZE + *peopleSize + sizeof(int) + (strlen(nameTemp) + 1) + (strlen(emailTemp) + 1));

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

void printPerson(void* pBuffer) {
    size_t* peopleSize = (size_t*)((char*)pBuffer + sizeof(int));
    char* nameTemp = (char*)((char*)peopleSize + sizeof(size_t));
    char* emailTemp = (char*)(nameTemp + STR_MAX_SIZE);
    printf("\nEmail: ");
    scanf(" %49[^\n]", emailTemp);
    clearStdinBuffer();

    void* personPtr = getPersonByEmail(pBuffer);

    if (personPtr == NULL) {
        printf("\nPessoa não encontrada!\n");
        return;
    }

    int* age = (int*)personPtr;
    char* name = (char*)((char*)personPtr + sizeof(int));
    char* email = (char*)(name + strlen(name) + 1);

    printf("\nNome: %s\n", name);
    printf("Email: %s\n", email);
    printf("Idade: %d\n", *age);

    emailTemp[0] = '\0';
}

void listPeople(void* pBuffer) {
    size_t* peopleSize = (size_t*)((char*)pBuffer + sizeof(int));

    if (!*peopleSize) {
        printf("\nNão há nenhuma pessoa na lista!\n");
        return;
    }

    void* currentPtr = (char*)pBuffer + BUFFER_INITIAL_SIZE;
    void* endPtr = (char*)currentPtr + *peopleSize;

    while (currentPtr < endPtr) {
        int* age = (int*)currentPtr;
        char* name = (char*)((char*)currentPtr + sizeof(int));
        char* email = (char*)(name + strlen(name) + 1);

        printf("\nNome: %s\n", name);
        printf("Email: %s\n", email);
        printf("Idade: %d\n", *age);

        currentPtr = (void*)((char*)email + strlen(email) + 1);
    }
}

void deletePerson(void** pBuffer) {
    size_t* peopleSize = (size_t*)((char*)*pBuffer + sizeof(int));
    char* nameTemp = (char*)((char*)peopleSize + sizeof(size_t));
    char* emailTemp = (char*)(nameTemp + STR_MAX_SIZE);

    printf("\nEmail: ");
    scanf(" %49[^\n]", emailTemp);
    clearStdinBuffer();

    void* personPtr = getPersonByEmail(*pBuffer);

    if (personPtr == NULL) {
        printf("\nPessoa não encontrada!\n");
        emailTemp[0] = '\0';
        return;
    }
    char* name = (char*)((char*)personPtr + sizeof(int));
    char* email = (char*)(name + strlen(name) + 1);

    // ptr para o inicio dos dados da proxima pessoa
    void* nextPersonPtr = (void*)((char*)email + strlen(email) + 1);

    // final da lista de pessoas
    void* endPtr = (void*)((char*)*pBuffer + BUFFER_INITIAL_SIZE + *peopleSize);

    // verificamos, para nao mover "pra frente"
    if (nextPersonPtr < endPtr) {
        memmove(personPtr, nextPersonPtr, (char*)endPtr - (char*)nextPersonPtr);
    }
    //memmove vai mover x bytes (3o param.) da memoria, a partir do 2o elemento, para a posicao do primeiro elemento
    // ou seja, pega do nextPersonPtr até o final da lista, e move tudo para tras, ate chegar na posicao de personPtr
    // o que equivale a trazer os dados para tras, sobrescrevendo a pessoa que deveria ser removida
 
    *peopleSize -= (sizeof(int) + (strlen(name) + 1) + (strlen(email) + 1));
    emailTemp[0] = '\0';

    *pBuffer = realloc(*pBuffer, BUFFER_INITIAL_SIZE + *peopleSize);
    if (!*pBuffer) {
        printf("Memória insuficiente!");
        return;
    }
    printf("\nPessoa removida!\n");
}