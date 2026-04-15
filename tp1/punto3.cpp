#include <random>
#include <iostream>
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


    int n = std::stoi(argv[1]); // no pido valores por teclado ya que el objetivo es medir el tiempo

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 10);
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    std::vector<int> vec(n);

    for(int i = 0; i < n; i++){
        vec[i] = distr(gen);
        for(int j = 0; j < n; j++){
            matriz[i][j] = distr(gen);
        }
    }

    int aux = 0;
    std::vector<int> final(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux += matriz[i][j] * vec[j];
        }
        final[i] = aux;
        aux = 0;
    }

    for (auto &&i : final)
    {
        cout << i << " ";
    }
    
    

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> tiempo_transcurrido = fin - inicio;

    cout << "Resultados del analisis:" << endl;
    cout << "El proceso tardo: " << tiempo_transcurrido.count() << " ms" << endl;
}