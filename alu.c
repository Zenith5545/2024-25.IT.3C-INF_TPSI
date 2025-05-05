#include <stdio.h>
#include <math.h>




// Funzione per simulare la porta NOT
int NOT(int a) {
    // Il valore di ritorno della funzione
    return 1 - a;
}
// Funzione per simulare la porta AND
int AND(int a, int B) {
 
    
    return a * B;
}  
// Funzione per simulare la porta OR
int OR(int a, int B) {
 
    return (a + B) - (a * B);
}
// Funzine per simulare la porta EX-OR
int EXOR(int a, int b){

return (a+b)-((2*a)*b);
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