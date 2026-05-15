#include <iostream>
#include <omp.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 2) {
        cerr << "Error: Debes ingresar el valor de n." << endl;
        cerr << "Uso: " << argv[0] << " <numero>" << endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    vector<int> primos;

    #pragma omp parallel for
    for (int k = 2; k <= n; k++) {
        bool esPrimo = true;
        int i = 2;
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
            #pragma omp critical
            primos.push_back(k);
        }
    }

    sort(primos.begin(), primos.end());

    for (int i = primos.size()-5; i < primos.size(); ++i) {
        cout << primos[i] << endl;
    }
    
}