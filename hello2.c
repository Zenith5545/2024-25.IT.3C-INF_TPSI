void LETTURA(char* reg, int indiceREG, int ValoreReg[8]) {
    
    for (int b = 0; b < 8; b++) {
        int r = indiceREG + b;
        
        if (reg[r] == '0' || reg[r] == '1') {
            ValoreReg[b] = reg[r] - '0';
        } else {
            ValoreReg[b] = 0; 
        }
    }
}










int main() {





//Dichiarazione variabili
    int lunghezza;
    int InRegA[4][8]; 
    int OutRegA[4][8];

    int InRegB[4][8]; 
    int OutRegB[4][8];


    lunghezza = strlen(numA);

    printf("Numero inserito: %s (numero di bit %d)\n", numA, lunghezza);
    if(lunghezza > 32){ 
        printf("valore A causa overflow\n");
        return 0;
    }



    lunghezza = strlen(numB);

    printf("Numero inserito: %s (numero di bit %d)\n", numB, lunghezza);
    if(lunghezza > 32){ 
        printf("valore B causa overflow\n");
        return 0;
    }





//Memorizzazione nel registro A e B
    for (int r = 0; r < 4; r++) { 
        LETTURA(numA, r * 8, InRegA[r]);

printf("Inizializzazione e Interazione con Registro %d\n", r);
        REGISTRO(InRegA[r][0], InRegA[r][1], InRegA[r][2], InRegA[r][3],
                 InRegA[r][4], InRegA[r][5], InRegA[r][6], InRegA[r][7],
                 &OutRegA[r][0], &OutRegA[r][1], &OutRegA[r][2], &OutRegA[r][3],
                 &OutRegA[r][4], &OutRegA[r][5], &OutRegA[r][6], &OutRegA[r][7]);


        LETTURA(numB, r * 8, InRegB[r]);

printf("Inizializzazione e Interazione con Registro %d\n", r);
        REGISTRO(InRegB[r][0], InRegB[r][1], InRegB[r][2], InRegB[r][3],
                 InRegB[r][4], InRegB[r][5], InRegB[r][6], InRegB[r][7],
                 &OutRegB[r][0], &OutRegB[r][1], &OutRegB[r][2], &OutRegB[r][3],
                 &OutRegB[r][4], &OutRegB[r][5], &OutRegB[r][6], &OutRegB[r][7]);

    }


//Visualizzazione risultato
    printf("Stato finale del registro A:\n");
    for (int r = 0; r < 4; r++){
        printf("Registro %d: ", r);
        for (int b = 0; b < 8; b++) {
            printf("%d", OutRegA[r][b]);
        }
        printf("\n");
    }

        printf("Stato finale del registro B:\n");
    for (int r = 0; r < 4; r++){
        printf("Registro %d: ", r);
        for (int b = 0; b < 8; b++) {
            printf("%d", OutRegB[r][b]);
        }
        printf("\n");
    }


    //sezione calcolo

ALU();
ALU();
ALU();
ALU();
ALU();
ALU();
ALU();
ALU();



    printf("\nProgramma terminato\n");
    return 0;
}