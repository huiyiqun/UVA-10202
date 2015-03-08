#include <iostream>
#include <set>

#define NUMBER_OF_NUM 100
#define NUMBER_OF_SUM NUMBER_OF_NUM * (NUMBER_OF_NUM - 1) / 2

using namespace std;

int N;
int nums[NUMBER_OF_NUM];

void output(int s[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        cout << s[i];
        if (i == len - 1)
            cout << endl;
        else
            cout << ' ';
    }
}

int main() {
    while(true) {
        cin >> N;
        int number_of_sum = N * (N - 1) / 2;
        if (N == 0)
            break;
        multiset<int> sums;
        for (int i = 0; i < number_of_sum; i++) {
            int temp;
            cin >> temp;
            sums.insert(temp);
        }
        // Deal with first two sums;
        multiset<int>::iterator it = sums.begin();
        int sums_0 = *it;
        sums.erase(it++);
        int sums_1 = *it;
        sums.erase(it++);
        for (; it != sums.end(); it++) {
            // nums[1] + nums[2] = sums[2, 3, 4, 5, 6, ..., N]
            // Try get nums[0]
            int last_it = 2;
            // copy sums
            multiset<int> i_sums(sums.begin(), sums.end());
            nums[0] = sums_0 + sums_1 - *it;
            if (nums[0] % 2 != 0)
                goto NEXT_I;
            nums[0] /= 2;
            nums[1] = sums_0 - nums[0];
            nums[2] = sums_1 - nums[0];
            if (nums[0] <= 0 || nums[1] < nums[0] || nums[2] < nums[1])
                goto NEXT_I;
            while (true) {
                for (int i = 1; i < last_it; i++) {
                    multiset<int>::iterator sum_it = i_sums.find(nums[last_it] + nums[i]);
                    if (sum_it == i_sums.end()) {
                        cerr << nums[last_it] + nums[i] << " is not found!" << endl;
                        goto NEXT_I;
                    }
                    else {
                        i_sums.erase(sum_it);
                    }
                }
                if (i_sums.empty())
                    break;
                multiset<int>::iterator it_least = i_sums.begin(); // The least
                nums[++last_it] = *it_least - nums[0];
                i_sums.erase(it_least);
            }
NEXT_I:
            if (i_sums.empty()) {
                break;
            }
        }
        if (it == sums.end()) {
            cout << "impossible" << endl;
        }
        else {
            output(nums, N);
        }
    }
}
