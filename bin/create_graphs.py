import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.interpolate as ip
import sys

def set_up_plot(ax, title):
    ax.set_title(title)
    ax.set_xlabel("Log of Size $n$")
    ax.set_ylabel("Log of Waste $W(n)$")
    ax.set_xticklabels(ax.get_xticks(), fontsize= 5)
    ax.set_yticklabels(ax.get_yticks(), fontsize= 5)
    ax.legend()

def get_line(x, y):
    A = np.vstack([np.log10(x), np.ones(len(x))]).T
    m, b = np.linalg.lstsq(A, np.log10(y), rcond=None)[0]
    return m, b

def get_data_from_file(filename):
    qualities = pd.read_csv(filename)
    print(qualities)

    algorithms = qualities['algorithm'].values
    x = qualities['n'].values
    y = qualities['waste'].values

    return algorithms, x, y

def plot_all_qualities(filename, algs, points, lines, outfile=""):
    algorithms, x, y = get_data_from_file(filename)

    colors = ['red', 'blue', 'green', 'purple', 'orange']
    _, ax = plt.subplots(1, 1, figsize = (6, 6))
    
    for i, alg in enumerate(np.unique(algorithms)):

        if (alg not in algs):
            continue

        mask = np.where(algorithms == alg)[0]

        if (points):
            ax.loglog(x[mask], y[mask], "o", markersize = 5, 
                      c = colors[i], label = alg)

        if (lines):
            m, b = get_line(x[mask], y[mask])
            if (points):
                ax.loglog(x[mask], np.power(x[mask], m) * 10 ** b, "r", 
                          c = colors[i])
            else:
                ax.loglog(x[mask], np.power(x[mask], m) * 10 ** b, "r", 
                          c = colors[i], 
                label = '$W(n) = n^{{ {} }} \\cdot 10^{{ {} }}$'.format(m, b))
    
    set_up_plot(ax, "Comparison of Bin Packing Algorithms")
    ax.legend()
    
    if (outfile != ""):
        plt.savefig(outfile)
    else:
        plt.show()

    plt.close() 

if __name__ == "__main__":
    argc = len(sys.argv)
    assert argc == 2, "program only accepts one file"

    plot_all_qualities(sys.argv[1], [
#        'next fit', 
        'first fit', 
        'first fit decreasing',
#        'best fit', 
#        'best fit decreasing',
        ], True, True) #, "all-qualities.png")