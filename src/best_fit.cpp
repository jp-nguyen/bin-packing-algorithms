#include "project2.h"
#include "utils.h"

void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int count = 0;
    int bi;
    double min;

    for (int i = 0; i < n; ++i) {
        bi = 0;
        min = 1.1; // more than the capacity of a bin

        for (int j = 0; j < count; ++j) {
            if (items[i] <= free_space[j] && free_space[j] - items[i] < min) {
                bi = j;
                min = free_space[j] - items[i];
            }
        }
        
        if (min >= 1.1) {
            free_space.push_back(1.0 - items[i]);
            bi = ++count;
        } else {
            free_space[bi] -= items[i];
        }
        assignment[i] = bi;
    }
}

void best_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    vector<original> sorted_items(enumerated_sort(items));

    int n = sorted_items.size();
    int count = 0;
    int bi;
    double min;

    for (int i = 0; i < n; ++i) {
        bi = 0;
        min = 1.1;

        for (int j = 0; j < count; ++j) {
            if (sorted_items[i].value <= free_space[j] && 
                    free_space[j] - sorted_items[i].value < min) {
                bi = j;
                min = free_space[j] - sorted_items[i].value;
            }
        }
        
        if (min >= 1.1) {
            free_space.push_back(1.0 - sorted_items[i].value);
            bi = ++count;
        } else {
            free_space[bi] -= sorted_items[i].value;
        }
        assignment[sorted_items[i].index] = bi;
    }
}