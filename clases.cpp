#include <iostream>
#include <iomanip>

using namespace std;

class  Tiempo {
   public:    
       Tiempo();
       void estableceHora(int, int, int);
       void imprimeHora24();
       void imprimeHoraEstandar();
       void imprimeHoraEstandar2();
   private:
       int hora; 
       int minuto;
       int segundo;
};

Tiempo::Tiempo() {
     hora=minuto = segundo=0;
}


void Tiempo::estableceHora(int h,  int m, int s) {         
      hora = (h >= 0 && h < 24) ? h : 0;
      minuto = (m >= 0 && m < 60) ? m : 0;
      segundo = (s >= 0 && s < 60) ? s : 0;
}

void Tiempo:: imprimeHora24() {         
      cout << setfill('0') << setw(2) << hora << ":" 
               << setw(2) << minuto <<":"
                    << setw(2) << segundo << "\n" ;
}

void Tiempo::imprimeHoraEstandar() {
      cout <<  ( ((hora%12)==0)?12:(hora%12) ) << ":"  
               << setw(2) << minuto <<":" 
                    << setw(2) << segundo << (hora < 12 ? " AM\n\n" : " PM\n\n") ;
  
}

void Tiempo::imprimeHoraEstandar2(){
        cout  << ((hora == 0 || hora == 12) ? 12 : hora % 12) <<":"
                    << setfill('0') << setw(2) << minuto << ":"
                        << setw(2) << segundo << (hora < 12 ? " AM\n\n" : " PM\n\n");
}

main  ( ) {
	Tiempo t;
	cout << "La hora universal inicial es:";
	t.imprimeHora24(); // 00:00:00
	t.estableceHora(0,30,0);
	t.imprimeHora24(); // 02:30:00
    t.imprimeHoraEstandar();
    t.imprimeHoraEstandar2();    
	system("pause");
} 

