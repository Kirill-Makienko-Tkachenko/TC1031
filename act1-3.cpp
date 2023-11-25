//
// Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// Dulce Nahomi Bucio Rivas | A01425284
// Kirill Makienko Tkachenko | A01425218
// Desirée Espinosa Contreras | A01425162
// 06/09/2023
//


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

map<string, int> MAPA;

// Función para imprimir los respectivos registros
void imprimeRegistros(map<string, int> registros) {
    map<string, int>::iterator it = registros.begin();
    while (it != registros.end())
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }
}

// Función para convertir los meses a números para optimizar la búsqueda
int mesANum(char *arr){
    string palabra(arr, 3), palabra3;
    // Convierte a string el día
    int len = strlen(arr), day;
    
    if (len == 5){
        string palabra2(arr, 4,1);
        day = stoi(palabra2);
    }
    else{
        string palabra2(arr, 4,2);
        day = stoi(palabra2);
    }

    // Convierte los meses a números
    int date;
    if (palabra == "Jan"){ 
        date = 1;
    }
    else if (palabra == "Feb"){
        date = 2;
    }
    else if (palabra == "Mar"){
        date = 3;
    }
    else if (palabra == "Apr"){
        date = 4;
    }
    else if (palabra == "May"){
        date = 5;
    }
    else if (palabra == "Jun"){
        date = 6;
    }
    else if (palabra == "Jul"){
        date = 7;
    }
    else if (palabra == "Aug"){
        date = 8;
    }
    else if (palabra == "Sep"){
        date = 9;
    }
    else if (palabra == "Oct"){
        date = 10;
    }
    else if (palabra == "Nov"){
        date = 11;
    }
    else if (palabra == "Dec"){
        date = 12;
    }

    return date*100+day;
}

// Función para leer la bitácora y guardarla en un vector
vector<string> leeBitacora() {
    vector<string> registros;
    // Por alguna razón no deja usar el path relativo, cambiar esto por el path absoluto de su computadora
    ifstream bitacora("C:\\Users\\PC BULLOCK\\Documents\\3ero\\tc1031\\AcT1_3-TC1033\\bitacora.txt");
    string registro;

    // Verifica que el archivo se haya abierto correctamente
    if (!bitacora.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return {};
    }

    // Lee el archivo y lo guarda en un vector
    while (getline(bitacora, registro)) {
        char fecha[6];
        for(int i = 0; i < 6; i++) {
                fecha[i] = registro[i];
        }
        MAPA[registro] = mesANum(fecha);
    }
    return registros;
    bitacora.close();
}

// Función para escribir la bitácora seleccionada en un archivo según los indices dados
void escribirBitacora(const std::string& fileName, const vector<pair<string, int>> content, int indiceInicio, int indiceFinal) {
    ofstream outFile(fileName);
    // Verifica que el archivo se haya abierto correctamente
    if (!outFile) {
        std::cerr << "Failed to open the file: " << fileName << std::endl;
        return;
    }
    // Escribe en el archivo
    for (int i = indiceInicio; i < indiceFinal; i++){
        outFile << content[i].first << '\n';
    }
    outFile.close();
}

// Función para ordenar el mapa por valor
bool compareByValue(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

// Función para ordenar el mapa por valor
vector<pair<string, int>> sortMapByValue(const map<string, int>& originalMap) {
    vector<pair<string, int>> vec(originalMap.begin(), originalMap.end());
    sort(vec.begin(), vec.end(), compareByValue); //O(log n) -- Introsort    
    return vec;
}

// Función para realizar la búsqueda binaria entre las fechas dadas
int busqBinaria(vector<pair<string, int>> arr, int l, int r, int x) { // Complejidad O(log n), en este caso log 10 = 3 operaciones
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m].second == x)
            return m;
        if (arr[m].second < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Función para imprimir los datos de la bitácora desde el formato txt
void imprimeBitacora(const std::string& fileName) {
    ifstream inFile(fileName);
    // Verifica que el archivo se haya abierto correctamente
    if (!inFile) {
        std::cerr << "Failed to open the file: " << fileName << std::endl;
        return;
    }
    // Imprime el archivo
    cout << inFile.rdbuf();
    inFile.close();
}

int main() {

    // Lee la bitácora y la guarda en un vector
    vector<string> registros = leeBitacora();
    // Convierte el vector a un mapa para poder ordenarlo
    vector<pair<string, int>> ordenado = sortMapByValue(MAPA);

    // Solicita al usuario las fechas entre las que quiere buscar
    int fechaInicio, fechaFinal;
    cout << "¿Entre que fechas quiere buscar? (Formato: mm/dd, ej 909 para 9 de Septiembre)" << endl;
    cout << "Fecha inicial: ";
    cin >> fechaInicio;
    cout << "Fecha final: ";
    cin >> fechaFinal;
    // Obtiene los indices de las busquedas
    int indiceInicio = busqBinaria(ordenado, 0, ordenado.size(), fechaInicio);
    int indiceFinal = busqBinaria(ordenado, 0, ordenado.size(), fechaFinal);
    cout << indiceInicio << endl;
    cout << indiceFinal << endl;

    // Escribe los registros encontrados seleccionada en un archivo
    escribirBitacora("bitacoraSeleccionada.txt", ordenado, indiceInicio, indiceFinal);
    imprimeBitacora("bitacoraSeleccionada.txt");

    return 0;
}