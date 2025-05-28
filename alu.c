#include <stdio.h>
#include <math.h>
#include <string.h>

// Funzioni logiche
int NOT(int a) { return 1 - a; }
int AND(int a, int B) { return a * B; }
int OR(int a, int B) { return (a + B) - (a * B); }
int EXOR(int a, int b){ return (a + b) - ((2 * a) * b); }
int NOR(int a, int b) { return NOT(OR(a, b)); }
int NAND(int a, int b) { return NOT(AND(a, b)); }

// Funzioni per 3 o più variabili
int OR3(int a, int b, int c){return OR(OR(a, b), c);}
int AND3(int a, int b, int c){return AND(AND(a, b), c);}
int NOR3(int a, int b, int c){return NOT(OR(OR(a, b), c));}
int NAND3(int a, int b, int c){return NOT(AND(AND(a, b), c));}
int AND1(int a){return a;}
int AND4(int a, int b, int c, int d){return AND(AND(AND(a, b), c), d); }
int NAND4(int a, int b, int c, int d){return NOT(AND(AND(AND(a, b), c), d)); }
int NOR4(int a, int b, int c, int d){return NOT(OR(OR(OR(a, b), c), d));}
int AND5(int a, int b, int c, int d, int e){return AND(AND(AND(AND(a, b), c), d), e);}
int NAND5(int a, int b, int c, int d, int e){return NOT(AND(AND(AND(AND(a, b), c), d), e));}


// ALU
void ALU(
    int a0, int b0, int a1, int b1, int a2, int b2, int a3, int b3,
    int z0, int z1, int z2, int z3, int m1, int Cn,
    int* f0, int* f1, int* f2, int* f3, int* A, int* B, int* Cn4
)  {

    // 1 sezione
    int p0 = NOR3(AND(NOT(b0), z1),AND(z0, b0), AND1(a0));
    int p1 = NOR(AND3(a0, b0, z3), AND3(a0, z2, NOT(b0)));

    int p2 = NOR3(AND(NOT(b1), z1),AND(z0, b1), AND1(a1));
    int p3 = NOR(AND3(a1, b1, z3), AND3(a1, z2, NOT(b1)));

    int p4 = NOR3(AND(NOT(b2), z1),AND(z0, b2), AND1(a2));
    int p5 = NOT(OR(AND3(a2, b2, z3), AND3(a2, z2, NOT(b2))));

    int p6 = NOR3(AND(NOT(b3), z1),AND(z0, b3), AND1(a3));
    int p7 = NOR(AND3(a3, b3, z3), AND3(a3, z2, NOT(b3)));


    // 2 sezione
    int M = NOT(m1);

    *f0 = EXOR(EXOR(p0, p1), NAND(Cn, M));

    int f1a = NOR(AND3(p2, M, Cn), AND(p1, M));
    *f1 = EXOR(EXOR(p2, p3), f1a);

    int f2a = NOR3(AND4(Cn, p2, p4, M), AND3(p4, p1, M), AND(M, p3));
    *f2 = EXOR(EXOR(p4, p5), f2a);

    int f3d = AND5(Cn, p1, p3, p5, M);
    int f3c = AND4(p3, p5, p1, M);
    int f3b = AND3(p2, M, p5);
    int f3a = AND(p4, M);
    *f3 = EXOR(EXOR(p6, p7), NOR4(f3d, f3c, f3b, f3a));

    *A = AND(*f0, *f1);
    *B = AND(*f3, *f2);

    // 3 sezione
    int GY = NOR4(AND1(p6), AND(p7, p4), AND3(p7, p5, p2), AND4(p7, p5, p3, Cn));

    *Cn4 = OR(NOT(GY), NOT(NAND5(p7, p5, p3, p1, Cn)));
}


