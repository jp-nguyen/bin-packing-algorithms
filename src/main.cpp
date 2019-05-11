#include <iostream>
#include <fstream>
#include "project2.h"
#include "utils.h"
using namespace std;

typedef void (*algorithm)(const vector<double>&, vector<int>&, vector<double>&); 

void run_bin_packing_algorithm(algorithm a, int n) {
    vector<double> items;
    generate_items(items, n);

    vector<int> assignment(items.size(), 0);
    vector<double> free_space;

    (*a)(items, assignment, free_space);

    double waste = (double) free_space.size() - sum(items);

    cout << "Packed " << n << " items with " << free_space.size() 
        << " bins, " << sum(items) << " actual size, and a waste of " 
        << waste << endl;
}

int main() {
    // string filename = "timings.csv";
    // create_empty_timings_sheet(filename);

    for (int n = 10; n <= 1000000; n *= 10)
        run_bin_packing_algorithm(&next_fit, n);

    return 0;
}
