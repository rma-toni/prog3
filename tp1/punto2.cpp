#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]){
    
    auto inicio = chrono::high_resolution_clock::now();
    
    if (argc < 3) {
        std::cerr << "Error: Debes ingresar el valor de n y x." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    vector<int> numeros;
    int counter = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 10000);

    for (int i = 0; i < n; i++)
    {
        numeros.push_back(distr(gen));
    }

    int x = std::stoi(argv[2]);
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