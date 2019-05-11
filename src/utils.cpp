#include "utils.h"

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
