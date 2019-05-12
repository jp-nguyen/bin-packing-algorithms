#include "project2.h"
#include "utils.h"
using namespace std;
typedef void (*algorithm)(const vector<double>&, vector<int>&, vector<double>&); 

string filename = "qualities.csv";

double run_bin_packing_algorithm(algorithm a, int n) {
    vector<double> items;
    generate_items(items, n);

    vector<int> assignment(items.size(), 0);
    vector<double> free_space;

    (*a)(items, assignment, free_space);

    return free_space.size() - sum(items);
}

void get_qualities(algorithm a, string alg, int reps, int limit) {
    quality q;
    q.algorithm = alg;

    cout << "getting qualities for " << alg << endl;
    cout << "--------------------" << endl;

    for (int n = 10; n <= limit; n *= 10) {
        q.n = n;

        for (int i = 0; i < reps; ++i)
            q.waste += run_bin_packing_algorithm(a, n);            

        q.waste /= reps;
        print_quality(q);
        add_quality_to_sheet(filename, q);
    }

    cout << "--------------------" << endl;
}

int main() {
    create_empty_qualities_sheet(filename);
    int reps = 5;
    int limit = 100000;

    get_qualities(&next_fit, "next fit", reps, limit);
    get_qualities(&first_fit, "first fit", reps, limit);
    get_qualities(&first_fit_decreasing, "first fit decreasing", reps, limit);
    get_qualities(&best_fit, "best fit", reps, limit);
    get_qualities(&best_fit_decreasing, "best fit decreasing", reps, limit);

    return 0;
}
