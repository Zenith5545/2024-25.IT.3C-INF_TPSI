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

// Funzine per simulare la porta EX-OR
int EXOR(int a, int b){
    // Il valore di ritorno della funzione
    // TODO aggiungere l'espressione matematica per soddisfare la porta AND
return (a+b)-((2*a)*b);
}


    int main() {
        FILE *file;
        int num[10]; // Buffer per leggere 10 interi
        size_t result;
        int i;
        
        // Aprire il file in modalità di lettura
        file = fopen("in.txt", "r");


        if (file == NULL) {
            perror("Errore nell'apertura del file: file non trovato");
            return 1;
        }
    
        // Leggere 10 interi dal file
        result = fread(num, sizeof(int), 10, file);


        if (result != 10) {
            perror("Errore nella lettura dal file: file non leggibile");
            fclose(file);
            return 1;
        }
    
        // Stampare i numeri letti
        printf("Numeri letti dal file:\n");
        for (i = 0; i < 10; i++) {
            printf("%d\n", num[i]);
        }
    
        // Chiudere il file
        fclose(file);
        return 0;
    }


