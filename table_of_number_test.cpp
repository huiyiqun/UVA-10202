#include <iostream>
#include <cstdlib>

#define MAX_INT 500000
#define NUMBER_OF_NUM 10000
#define NUMBER_OF_SUM NUMBER_OF_NUM * (NUMBER_OF_NUM - 1) / 2

using namespace std;

int Ns[] = {3, 6, 9, 10, 50, 100, 500, 1000, 5000, 10000};
int number_of_N = 6;
int sums[NUMBER_OF_SUM];
int nums[NUMBER_OF_NUM];

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    for (int i = 0; i < number_of_N; i++) {
        int N = Ns[i];
        cout << N << endl;
        int number_of_sum = N * (N - 1) / 2;
        int j;
        for (j = 0; j < N; j++)
            nums[j] = rand() % MAX_INT + 1;
        j = 0;
        for (int p = 0; p < N; p++)
            for (int q = 0; q < p; q++)
                sums[j++] = nums[p] + nums[q];
        qsort(sums, number_of_sum, sizeof(int), compare);
        qsort(nums, N, sizeof(int), compare);
        for (j = 0; j < number_of_sum; j++) {
            cout << sums[j];
            if (j == number_of_sum - 1)
                cout << endl;
            else
                cout << ' ';
        }
        for (j = 0; j < N; j++) {
            cerr << nums[j];
            if (j == N - 1)
                cerr << endl;
            else
                cerr << ' ';
        }
    }
    cout << 0 << endl;
}
