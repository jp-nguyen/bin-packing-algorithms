#ifndef PROJECT2_H
#define PROJECT2_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// implement in next_fit.cpp
void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space);

// implement in first_fit.cpp
void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space);
void first_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space);

// implement in best_fit.cpp
void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space);
void best_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space);

#endif