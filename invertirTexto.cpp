#include <iostream>
#include <string.h>
using namespace std;


void invertirPalabra(char *s1, char *s2) {
    int contador = 0;
    char *p = &s1[strlen(s1)-1];
    char *p2=s2;

    while(p>=s1){
        *p2++=*p--;
        
    }
    
}



int main() {

    char s1[100], s2[100];

    cout << "escriba una palabra: " <<  endl;
    cin >> s1;
    invertirPalabra(s1, s2);
    cout << s2 <<endl;
}
