#include "utils.h"

void create_empty_qualities_sheet(string filename) {
    ofstream file;
    file.open(filename, ofstream :: trunc);
    file << "algorithm,n,waste" << endl;
    file.close();
}

void add_quality_to_sheet(string filename, quality q) {
    ofstream file;
    file.open(filename, ofstream :: app);
    file << q.algorithm << "," << q.n << "," << q.waste << endl;
    file.close();
}

void print_quality(quality q) {
    cout << "Packed " << q.n << " items with a waste of " << q.waste << endl;
}

vector<original> enumerated_sort(const vector<double>& items) {
    int n = items.size();
    vector<original> sorted;
    for (int i = 0; i < n; ++i)
        sorted.push_back({items[i], i});
    sort(sorted.begin(), sorted.end(), custom_greater);

    return sorted;
}

double randdouble() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_real_distribution<double> range(0.0, 1.0);

    return range(gen);
}

void generate_items(vector<double>& items, int n) {
    for (int i = 0; i < n; ++i)
        items.push_back(randdouble());
}

void print_items(const vector<double>& items) {
    int n = items.size();
    for (int i = 0; i < n; ++i)
        cout << items[i] << endl;
    cout << "-------" << endl;
}

double sum(const vector<double>& items) {
    int n = items.size();
    double result = 0.0;

    for (int i = 0; i < n; ++i)
        result += items[i];

    return result;
}