void REG(
    int f0_in, int f1_in, int f2_in, int f3_in, int f4_in, int f5_in, int f6_in, int f7_in,
    int* Q0, int* Q1, int* Q2, int* Q3, int* Q4, int* Q5, int* Q6, int* Q7
){
    int Q0n, Q1n, Q2n, Q3n, Q4n, Q5n, Q6n, Q7n; // Qn = NOT(Q)
    int R;

    // Inizializzazione con i valori passati
    R = 0;
    *Q0 = AND(f0_in, NOT(R));
    Q0n = NOT(*Q0);

    *Q1 = AND(f1_in, NOT(R));
    Q1n = NOT(*Q1);

    *Q2 = AND(f2_in, NOT(R));
    Q2n = NOT(*Q2);

    *Q3 = AND(f3_in, NOT(R));
    Q3n = NOT(*Q3);

    *Q4 = AND(f4_in, NOT(R));
    Q4n = NOT(*Q4);

    *Q5 = AND(f5_in, NOT(R));
    Q5n = NOT(*Q5);

    *Q6 = AND(f6_in, NOT(R));
    Q6n = NOT(*Q6);

    *Q7 = AND(f7_in, NOT(R));
    Q7n = NOT(*Q7);

    printf("Dato memorizzato: Q0 = %d\n", *Q0);
    printf("Dato memorizzato: Q1 = %d\n", *Q1);
    printf("Dato memorizzato: Q2 = %d\n", *Q2);
    printf("Dato memorizzato: Q3 = %d\n", *Q3);
    printf("Dato memorizzato: Q4 = %d\n", *Q4);
    printf("Dato memorizzato: Q5 = %d\n", *Q5);
    printf("Dato memorizzato: Q6 = %d\n", *Q6);
    printf("Dato memorizzato: Q7 = %d\n", *Q7);

    // Loop per operazioni successive
    while (1) {
        int scelta;
        printf("\nCosa vuoi fare ora?\n");
        printf("1 - Reset\n");
        printf("2 - Sovrascrivi con nuovo SET\n");
        printf("3 - Termina\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        if (scelta == 1) {
            // RESET
            R = 1;
            *Q0 = AND(0, NOT(R)); Q0n = NOT(*Q0);
            *Q1 = AND(0, NOT(R)); Q1n = NOT(*Q1);
            *Q2 = AND(0, NOT(R)); Q2n = NOT(*Q2);
            *Q3 = AND(0, NOT(R)); Q3n = NOT(*Q3);
            *Q4 = AND(0, NOT(R)); Q4n = NOT(*Q4);
            *Q5 = AND(0, NOT(R)); Q5n = NOT(*Q5);
            *Q6 = AND(0, NOT(R)); Q6n = NOT(*Q6);
            *Q7 = AND(0, NOT(R)); Q7n = NOT(*Q7);

            printf("Reset effettuato. Q0 = %d\n", *Q0);
            printf("Reset effettuato. Q1 = %d\n", *Q1);
            printf("Reset effettuato. Q2 = %d\n", *Q2);
            printf("Reset effettuato. Q3 = %d\n", *Q3);
            printf("Reset effettuato. Q4 = %d\n", *Q4);
            printf("Reset effettuato. Q5 = %d\n", *Q5);
            printf("Reset effettuato. Q6 = %d\n", *Q6);
            printf("Reset effettuato. Q7 = %d\n", *Q7);

        } else if (scelta == 2) {
            // Nuovo SET
            int new_f_val;
            printf("Inserisci il nuovo valore SET (0 o 1) per tutti i registri: ");
            scanf("%d", &new_f_val);

            R = 0; // Per un SET, R deve essere 0
            *Q0 = AND(new_f_val, NOT(R)); Q0n = NOT(*Q0);
            *Q1 = AND(new_f_val, NOT(R)); Q1n = NOT(*Q1);
            *Q2 = AND(new_f_val, NOT(R)); Q2n = NOT(*Q2);
            *Q3 = AND(new_f_val, NOT(R)); Q3n = NOT(*Q3);
            *Q4 = AND(new_f_val, NOT(R)); Q4n = NOT(*Q4);
            *Q5 = AND(new_f_val, NOT(R)); Q5n = NOT(*Q5);
            *Q6 = AND(new_f_val, NOT(R)); Q6n = NOT(*Q6);
            *Q7 = AND(new_f_val, NOT(R)); Q7n = NOT(*Q7);

            printf("Dato memorizzato: Q0 = %d\n", *Q0);
            printf("Dato memorizzato: Q1 = %d\n", *Q1);
            printf("Dato memorizzato: Q2 = %d\n", *Q2);
            printf("Dato memorizzato: Q3 = %d\n", *Q3);
            printf("Dato memorizzato: Q4 = %d\n", *Q4);
            printf("Dato memorizzato: Q5 = %d\n", *Q5);
            printf("Dato memorizzato: Q6 = %d\n", *Q6);
            printf("Dato memorizzato: Q7 = %d\n", *Q7);

        } else if (scelta == 3) {
            printf("Terminazione del processo.\n");
            break;
        } else {
            printf("Scelta non valida. Riprova.\n");
        }
    }
}


// decimale -> binario
void invertitore(char* Abin){
    int lunghezza = strlen(Abin);
    int i, j;
    char rif;
    for (i = 0, j = lunghezza - 1; i < j; i++, j--) {
        rif = Abin[i];
        Abin[i] = Abin[j];
        Abin[j] = rif;
    }
}

