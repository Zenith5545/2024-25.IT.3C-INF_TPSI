#include <stdio.h>

// Funzione per simulare la porta NOT
int NOT(int a) {
    // Il valore di ritorno della funzione
    return 1 - a;
}

// Funzione per simulare la porta AND
int AND(int a, int B) {
    // Il valore di ritorno della funzione
    // TODO aggiungere l'espressione matematica per soddisfare la porta AND
    return a * B;
}   // 1337 = LEET

// Funzione per simulare la porta OR
int OR(int a, int B) {
    // Il valore di ritorno della funzione
    // TODO aggiungere l'espressione matematica per soddisfare la porta OR
    return (a + B) - (a * B);
}

int main() {
    // Dichiara una variabile
    int A, B;

    // Mostra un messaggio sul terminale che l'utente può leggere
    printf("Inserisci il valore di A (0 o 1):\n");
    // Attende che l'utente inserisca un valore e prema invio
    scanf("%d", &A);
    // Mostra un messaggio sul terminale che l'utente può leggere
    printf("Hai inserito il valore A: %d\n", A);

    // Mostra un messaggio sul terminale che l'utente può leggere
    printf("Inserisci il valore di B (0 o 1):\n");
    // Attende che l'utente inserisca un valore e prema invio
    scanf("%d", &B);
    // Mostra un messaggio sul terminale che l'utente può leggere
    printf("Hai inserito il valore B: %d\n", B);

    if (A != 0 && A != 1 && B != 0 && B != 1) {
        printf("I valori inseriti non sono 1 o 0\n");
    } else {
        // Procediamo con l'esecuzione solo se il numero è 1 o 0
        printf("I valori inseriti sono 1 o 0\n");

        // Esempio di porta NOT
        printf("Il valore di A viene trasformato da una porta NOT\n");
        int notA = NOT(A);
        printf("Il valore di uscita della porta NOT è: %d\n", notA);

        // Esempio di porta AND
        printf("I valori di A e B vengono trasformati da una porta AND\n");
        int andAB = AND(A, B);
        printf("Il valore di uscita della porta AND è: %d\n", andAB);

        // Esempio di porta OR
        printf("I valori di A e B vengono trasformati da una porta OR\n");
        int orAB = OR(A, B);
        printf("Il valore di uscita della porta OR è: %d\n", orAB);
    }

    printf("\n\n");
}

//esercizio 3 - calcolo esp. NOT(AND(A, OR(A, B)))

int r = 1 - (A * (A + B - A * B));
printf("il valore è: %d\n", r)



//esercizio 4 - creazione labirinto logico

int main2() {
   
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




 int AND(int A, int B) {
    return A * B
 }

 int NOT(int C) {
    return 1 - C;
 }

 int OR(int D, int F) {
    return (D + E) - (D * E);
 }

 int NOT2(int F) { 
    return 1 - F;
 }





 int OR2(int AND, int AND){
    return (AND + AND) - (AND * AND);
 }

 int AND2(int OR; int NOT2){
    return OR * NOT2
 }



 int OR3(int OR2, int NOT){
    return (OR2 + NOT) - (OR2 * NOT);
 }

 int AND3(int NOT, int AND2){
    return NOT * AND2
 }




 int AND4(int OR3, int AND3){
    return OR3 * AND3
 }


 int NOT3(int AND4){
    return 1 - AND4
 }

 printf("il valore è in uscita dal labirinto è: %d\n", NOT3)

}