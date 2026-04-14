#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int primos[5];
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

    int k = n;
    while (counter<5)
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
            primos[counter] = k;
            counter++;
        }
        
        k--;
    }

    for (int num : primos)
    {
        cout << num << endl;
    }
    
    
}
