#include <iostream>

using namespace std;

void burbuja(int* arr, int n) {
    for (int i=0; i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insercion_directa(int *arr,int n) {
    int x;
    int j;
    for (int i=1;i<n;i++) {
        x=arr[i];
        j=i-1;
        while ((j>=0) && (arr[j]>x)) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
}

void imprimeArr(int *arr, int n) {
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
int main() {
    int arreglo[]={3,7,5,2,1};
    //burbuja(arreglo,5);
    cout<<"Ordena por inserción:\n";
    insercion_directa(arreglo,5);
    imprimeArr(arreglo,5);
    system("pause");
}
    