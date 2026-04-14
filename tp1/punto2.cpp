#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(){
    int n;

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