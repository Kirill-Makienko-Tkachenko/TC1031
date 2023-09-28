#include <iostream>
#include <string.h>

using namespace std;

void apuntadores2() {


    char cadena1[] = "Hola ";
    char cadena2[10];
    char *Pcad1 = cadena1, *Pcad2 = cadena2;

    for (int i = 0; (*(Pcad2++)=*(Pcad1++)); i++);  // Es lo mismo que: for (int i = 0; (*(Pcad2++)=*(Pcad1++)) != '\0'; i++);
        ;

    cout << "Cadena 1: " << Pcad1 << endl;
    cout << "Cadena 2: " << Pcad2 << endl;

}


void ejercicio(char *cadena){

    bool esPalindromo = true;

    char *pcadena = cadena;
    int tamano = 0;
    while(*(pcadena++)) tamano++;
    pcadena = cadena;
    for(int i=0; i<tamano/2; i++){
        if(*(pcadena+i) != *(pcadena+tamano-i-1)) esPalindromo = false;
    }

    if (esPalindromo){
        cout << "La cadena '" << cadena << "' es palindromo" << endl;
    } else {
        cout << "La cadena '" << cadena << "' no es palindromo" << endl;
    }
}


void todoMinusculas(char *cad) {

    char *pCad = cad;

    for (int i = 0; i<strlen(cad); i++){

        *(pCad+i) = tolower(*(pCad+i));

    }
    cout << cad << endl;


}

void alternado (char *cad) {

    char *pCad = cad;

    for (int i = 0; i<strlen(cad); i++){

        *(pCad+i) = tolower(*(pCad+i));

    }

    for (int i = 0; i<strlen(cad); i= i + 2){

        *(pCad+i) = toupper(*(pCad+i));
        

    }

    cout << cad << endl;


}



int main() {
    /*int varX, varY;
    int *ptrX, *ptrY;

    ptrX=&varX;
    ptrY=&varY;

    cout<<"La localidad de memoria de varX es "<<&varX;
    cout<<"La localidad de memoria de varY es "<<&varY;

    cout<<"El valor de ptrX es "<<ptrX;
    cout<<"El valor de ptrY es "<<ptrX; */


    //char cad[10] = "rotor";

    

    //ejercicio(cad);


    char cad2[10] = "SDVKJBJB";

    todoMinusculas(cad2);

    alternado(cad2);

	return 0;

}