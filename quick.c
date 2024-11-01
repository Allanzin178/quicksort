#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funções
void troca(int *a, int *b);
int particao(int V[], int min, int max);
void Quicksort(int V[], int min, int max);

int main(){
    int teste[] = {0, 5, 10, 2, 6, 8, 7};
    int n = sizeof(teste) / sizeof(teste[0]); // O tamanho da array é tamanho do int (4) * numero de elementos, logo invertemos para saber o tamanho



    Quicksort(teste, 0, n - 1);

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", teste[i]);
    }
}

// Chamadas
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int V[], int min, int max){
    int media = (min + max) / 2;
    int pivot = V[media];
    printf("\npivot = %d\n", V[media]);
    int i = min; // i: índice para percorrer subvetor da esquerda
    int j = max; // j: índice para percorrer subvetor da direita

    for (int k = min; k <= max; k++) {
        if(k < max){
            printf("%d ", V[k]);
        }else{
            printf("%d\n", V[k]);
        }
    }

    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
    while(i <= j) {
        while(V[i] < pivot){ 
            printf("i = %d\n", V[i]);
            i++;
        } // fica preso ate encontrar alguem maior que o pivot (deveria estar na direita)
        while(V[j] > pivot) {
            printf("j = %d\n", V[j]);
            j--;
        } // fica preso ate encontrar alguem menor que o pivot (deveria estar na esquerda)
        printf("i = %d e j = %d\n", V[i], V[j]);
        
        if(i <= j){
            printf("Trocando!\n");
            troca(&V[i], &V[j]);
            i++;
            j--;
        }
        printf("I = %d\n", i);
        printf("J = %d\n\n", j);
        for (int k = min; k <= max; k++) {
            if(k < max){
                printf("%d ", V[k]);
            }else{
                printf("%d\n", V[k]);
            }
            
        }
        
    }
    
    printf("%d\n", i);
    return(i);
}

void Quicksort(int V[], int min, int max){
    if (min < max){
        int p = particao(V, min, max);

        printf("\t MIN = %d, MAX = %d", min, max);
        Quicksort(V, min, p-1);
        Quicksort(V, p, max);
    }
}