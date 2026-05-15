#include <iostream>
#include <omp.h>

int main(){
    int threads, id = 100;
    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        threads = omp_get_num_threads();
        #pragma omp critical
        {
            std::cout << "Thread "<<id<<" de "<<threads<<std::endl;
        }
        
    }
    std::cout << "ID "<<id<<std::endl;
}