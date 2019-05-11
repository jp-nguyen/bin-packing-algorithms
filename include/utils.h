#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <cmath>
using namespace std;

struct quality {
    string algorithm;
    int n;
    double waste;
};

double randdouble();
void generate_items(vector<double> & items, int n);
void print_items(const vector<double> & items);
double sum(const vector<double> & items);

#endif