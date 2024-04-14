#include <omp.h>
#include <iostream>

int main() {
    int k;
    std::cout << "Enter the number of threads: ";
    std::cin >> k;

    int rank; // ��������� ���������� rank 

    // OpenMP ������������ �������
    #pragma omp parallel num_threads(k) private(rank)
    {
        rank = omp_get_thread_num(); // ���������� rank ������� ��� ������ ����
        #pragma omp critical
        {
            std::cout << "I am " << rank << " thread." << std::endl;
        }
    }

    return 0;
}
