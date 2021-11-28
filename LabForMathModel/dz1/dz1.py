import math
import matplotlib.pyplot as plt

x = []
y = []
t1 = []

сorner = 45
v0 = 1000
g = 9.8

t = 2 * v0 * math.sin(corner)/g
h = 10 

while t >= 0:
y.append(((-g*t*t/2) + (v0 * math.sin(corner)*t))/1.4)
x.append(v0*math.cos(corner)*t)
t1.append(t)
t-=h



grah = plt.figure() # Создание объекта Figure
plt.plot(x, x)


plt.plot(x, y)
plt.grid(True)


plt.show()