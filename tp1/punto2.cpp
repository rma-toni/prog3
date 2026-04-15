#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(){
    
    auto inicio = chrono::high_resolution_clock::now();
    
    int n = 1000000;

    vector<int> numeros;
    int counter = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 10000);

    for (int i = 0; i < n; i++)
    {
        numeros.push_back(distr(gen));
    }

    int x = 5; // entrada por usuario? (cin)
    for (int num : numeros)
    {
        if (num == x)
        {
            counter++;
        }
    }
    cout << "el numero se encontro " << counter << " veces" << endl;
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
}