#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct quality {
    string algorithm;
    int n;
    double waste;
};

void create_empty_qualities_sheet(string filename);
void add_quality_to_sheet(string filename, quality q);
void print_quality(quality q);

struct original {
    double value;
    int index;
};

struct {
    bool operator()(original a, original b) const {
        return a.value > b.value;
    }
} custom_greater;

vector<original> enumerated_sort(const vector<double>& items);
double randdouble();
void generate_items(vector<double>& items, int n);
void generate_test_items(vector<double>& items);
void print_items(const vector<double>& items);
void print_results(const vector<double>& items, const vector<int>& assignment, const vector<double>& free_space);
double sum(const vector<double>& items);

#endif
