// Paulo Henrique Anesi Giacomelli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node;

void reorderList(struct ListNode* head) {
    int len = 0;
    Node* curr = head;

    // descobrir o tamanho
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }

    // se tamanho for menor que 3, nao mudamos, pois nao tem elementos suficientes 
    if (len < 3)
        return;

    Node* first = head;
    Node* preLast = NULL;
    Node* last = NULL;
    curr = head;
    while (curr != NULL) {

        // seta penultimo e ultimo
        if (curr->next != NULL && curr->next->next == NULL) {
            preLast = curr;
            last = curr->next;
        }

        //se penultimo e ultimo estao setados, podemos fazer as trocas nos ponteiros
        if (preLast != NULL && last != NULL) {

            //Fizemos as trocas nos ponteiros
            preLast->next = last->next;
            last->next = head->next;
            head->next = last;
            // chamada recursiva passando o 3o elemento como cabeça
            reorderList(last->next);
            return;
        } else {
            curr = curr->next;
        }

       
    }
}

int main() {
    Node n1 = {1, NULL};
    Node n2 = {2, NULL};
    Node n3 = {3, NULL};
    Node n4 = {4, NULL};
    Node n5 = {5, NULL};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    reorderList(&n1);

    return 0;
}