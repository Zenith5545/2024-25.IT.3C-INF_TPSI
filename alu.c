#include <stdio.h>
#include <math.h>

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




int main()
{

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
                    } 
                

                    // abbiamo a e b -> input convertiti in binario

            }

            bin: // binario
            if(s2b == 1){

                int k, a, b, i1, i2, u;

                i1 = 1;
                i2 = 1;
                u = 0;

                //Richiesta all'utente di inserire il primo numero
                while(i1==1){
                printf("Inserisci il primo numero che sia in numeri binari\n");
                scanf("%d", &a);

                    if(a == 1 || a == 0){i1--;}

                    else(printf("valore sbagliato ritenta\n") + u++);
                    if(u==5) goto end;
                } // valore 1


                //Richiesta all'utente di inserire il secondo numero
                while(i2==1){
                printf("Inserisci il secondo numero che sia in numeri binari\n");
                scanf("%d", &b);

                    if(b == 1 || b == 0){i2--;}

                    else(printf("valore sbagliato ritenta\n") + u++);
                    if(u==5) goto end;
                } // valore 2

                  // a e b -> 2 input binari
            }

}



fli: // zona dedicata a inserimento file
if(s1f == 1){


}














end: // fine programma



}