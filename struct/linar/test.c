#include<stdio.h>
int main()
{
	char s1[50],s2[50];
	char c;
	int i=0,j=0,k=0;
	while(scanf("%c", &c), c!='#') 
	{
	   s1[i++] = c; 
	}
	s1[i]='\0';
	while(scanf("%c", &c), c!='#') 
	{
	   s2[j++] = c; 
	}
	s2[j]='\0';
	i=0;
	//j=j-1;
	while(s1[i]!='\0')
	{
		s2[j++]=s1[i++];
	}
	s2[j]='\0';
	
	printf("%s",s2);
	
	return (0);
}