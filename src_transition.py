import numpy as np
import pandas as pd

def smooth_signal(x, window=15):
    return pd.Series(x).rolling(window, center=True, min_periods=1).mean().values

def detect_transition(x):
    s = smooth_signal(x)
    dx = np.gradient(s)
    z = (dx - np.mean(dx)) / (np.std(dx) + 1e-9)
    idx = np.argmax(np.abs(z))
    return idx, z[idx]
