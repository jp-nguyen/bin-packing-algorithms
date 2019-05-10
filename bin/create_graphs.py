import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.interpolate as ip
import sys

if __name__ == "__main__":
    argc = len(sys.argv)
    assert argc == 2, "program only accepts one file"