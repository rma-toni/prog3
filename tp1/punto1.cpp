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

    clock_t cpu_inicio = clock();
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
    
    clock_t cpu_fin = clock();
    auto fin = chrono::high_resolution_clock::now();
    
    double cpu_usada = double(cpu_fin - cpu_inicio) / CLOCKS_PER_SEC;
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;
    
    double porcentaje = (cpu_usada / tiempo_transcurrido.count()) * 100.0;

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
    cout << "Uso de CPU: " << porcentaje << "%" << endl;
}
