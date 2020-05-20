import numpy as np
from scipy.integrate import odeint,solve_ivp
import scipy
from numpy import sqrt, exp
import matplotlib.pyplot as plt


def analytical1(x):
    return np.cos(x)/2 + np.exp(-x)*(x/2 + 1/2)

def analytical2(t):
    return -(np.exp(t) * np.sin(t) + t) / (2 * np.exp(t))


def model(t,z):
	# print(z)
	y1=z[0]
	y2=z[1]
	return [y2,t*np.exp(-t) - y1]

# initial condition
z0 = np.array([1,0])

solve = solve_ivp(model,[0, 2],z0,method='LSODA',min_step=0.01,max_step=0.01)

x=solve.t
z=solve.y
# print(z)

Y1=z[0]
Y2=z[1]

plt.subplot(221)
plt.plot(x,Y1)
# plt.show()
plt.subplot(222)
plt.plot(x,Y2)
# plt.show()
plt.subplot(223)
plt.plot(Y1,Y2)
plt.show()  



fig2 = plt.figure()
ax2 = fig2.add_subplot()

ax2=plt.subplot('122')
ax2.plot(x,Y1-analytical1(x), label = 'y(x)')
ax2=plt.subplot('121')
ax2.plot(x,Y2-analytical2(x), label = 'y*(x)')
ax2.legend()