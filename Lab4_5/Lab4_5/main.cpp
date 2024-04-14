#include <iostream>
#include <omp.h>

int main() {
    int k, N;
    std::cout << "Enter the number of threads (k): ";
    std::cin >> k;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    int sum = 0; // ����� �����

    // ������������ ������
    // �������� reduction ���������, ��� ���������� total_sum ����� �������������� ��� ������������ �������� �� ������ �����
    #pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num(); // �������� ������������� ������� ����

        // ���� ��� ������ ����, ����������� ����� ����� �� 1 �� N � ����� k
        for (int i = thread_id + 1; i <= N; i += k) {
            sum += i; // ��������� ������� �������� � ����� �����
        }

        // ������� ��������� ����� ������ ����
        #pragma omp critical
        {
            std::cout << "[" << thread_id << "]: Sum = " << sum << std::endl;
        }
    }

    // ����� ���������� ������������ ������ ������� ����� �����
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
