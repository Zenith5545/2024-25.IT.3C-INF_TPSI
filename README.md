# 2024-25.IT.3C-INF_TPSI;

#include <stdio.h>

int main() {
   
    int A, B, C, D, E, F;

printf("Inserisci il valore di A (0 o 1):\n");
scanf("%d", &A);                                // and
printf("Inserisci il valore di B (0 o 1):\n");
scanf("%d", &B);

printf("Inserisci il valore di C (0 o 1):\n");
scanf("%d", &C);                               // not

printf("Inserisci il valore di D (0 o 1):\n");
scanf("%d", &D);    
                                               // or
printf("Inserisci il valore di E (0 o 1):\n");
scanf("%d", &E);

printf("Inserisci il valore di F (0 o 1):\n");
scanf("%d", &F);                               //not         




int AND(int A; int B){
    return A * B
}

int NOT(int C) {
    return 1 - C;
}

int OR(int D, int F) {
    return D + E;
}

int NOT2(int F) {
    return 1 - F;
}







int OR2(int AND, int AND) {
    return AND + AND;



}