#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(){
    int n, counter = 0;
    vector<int> numeros;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 10000);

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

    for (int i = 0; i < n; i++)
    {
        numeros.push_back(distr(gen));
    }
    
}