void BIN(int A, char* Abin){
    // Gestione del caso 0
    if (A == 0) {
        strcpy(Abin, "0");
        return;
    }

    int i = 0;
    int Arif = A;

    // Estrae i bit e li inserisce nel buffer (in ordine inverso)
    while (Arif > 0){
        if(Arif % 2 == 0){Abin[i] = '0' ;}
        else{Abin[i]= '1' ;}

        Arif /= 2;
        i++;
    }

    Abin[i] = '\0';

    // Inverte la stringa per avere l'ordine corretto dei bit
    invertitore(Abin);
}


void DIV(
    char* num_str,
    int* d0,  int* d1,  int* d2,  int* d3,
    int* d4,  int* d5,  int* d6,  int* d7,
    int* d8,  int* d9,  int* d10, int* d11,
    int* d12, int* d13, int* d14, int* d15,
    int* d16, int* d17, int* d18, int* d19,
    int* d20, int* d21, int* d22, int* d23,
    int* d24, int* d25, int* d26, int* d27,
    int* d28, int* d29, int* d30, int* d31
){
    int cifre[32]; // Max 32 bit
    int r0 = 0;

    // Inizializza tutti i valori a 0 prima di assegnare per quando il numero è minore di 32 bit
    for(int i = 0; i < 32; i++){
        cifre[i] = 0;
    }

    // Convertiamo la stringa in array di cifre intere
    while (num_str[r0] != '\0' && r0 < 32) { 
        cifre[r0] = num_str[r0] - '0';  
        r0++;
    }

    printf("\nIl numero di bit è %d\n", r0);

    // Assegna i valori ai puntatori. Se la stringa è più corta, i valori rimangono 0 (per via dell'inizializzazione)
    *d0 = (r0 > 0) ? cifre[0] : 0;
    *d1 = (r0 > 1) ? cifre[1] : 0;
    *d2 = (r0 > 2) ? cifre[2] : 0;
    *d3 = (r0 > 3) ? cifre[3] : 0;
    printf("Le prime quattro cifre del numero sono: %d, %d, %d, %d\n", *d0, *d1, *d2, *d3);

    *d4 = (r0 > 4) ? cifre[4] : 0;
    *d5 = (r0 > 5) ? cifre[5] : 0;
    *d6 = (r0 > 6) ? cifre[6] : 0;
    *d7 = (r0 > 7) ? cifre[7] : 0;
    printf("Le cifre del primo riporto sono: %d, %d, %d, %d\n", *d4, *d5, *d6, *d7);

    *d8 = (r0 > 8) ? cifre[8] : 0;
    *d9 = (r0 > 9) ? cifre[9] : 0;
    *d10 = (r0 > 10) ? cifre[10] : 0;
    *d11 = (r0 > 11) ? cifre[11] : 0;
    printf("Le cifre del secondo riporto sono: %d, %d, %d, %d\n", *d8, *d9, *d10, *d11);

    *d12 = (r0 > 12) ? cifre[12] : 0;
    *d13 = (r0 > 13) ? cifre[13] : 0;
    *d14 = (r0 > 14) ? cifre[14] : 0;
    *d15 = (r0 > 15) ? cifre[15] : 0;
    printf("Le cifre del terzo riporto sono: %d, %d, %d, %d\n", *d12, *d13, *d14, *d15);

    *d16 = (r0 > 16) ? cifre[16] : 0;
    *d17 = (r0 > 17) ? cifre[17] : 0;
    *d18 = (r0 > 18) ? cifre[18] : 0;
    *d19 = (r0 > 19) ? cifre[19] : 0;
    printf("Le cifre del quarto riporto sono: %d, %d, %d, %d\n", *d16, *d17, *d18, *d19);

    *d20 = (r0 > 20) ? cifre[20] : 0;
    *d21 = (r0 > 21) ? cifre[21] : 0;
    *d22 = (r0 > 22) ? cifre[22] : 0;
    *d23 = (r0 > 23) ? cifre[23] : 0;
    printf("Le cifre del quinto riporto sono: %d, %d, %d, %d\n", *d20, *d21, *d22, *d23);

    *d24 = (r0 > 24) ? cifre[24] : 0;
    *d25 = (r0 > 25) ? cifre[25] : 0;
    *d26 = (r0 > 26) ? cifre[26] : 0;
    *d27 = (r0 > 27) ? cifre[27] : 0;
    printf("Le cifre del sesto riporto sono: %d, %d, %d, %d\n", *d24, *d25, *d26, *d27);

    *d28 = (r0 > 28) ? cifre[28] : 0;
    *d29 = (r0 > 29) ? cifre[29] : 0;
    *d30 = (r0 > 30) ? cifre[30] : 0;
    *d31 = (r0 > 31) ? cifre[31] : 0;
    printf("Le cifre del settimo riporto sono: %d, %d, %d, %d\n", *d28, *d29, *d30, *d31);
    
    printf("\nfine divisione di questi valori\n");
}


