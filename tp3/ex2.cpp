#include <iostream>
#include <omp.h>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 3) {
        std::cerr << "Error: Debes ingresar el valor de n y x." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    int x = std::stoi(argv[2]);
    vector<int> numeros(n);
    int counter = 0;

    #pragma omp parallel
    {
        // Instanciamos el RNG dentro del bloque paralelo 
        // para que cada hilo tenga su propio generador local.
        random_device rd;
        mt19937 gen(rd() ^ omp_get_thread_num()); 
        uniform_int_distribution<> distr(0, 10000);
        #pragma omp for
        for (int i = 0; i < n; i++)
        {
            numeros[i] = distr(gen);
        }
    }


    //reduction suma el resultado de cada hilo
    #pragma omp parallel for reduction(+:counter)
    for (int num : numeros)
    {
        if (num == x)
        {
            counter++;
        }
    }
    cout << "el numero se encontro " << counter << " veces" << endl;
}