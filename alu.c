#include <stdio.h>
#include <math.h>
#include <string.h>

int NOT(int a) {
       return 1 - a;
}

int AND(int a, int B) {
    return a * B;
}  

int OR(int a, int B) {
 
    return (a + B) - (a * B);
}

int EXOR(int a, int b){
return (a+b)-((2*a)*b);
}

int NOR (int a, int b){
return NOT(OR(a, b));
}

int NAND (int a, int b){
    return NOT(AND(a, b));
}

int OR3(int a, int b, int c){
    return OR(OR(a, b), c);
}

int AND3(int a, int b, int c){
    return AND(AND(a, b), c);
}

int NOR3(int a, int b, int c){
    return NOT(OR(OR(a, b), c));
}

int NAND3(int a, int b, int c){
    return NOT(AND(AND(a, b), c));
}

int AND1(int a){
return a;
}

int AND4(int a, int b, int c, int d){
return AND(AND(AND(a, b), c), d); 
}

int NAND4(int a, int b, int c, int d){
    return NOT(AND(AND(AND(a, b), c), d)); 
}

int NOR4(int a, int b, int c, int d){
    return NOT(OR(OR(OR(a, b), c), d));
}

int AND5(int a, int b, int c, int d, int e){
  return AND(AND(AND(AND(a, b), c), d), e);
}

int NAND5(int a, int b, int c, int d, int e){
  return NOT(AND(AND(AND(AND(a, b), c), d), e));
}

//                input                                                         selettori                   carry in            output                    ??        carry out          ???
int ALU(int a0,int b0,int a1,int b1,int a2,int b2,int a3,int b3,      int z0,int z1,int z2,int z3,int m1,    int Cn,   int f0,int f1,int f2,int f3,  int A, int B,   int Cn4,     int PX,int GY){
 
 // 1 sezione
 
 
    

  
  int p0 = NOR3(AND(NOT(b0), z1),AND(z0, b0), AND1(a0));
  int p1 = NOR(AND3(a0, b0, z3), AND3(a0, z2, NOT(b0)));
  
  int p2 = NOR3(AND(NOT(b1), z1),AND(z0, b1), AND1(a1));
  int p3 = NOR(AND3(a1, b1, z3), AND3(a1, z2, NOT(b1)));
  
  int p4 = NOR3(AND(NOT(b2), z1),AND(z0, b2), AND1(a2));
  int p5 = NOR(AND3(a2, b2, z3), AND3(a2, z2, NOT(b2)));
  
  int p6 = NOR3(AND(NOT(b3), z1),AND(z0, b3), AND1(a3));
  int p7 = NOR(AND3(a3, b3, z3), AND3(a3, z2, NOT(b3)));
  
  
 // 2 sezione
  


 int M = NOT(m1);
  
 f0 = EXOR(EXOR(p0, p1), NAND(Cn, M));                                  // output 1
 
     int f1a = NOR(AND3(p2, M, Cn), AND(p1, M));                        
 f1 = EXOR(EXOR(p2, p3), f1a);                                          // output 2
 
     int f2a = NOR3(AND4(Cn, p2, p4, M), AND3(p4, p1, M), AND(M, p3));      
 f2 = EXOR(EXOR(p4, p5), f2a);                                          // output 3
 
     int f3d = AND5(Cn, p1, p3, p5, M);
     int f3c = AND4(p3, p5, p1, M);
     int f3b = AND3(p2, M, p5);
     int f3a = AND(p4, M);
 f3 = EXOR(EXOR(p6, p7), NOR4(f3d, f3c, f3b, f3a));                     // output 4
 
 A = AND(f0, f1);                                                       
                                                                         // output A = B
 B = AND(f3, f2);
 
 // 3 sezione
 

 PX = NAND4(p7, p5, p3, p1);                                              // output P(negato) or X
 
 
 GY = NOR4(AND1(p6), AND(p7, p4), AND3(p7, p5, p2), AND4(p7, p5, p3, Cn));// output G(negato) or Y 
 

 Cn4 = OR(NOT(GY), NOT(NAND5(p7, p5, p3, p1, Cn)));                       // output Cn+4 or Cn+4(negato)
 
}

int CHECK(int a, int u)
{
           
int i1 = 1;

//Richiesta all'utente di inserire il primo numero
while(i1==1){
     printf("inserisci il valore, deve essere 1 o 0\n");
scanf("%d", &a);
if(a == 1 || a == 0){i1--;}
else( printf("valore sbagliato\n") + u++);
if(u==5) break;
}
return a;
return u;
}




