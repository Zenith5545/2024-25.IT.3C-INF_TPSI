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





trm: // zona dedicata al terminale
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



            }

            bin: // binario
            if(s2b == 1){


    
            }

}



fli: // zona dedicata a inserimento file
if(s1f == 1){


}














end:



}