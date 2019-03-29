#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mem;

int cycles(int x){
	if(mem.find(x) != mem.end()) return mem[x];
	if(x%2 == 0) mem[x] = 1 + cycles(x/2); 
	else mem[x] = 2 + cycles((3*x+1)/2);
	return mem[x];
}

int main(int argc, char *argv[]) {
	int i, j;
	mem[1] = 1;
	while(cin>>i>>j){
		int mx = 0;
		for(int x = i; x<= j; x++)
			mx =  max(cycles(x), mx);
		cout<<i<<" "<<j<<" "<<mx<<endl;
	}
    return 0;
}
