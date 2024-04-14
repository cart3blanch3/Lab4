#include <iostream>
#include <omp.h>

int main() {
    // Указываем OpenMP создать 4 потока
    #pragma omp parallel num_threads(4)
    {
        // Критическая секция для корректного вывода в стандартный поток вывода
        #pragma omp critical
        {
            // Каждый поток выводит строку "Hello World!"
            std::cout << "Hello World!" << std::endl;
        }
    }
    return 0;
}
