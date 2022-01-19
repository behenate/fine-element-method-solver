import matplotlib.pyplot as plt
import numpy as np


def xi(i, n, a, b):
    return ((b - a) / n) * i


def e(i, n, a, b, x):
    if i - 1 >= 0 and xi(i - 1, n, a, b) <= x <= xi(i, n, a, b):
        return (x - xi(i - 1, n, a, b)) / (xi(i, n, a, b) - xi(i - 1, n, a, b))
    elif i + 1 <= n and xi(i, n, a, b) <= x <= xi(i + 1, n, a, b):
        return (xi(i + 1, n, a, b) - x) / (xi(i + 1, n, a, b) - xi(i, n, a, b))
    else:
        return 0


def getU(x, n, a, b, result_arr):
    sum = 0
    i = 0
    for value in result_arr:
        sum += e(i, n, a, b, x) * value
        i += 1
    return sum


f = open("../result.txt", "r")
content_arr = f.read().split(";")
n = int(content_arr[0])
a = float(content_arr[1])
b = float(content_arr[2])
result_arr = content_arr[3:]
for i in range(len(result_arr)):
    result_arr[i] = float(result_arr[i])

points = int(100)  # Number of points
xlist = np.linspace(a, b, 100)
ylist = []
for elem in xlist:
    ylist.append(getU(elem, n, a, b, result_arr))
plt.plot(xlist, ylist)
plt.show()
