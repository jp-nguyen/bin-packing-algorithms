#include "project2.h"

void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int j = 0;

    free_space.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (free_space[j] + items[i] <= 1.0) {
            free_space[j] += items[i];
        } else {
            free_space.push_back(items[i]);
            ++j;
        }
        assignment[i] = j;
    }
}