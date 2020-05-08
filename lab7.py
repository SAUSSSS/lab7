from scipy.integrate import odeint  
import numpy as np                   
import matplotlib.pyplot as plt      
 
def f(u, x):
    y = u[0]
    z = u[1]
    return [z, x*np.exp(-x) - y ]

def ff(u, x):
    y = u[1]
    z = u[0]
    return [z,-(x+1)*np.exp(-x) - y*x]


# Аналитическое решение
def analytical1(t):
    return np.cos(t)/2 + (np.exp(-t) * np.cos(t) * (np.cos(t) + t * np.cos(t) + t * np.sin(t)))/2 + (np.exp(-t)*np.sin(t)*(np.sin(t)-t*np.cos(t)+t*np.sin(t)))/2;

def analytical2(t):
    return -(np.exp(t) * np.sin(t) + t) / (2 * np.exp(t))
    

x = np.arange(0.0, 2.0, 0.01)    
y0 = [0.0, 1.0]
y1 = [1.0, 0.0]     
 
solution1 = odeint(f, y0, x)
solution2 = odeint(ff, y1, x)
 
fig1 = plt.figure()
ax1 = fig1.add_subplot()

fig2 = plt.figure()
ax2 = fig2.add_subplot()

ax1.plot(solution1[:,1], label = 'y(x)')
ax1.plot(analytical1(x), label = 'y(x) Analytical')
ax1.legend()

ax2.plot(solution2[:,1], label = 'y(x)')
ax2.plot(analytical2(x), label = 'y(x) Analytical')
ax2.legend()