int main(){

    int s1, s1t, s1f,     s2, s2b, s2d,     u = 0;

    rt1: // scelta tra terminale e file
    printf("inserimento valori tramite: 1 manualmente da terminale, 2 tramite file.\n");
    scanf("%d",&s1);

    if(s1 == 1){goto trm;
    s1t=1;}

    else if(s1 == 2){goto fli;
    s1f=1;}

    else{printf("valore sbagliato ritenta\n") + u++;
    goto rt1;};
    if(u==5){goto end;}





    trm: // zona dedicata all'inserimento da terminale
    if(s1t = 1){

    rt2:
    printf("tipologia valori: 1 = decimale, 2 binario.\n");
    scanf("%d",&s2);

    if(s2 == 1){goto dec;
    s2d = 1;
    }

    else if(s2 == 2){goto bin;
    s2b = 1;
    } 


     else{printf("valore sbagliato ritenta\n") + u++;
     goto rt2;};
     if(u==5){goto end;} 




            dec: // decimale
            if(s2d == 1){
            
                
                     int tipoval,a,b,numbin1,numbin2,pes1,pes2,a2,b2;
           
                    printf("inserire i 2 valori\n");
                    
                    scanf("%d\n",&a2); // 1 valore

                    a=0, pes1=1;
                    while(a2 != 0){    
                        numbin1 = a2 % 2;
                        a += numbin1*pes1;
                        pes1 *= 10;
                        a2 /= 2;
                    }
                    
                    scanf("%d",&b2); // 2 valore

                    b=0, pes2=1;

                    while(b2 > 0){    
                        numbin2 = b2 % 2;
                        b += numbin2*pes2;
                        pes2 *= 10;
                        b2 /= 2;
                    }  // abbiamo a e b -> input convertiti in binario   
                  


            }

            bin: // binario
            if(s2b == 1){


    char numeroStrA[32 + 1];  // +1 per il terminatore di stringa '\0'
    
    int cifre[32], r0 = 0, a0, a1, a2, a3;
   
    int rip1[32], r1 = 0, a01, a11, a21, a31;
    int rip2[32], r2 = 0, a02, a12, a22, a32;
    int rip3[32], r3 = 0, a03, a13, a23, a33;
    int rip4[32], r4 = 0, a04, a14, a24, a34;
    int rip5[32], r5 = 0, a05, a15, a25, a35;
    int rip6[32], r6 = 0, a06, a16, a26, a36;
    int rip7[32], r7 = 0, a07, a17, a27, a37;
 
    
    
    printf("Inserisci un numero (max 32 bit): ");
    scanf("%s", numeroStrA);

    // Controlliamo che il numero non superi il limite
    if (strlen(numeroStrA) > 32) {
        printf("Errore: il numero inserito supera il limite di 32 bit, overflow.\n");
        return 1;
    }

    // Convertiamo la stringa in array di cifre
    while (numeroStrA[r0] != '\0') {
        cifre[r0] = numeroStrA[r0] - '0';  // Convertiamo il carattere in cifra intera
        r0++;
    }
   
    printf("il numero di bit è %d\n", r0);
     
     
    // Verifichiamo che ci siano almeno quattro cifre
    if (r0 >= 4) { // input
        a0 = cifre[0];
        a1 = cifre[1];
        a2 = cifre[2];
        a3 = cifre[3];

        printf("Le prime quattro cifre del numero sono: %d, %d, %d, %d\n", a0, a1, a2, a3);

        
        if (r0 > 4) { // 1 riporto
            for (int j = 4; j < r0; j++) {
                rip1[r1] = cifre[j];
                r1++;
            }

            if(r1 > 4){
                a01 = rip1[0];
                a11 = rip1[1];
                a21 = rip1[2];
                a31 = rip1[3];
                
        printf("Le cifre del primo riporto sono: %d, %d, %d, %d\n", a01, a11, a21, a31);  
        
          
        if (r1 > 4) { // 2 riporto
            for (int j = 4; j < r1; j++) {
                rip2[r2] = rip1[j];
                r2++;        
            }
            
            if(r2 > 4){
                a02 = rip2[0];
                a12 = rip2[1];
                a22 = rip2[2];
                a32 = rip2[3]; 
                
        printf("Le cifre del secondo riporto sono: %d, %d, %d, %d\n", a02, a12, a22, a32);
        
        
        if (r2 > 4) { // 3 riporto
            for (int j = 4; j < r2; j++) {
                rip3[r3] = rip2[j];
                r3++;        
            }
            
            if(r3 > 4){
                a03 = rip3[0];
                a13 = rip3[1];
                a23 = rip3[2];
                a33 = rip3[3];        
        
        printf("Le cifre del terzo riporto sono: %d, %d, %d, %d\n", a03, a13, a23, a33);
        



        if (r3 > 4) { // 4 riporto
            for (int j = 4; j < r3; j++) {
                rip4[r4] = rip3[j];
                r4++;        
            }
            
            if(r4 > 4){
                a04 = rip4[0];
                a14 = rip4[1];
                a24 = rip4[2];
                a34 = rip4[3];        
        
        printf("Le cifre del quarto riporto sono: %d, %d, %d, %d\n", a04, a14, a24, a34);
        
        
        
        if (r4 > 4) { // 5 riporto
            for (int j = 4; j < r4; j++) {
                rip5[r5] = rip4[j];
                r5++;        
            }
            
            if(r5 > 4){
                a05 = rip5[0];
                a15 = rip5[1];
                a25 = rip5[2];
                a35 = rip5[3];        
        
        printf("Le cifre del quinto riporto sono: %d, %d, %d, %d\n", a05, a15, a25, a35);
        
        
        
        if (r5 > 4) { // 6 riporto
            for (int j = 4; j < r5; j++) {
                rip6[r6] = rip5[j];
                r6++;        
            }
            
            if(r6 > 4){
                a06 = rip6[0];
                a16 = rip6[1];
                a26 = rip6[2];
                a36 = rip6[3];        
        
        printf("Le cifre del sesto riporto sono: %d, %d, %d, %d\n", a06, a16, a26, a36);        
        
        
        
        if (r6 > 4) { // 6 riporto
            for (int j = 4; j < r6; j++) {
                rip7[r7] = rip6[j];
                r7++;        
            }
            
            if(r7 == 4){
                a07 = rip7[0];
                a17 = rip7[1];
                a27 = rip7[2];
                a37 = rip7[3];        
        
        printf("Le cifre del settimo riporto sono: %d, %d, %d, %d\n", a07, a17, a27, a37);
        
        
            }}
            }}
            }}
            }}
            }}
            }}
            }}
        
        }
       
    
    else {
        printf("Il numero inserito non ha almeno quattro cifre.\n");
    }


                  // a e b -> 2 input binari
            }

    }



    fli: // zona dedicata a inserimento file
    if(s1f == 1){
   

  

    }


    end: // fine programma

    printf("fine programma\n");



    return 0;
}


