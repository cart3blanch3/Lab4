#include <iostream>
#include <omp.h>

int main() {
    int k;
    std::cout << "Enter the number of threads: ";
    std::cin >> k;

    // Указываем OpenMP создать k потоков
    #pragma omp parallel num_threads(k)
    {
        // Получаем номер текущего потока и общее количество потоков
        int thread_num = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        // Проверяем, является ли номер нити четным
        if (thread_num % 2 == 0) {
            // Защищаем вывод с помощью критической секции
            #pragma omp critical
            {
                // Каждая четная нить выводит информацию о себе
                std::cout << "I am " << thread_num << " thread from " << num_threads << " threads!" << std::endl;
            }
        }
    }

    return 0;
}
