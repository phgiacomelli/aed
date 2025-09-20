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
                char *new = ReadStr(100);

                InsertStr(src, new);
                break;
            case 2:
                char *str = ReadStr(100);
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
    strcpy(new, strcat(new, " "));
    int newWordLength = (strlen(src) + strlen(new)) - 1;
    src = (char *)realloc(src, newWordLength * sizeof(char));
    strcpy(src, strcat(src, new));
}

void RemoveStr(char *src, char *str) {
    char *test;

    test = strtok(src, " ");
    printf("PRÉ: %s\n", src);

    while (test != NULL) {
        if (strcmp(test,str) == 0)
        {
            // int newWordLength = strlen(src)-strlen(str);
            // src = (char *)realloc(src, newWordLength * sizeof(char));
            printf("Igual");
        }
        //  else{
            strcpy(src,strcat(src, " de boa"));
            // strcpy(src,strcat(src,test));
            // printf("%s", src);
        // }

        // printf("%s\n", test);
        
        test = strtok(NULL, " ");
    }

    printf("PÓS: %s\n", src);

}