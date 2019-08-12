# CS 165: Project 2
This project involves testing various bin packing algorithms and determining their experimental "waste" for a given list of items. This waste is defined as the number of bins used MINUS the total size of all the items in the list.

# Motivation
This is based on the instructions for the second project of CS 165. How I am approaching the project is test-driven, with the tests being made first before
the sorts are applied onto the inputs. Each sort will be done on randomized input.

# Tech/Framework Used
**Build with:**
- C++
    - cmath
    - ctime
    - iostream
    - ifstream
    - random
    - vector
    - string
    - chrono
    - algorithm
- Python
    - matplotlib
    - numpy
- LaTeX
- Bash

# Features
The project can bin pack a vector of *n* doubles into another vector with the following:
- Next Fit
- First Fit
- First Fit Decreasing
- Best Fit
- Best Fit Decreasing

In addition, the project comes with these features:
- generator for randomized input
- functions to get the waste of an algorithm
- functions to graph out the data
- a report with analysis on bin-packing algorithm performance

# How to use?
Build with the makefile. Modify main.cpp if you want to change the parameters!

To utilize the actual algorithms, have the appropriate project2.h and utils.h along with the needed .cpp file.