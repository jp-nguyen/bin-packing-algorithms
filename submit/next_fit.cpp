#include "project2.h"

void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int count = 0;

    free_space.push_back(1.0);
    for (int i = 0; i < n; ++i) {
        if (items[i] <= free_space[count]) {
            free_space[count] -= items[i];
        } else {
            free_space.push_back(1.0 - items[i]);
            ++count;
        }
        assignment[i] = count;
    }
}