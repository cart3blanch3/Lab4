#include <iostream>
#include <omp.h>

int main() {
    int k, N;
    std::cout << "Enter the number of threads (k): ";
    std::cin >> k;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    int sum = 0; // Общая сумма

    // Параллельная секция
    // Параметр reduction указывает, что переменная total_sum будет использоваться для суммирования значений из разных нитей
    #pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num(); // Получаем идентификатор текущей нити

        // Цикл для каждой нити, вычисляющий сумму чисел от 1 до N с шагом k
        for (int i = thread_id + 1; i <= N; i += k) {
            sum += i; // Добавляем текущее значение к общей сумме
        }

        // Выводим частичную сумму каждой нити
        #pragma omp critical
        {
            std::cout << "[" << thread_id << "]: Sum = " << sum << std::endl;
        }
    }

    // После завершения параллельной секции выводим общую сумму
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
