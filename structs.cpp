#include <iostream>
#define NUM_CUATES 2

using namespace std;
// declaración
struct  Direccion {
       char calle[100];
        int numero;
       char colonia[50];
       char municipio[50];
       char estado[50];
};
void leeDireccion(Direccion &dir);
void imprimeDireccion(Direccion dir);

main () {
   Direccion miDir={"",0,"","",""};
   Direccion misCuatesDir[NUM_CUATES]=
             {{"5 mayo",0,"","",""},{"gobernadores",0}};
   cout << "Escribe tu dirección :"<<endl;

   leeDireccion(miDir);
   
   cout << "Escribe la dirección de tus cuates:"<<endl;
   int i=NUM_CUATES;
   while (i) {
      leeDireccion(misCuatesDir[i-1]);
      i--;
   }
   cout <<endl<< " Las direcciones fueron: "<<endl;
   cout <<" Tu dirección : "<<endl;
   imprimeDireccion(miDir);
   cout <<" Tus cuates : "<<endl;
   for (i=0; i < NUM_CUATES; i++) {
      imprimeDireccion(misCuatesDir[i]);
   }
   system("pause");
}

void leeDireccion(Direccion &dir) {
   fflush(stdin);
   cout <<endl<< "Calle: ";
   cin.getline(dir.calle, sizeof(dir.calle)-1);
   fflush(stdin);
   cout <<"Número: ";
   cin>>dir.numero;
   fflush(stdin);
   cout <<"Colonia: ";
   cin.getline(dir.colonia, sizeof(dir.colonia)-1);
   fflush(stdin);
   cout <<"Municipio: ";
   cin.getline(dir.municipio, sizeof(dir.municipio)-1);
   fflush(stdin);
   cout <<"Estado: ";
   cin.getline(dir.estado, sizeof(dir.estado)-1);   
   fflush(stdin);
}

void imprimeDireccion(Direccion dir) {
   cout <<endl<< "Calle: "<<dir.calle<<endl;
   cout <<"Número: "<<dir.numero<<endl;
   cout <<"Colonia: "<<dir.colonia<<endl;
   cout <<"Municipio: "<<dir.municipio<<endl;
   cout <<"Estado: "<<dir.estado<<endl;
}