int main(){
    // sezione input
    int s1, s1t = 0, s1f = 0; // per le scelte utente
    int s2, s2b = 0, s2d = 0;

    //input x registri
    char numA[32 + 1];  // +1 per il terminatore di stringa '\0'
    char numB[32 + 1];

    // dichiarazione per registro di A
    int a0, a1, a2, a3;
    int a4, a5, a6, a7;
    int a8, a9, a10, a11;
    int a12, a13, a14, a15;
    int a16, a17, a18, a19;
    int a20, a21, a22, a23;
    int a24, a25, a26, a27;
    int a28, a29, a30, a31;

    // dichiarazione per registro di B
    int b0, b1, b2, b3;
    int b4, b5, b6, b7;
    int b8, b9, b10, b11;
    int b12, b13, b14, b15;
    int b16, b17, b18, b19;
    int b20, b21, b22, b23;
    int b24, b25, b26, b27;
    int b28, b29, b30, b31;


    // zona scelta utente
    while(1){
        printf("Inserimento valori tramite: 1 = manualmente da terminale, 2 = tramite file.\n");
        printf("Scelta: ");
        scanf("%d",&s1);

        if(s1 == 1){
            s1t=1;
            break;
        } else if(s1 == 2){
            s1f=1;
            printf("Funzione 'tramite file' non implementata. Scegli 'manualmente da terminale'.\n");
            
            continue; // Torna all'inizio del loop per chiedere di nuovo in quanto funzione non implementata
        } else {
            printf("Valore sbagliato, ritenta.\n");
        }
    }

    // zona dedicata all'inserimento da terminale
    if(s1t == 1){ // Usare '==' per il confronto
        while(1){
            printf("Tipologia valori: 1 = decimale, 2 = binario.\n");
            printf("Scelta: ");
            scanf("%d",&s2);

            if(s2 == 1){
                s2d = 1;
                break;
            } else if(s2 == 2){
                s2b = 1;
                break;
            } else {
                printf("\nValore sbagliato, ritenta.\n");
            }
        }

        // zona decimale
        if(s2d == 1){
            int A, B;
            char BinA[32 + 1];
            char BinB[32 + 1];

            printf("\nInserisci 2 numeri decimali:\n");
            scanf("%d", &A);
            scanf("%d", &B);

            // Chiama la funzione per convertire i valori
            BIN(A, BinA);
            BIN(B, BinB);

            printf("\nIl numero %d in binario: %s\n", A, BinA);
            
            printf("\nIl numero %d in binario: %s\n", B, BinB);

            // Copia le stringhe binarie in numA e numB
            strncpy(numA, BinA, sizeof(numA) - 1);
            numA[sizeof(numA) - 1] = '\0';
            strncpy(numB, BinB, sizeof(numB) - 1);
            numB[sizeof(numB) - 1] = '\0';
        }

        // zona binaria
        if(s2b == 1){ 
            printf("Inserisci il primo numero (max 32 bit): ");
            scanf("%s", numA);
            printf("Inserisci il secondo numero (max 32 bit): ");
            scanf("%s", numB);
        }

        // Controllo 32 bit
        if ((strlen(numA) > 32) || (strlen(numB) > 32)) {
            printf("Errore: numero inserito supera il limite di 32 bit, overflow.\n");
            return 1; // Termina il programma con un errore se maggiori di 32 bit
        }
    }


    // Chiamata a DIV per dividere i bit nei registri
    DIV(
        numA, // divide i bit di A
        &a0, &a1, &a2, &a3,
        &a4, &a5, &a6, &a7,
        &a8, &a9, &a10, &a11,
        &a12, &a13, &a14, &a15,
        &a16, &a17, &a18, &a19,
        &a20, &a21, &a22, &a23,
        &a24, &a25, &a26, &a27,
        &a28, &a29, &a30, &a31
    );

    DIV(
        numB, // divide i bit di B
        &b0, &b1, &b2, &b3,
        &b4, &b5, &b6, &b7,
        &b8, &b9, &b10, &b11,
        &b12, &b13, &b14, &b15,
        &b16, &b17, &b18, &b19,
        &b20, &b21, &b22, &b23,
        &b24, &b25, &b26, &b27,
        &b28, &b29, &b30, &b31
    );

    //zona calcolo e registri
    
    REG();

    printf("\nFine programma.\n");

    return 0;
}