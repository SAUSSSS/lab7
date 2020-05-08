import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("y1.dat")
data2 = np.loadtxt("y2.dat")

fig1 = plt.figure()
fig2 = plt.figure()
fig3 = plt.figure()

ax1 = fig1.add_subplot()
ax2 = fig2.add_subplot()
ax3 = fig3.add_subplot()

ax1.plot(data1[:,2],data1[:,0], label = 'y(x) Tylor')
ax1.plot(data1[:,2],data1[:,1], label = 'y(x) Analytical')
ax1.legend()

ax2.plot(data2[:,2],data2[:,0], label = 'y(streak)(x) Tylor')
ax2.plot(data2[:,2],data2[:,1], label = 'y(streak)(x) Analytical')
ax2.legend()

ax3.plot(data1[:,0],data2[:,0],label = 'y(x),y(streak)(x) phase trajectory')
ax3.legend()





