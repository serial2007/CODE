#include <iostream>
using namespace std;
int n, arr[1001], stack[1001], ptr;

int main() 
{
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++) stack[ptr++] = arr[i];
	for(int i=0; i<n; i++) arr[i] = stack[--ptr];
	for(int i=0; i<n; i++) cout << arr[i] << ' ';
	cout << endl;
}