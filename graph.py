import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt

data1 = np.loadtxt("y2.dat")


def analytical1(x):
    return np.cos(x)/2 + np.exp(-x)*(x/2 + 1/2)

def analytical2(t):
    return -(np.exp(t) * np.sin(t) + t) / (2 * np.exp(t))

x = np.arange(0.0, 2.0, 0.01) 




fig1 = plt.figure()
fig2 = plt.figure()
fig3 = plt.figure()

ax1 = fig1.add_subplot()
ax2 = fig2.add_subplot()
ax3 = fig3.add_subplot()
ax1.plot(x,data1[:,0], label = 'y(x)')

ax1.plot(x,data1[:,1], label = 'y*(x)')
ax1.legend()


ax2.plot(data1[:,0],data1[:,1],color = 'red',lw = 2, label = 'y*(y) phase trajectory')
ax2.legend()



ax3=plt.subplot('121')
ax3.plot(x,data1[:,0]-analytical1(x),label = ' ')
ax3=plt.subplot('122')
ax3.plot(x,data1[:,1]-analytical2(x),label = ' ')

ax3.legend()





