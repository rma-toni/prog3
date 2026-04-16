#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    
    auto inicio = chrono::high_resolution_clock::now();
    
    if (argc < 2) {
        std::cerr << "Error: Debes ingresar el valor de n." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::vector<int> primos;
    int counter = 0;
    int i;
    bool esPrimo;

    
    int k = 2;
    while (k<=n)
    {
        esPrimo = true;
        i = 2;
        while (i*i <= k)
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
        k++;
    }
    for (int i = primos.size()-5; i < primos.size(); ++i) {
        cout << primos[i] << endl;
    }
    
    auto fin = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;
    

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
}
