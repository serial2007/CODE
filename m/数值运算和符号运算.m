%%数值计算
y=@(x)2*x^3-x+5;
[xmin,ymin]=fminbnd(y,-1,1)

%%符号计算
syms x a
fx=1/(1+exp(-1/x))
limit(fx,x,a)

x=[0.9218;0.7382;0.1763];
A=[2/3,1/sqrt(2),1/(3*sqrt(2));1/3,0,-4/(3*sqrt(2));
2/3,-1/sqrt(2),1/(3*sqrt(2))];
ax=x;
n=100;
for k=1:n
	%A = rand(3,3);
	%A = orth(A);
	x=A*x;
	ax=[ax,x];
end
plot3(ax(1,:),ax(2,:),ax(3,:),'*')