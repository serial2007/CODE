import numpy as np
v1=[0.54,0.90,1.29,1.66,2.03,2.40,2.78,3.17]
v2=[0.56,0.92,1.32,1.66,2.05,2.42,2.79,3.17]
v3=[0.56,0.93,1.31,1.68,2.03,2.42,2.79,3.17]
t =[0.04,0.08,0.12,0.16,0.20,0.24,0.28,0.32]

a1=[]; a2=[]; a3=[]
for i in range(4):
	a1.append((v1[i+4]-v1[i]) / (t[i+4]-t[i]))
	a2.append((v2[i+4]-v2[i]) / (t[i+4]-t[i]))
	a3.append((v3[i+4]-v3[i]) / (t[i+4]-t[i]))

s1=np.average(a1)
s2=np.average(a2)
s3=np.average(a3)
print(s1)
print(s2)
print(s3)
print((s1+s2+s3)/3)