#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 2) {
        std::cerr << "Error: Debes ingresar el valor de n." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]); // no pido valores por teclado ya que el objetivo es medir el tiempo

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    std::vector<int> vec(n);

    #pragma omp parallel
    {
        random_device rd;
        mt19937 gen(rd() ^ omp_get_thread_num()); 
        uniform_int_distribution<> distr(0, 10);
        #pragma omp for
        for(int i = 0; i < n; i++){
            vec[i] = distr(gen);
            for(int j = 0; j < n; j++){
                matriz[i][j] = distr(gen);
            }
        }
    }

    
    std::vector<int> final(n);
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        int aux = 0; // se mueve dentro para evitar condicion de carrera 
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
    
}