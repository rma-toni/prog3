#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;

int main(){

    std::vector<int> primos;
    int counter = 0;
    int i;
    int n = 100000;
    bool esPrimo;

    auto inicio = chrono::high_resolution_clock::now();
    
    int k = n;
    while (k>1)
    {
        esPrimo = true;
        i = 2;
        while (i <= sqrt(k))
        {
            if (k % i == 0)
            {
                esPrimo = false;
                break;
            } 
            i++;
        }
        if (esPrimo)
        {
            primos.push_back(k);
        }
        k--;
    }
    for (int i = 0; i < 5; ++i) {
        cout << primos[i] << endl;
    }
    
    auto fin = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;
    

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
}
