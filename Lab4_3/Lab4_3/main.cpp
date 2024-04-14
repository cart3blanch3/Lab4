#include <iostream>
#include <omp.h>

int main() {
    int k;
    std::cout << "Enter the number of threads: ";
    std::cin >> k;

    // ��������� OpenMP ������� k �������
    #pragma omp parallel num_threads(k)
    {
        // �������� ����� �������� ������ � ����� ���������� �������
        int thread_num = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        // ���������, �������� �� ����� ���� ������
        if (thread_num % 2 == 0) {
            // �������� ����� � ������� ����������� ������
            #pragma omp critical
            {
                // ������ ������ ���� ������� ���������� � ����
                std::cout << "I am " << thread_num << " thread from " << num_threads << " threads!" << std::endl;
            }
        }
    }

    return 0;
}
