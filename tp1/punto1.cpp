#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;

int main(){

    std::vector<int> primos;
    int counter = 0;
    int i, n;
    bool esPrimo;
    
    cout << "Ingrese un numero n mayor a 10^5: ";
    while (true)
    {
        if (cin >> n && n >= 1e5) break;
        else{
            cout << "Entrada invalida. Ingrese un numero n mayor o igual a 10^5: ";
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(10000, '\n'); // Ignora los caracteres basura en el buffer hasta el próximo enter
        }
    }

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
    chrono::duration<double, std::milli> tiempo = fin - inicio;
    cout << "El proceso tardo: " << tiempo.count() << " ms" << endl;
}
