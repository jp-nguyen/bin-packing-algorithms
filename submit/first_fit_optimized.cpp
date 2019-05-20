#include "project2.h"
#include "utils.h"

/*
void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int count = 0;
    int j;
    
    free_space.push_back(1.0);
    for (int i = 0; i < n; ++i) {
        for (j = 0; j < count; ++j) {
            if (items[i] <= free_space[j]) {
                free_space[j] -= items[i];
                break;
            }
        }
        
        if (j >= count) {
            free_space.push_back(1.0 - items[i]);
            ++count;
        }
        assignment[i] = j;
    }
}

void first_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    vector<original> sorted_items(enumerated_sort(items));

    int n = sorted_items.size();
    int count = 0;
    int j;

    free_space.push_back(1.0);
    for (int i = 0; i < n; ++i) {
        for (j = 0; j < count; ++j) {
            if (sorted_items[i].value <= free_space[j]) {
                free_space[j] -= sorted_items[i].value;
                break;
            }
        }
        
        if (j >= count) {
            free_space.push_back(1.0 - sorted_items[i].value);
            ++count;
        }
        assignment[sorted_items[i].index] = j;
    }
}
*/