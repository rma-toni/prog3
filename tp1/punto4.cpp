#include <iostream>
#include <chrono>

using namespace std;

int main(){
    
    auto inicio = chrono::high_resolution_clock::now();
    
    int n = 10;
    double dx = 1.0/n;
    double suma = 0.0;
    double x, altura, area;
    
    for (int i = 0; i < n; i++)
    {
        x = (i+0.5) * dx;
        altura = 4.0 / (1.0 + (x*x));
        area = altura * dx;
        suma+=area;
    }

    cout << "El valor obtenido es " << suma << endl;
    

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
}