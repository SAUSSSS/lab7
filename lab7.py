from scipy.integrate import odeint  
import numpy as np                   
import matplotlib.pyplot as plt      
 
def f(u, x):
    y = u[0]
    z = u[1]
    return [z,(1-x)*np.exp(-x) - y]

def ff(u, x):
    y = u[0]
    z = u[1]
    return [z,x*np.exp(-x) - y]



x = np.arange(0.0, 2.0, 0.01)    
y0 = [1.0, 0.0]
y1 = [1.0, 0.0]     
 
solution1 = odeint(f, y0, x)
solution2 = odeint(ff, y1, x)
 
fig1 = plt.figure()
ax1 = fig1.add_subplot()

fig2 = plt.figure()
ax2 = fig2.add_subplot()

ax1.plot(solution1[:,1], label = 'y(x)')
ax1.legend()

ax2.plot(solution2[:,1], label = 'y*(x)')
ax2.legend()