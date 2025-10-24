
a=[28,42,54,68,82,96,109,122]
x=[]
for i in range(len(a)-1):
	x.append(a[i+1] - a[i])

delta = sum(x)/len(x) * 1e-6
l = 1e-2 * 2
v = l / delta
print(v)