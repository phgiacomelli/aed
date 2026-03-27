#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu(void);
char *ReadStr(int length);
void InsertStr(char *src, char *new);
void RemoveStr(char *src, char *str);

int main() {
    int op;

    char *src;
    src = (char *)malloc(sizeof(char));

    for (;;) {
        op = Menu();

        switch (op) {
            case 1:
                char *new = ReadStr(50);
                InsertStr(src, new);
                break;
            case 2:
                char *str = ReadStr(20);
                RemoveStr(src, str);
                break;
            case 3:
                printf("\n\tString: ");
                printf("%s\n", src);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}

int Menu(void) {
    int op;
    do {
        printf("\n\nMenu:\n");
        printf("1. Adicionar nome.\n");
        printf("2. Remover nome.\n");
        printf("3. Listar.\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
    } while (op < 1 || op > 4);

    return op;
}

char *ReadStr(int length) {
    char *new;
    new = (char *)malloc(length * sizeof(char));

    printf("\n\tDigite: ");
    scanf(" %[^\n]", new);
    return new;
}

void InsertStr(char *src, char *new) {
    strcat(new, " ");
    int newWordLength = strlen(src) + strlen(new); 
    src = (char *)realloc(src, newWordLength * sizeof(char));
    strcat(src, new);
    free(new);
}

void RemoveStr(char *src, char *str) {
    char *token, *new, *aux;
    new = (char *)malloc(sizeof(char));
    aux = (char *)malloc(sizeof(char));

    token = strtok(src, " ");    
    while (token != NULL) {
        if (strcmp(token, str) != 0) {
            new = (char *)realloc(new, (strlen(new)+strlen(token)) * sizeof(char));
            aux = (char *)realloc(aux, (strlen(token)+1) * sizeof(char));
            strcpy(aux, token);
            strcat(aux, " ");
            strcat(new, aux);
        }        
        token = strtok(NULL, " ");
    }
    int newLen = strlen(new);
    src = (char *)realloc(src, newLen * sizeof(char));
    strcpy(src,new);
    free(aux);
    free(token);
    free(new);
}