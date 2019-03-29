#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> mem;

long long cycles(long long x){
	if(mem.find(x) != mem.end()) return mem[x];
	if(x%2 == 0) mem[x] = 1 + cycles(x/2); 
	else mem[x] = 2 + cycles((3*x+1)/2);
	return mem[x];
}

int main(int argc, char *argv[]) {
	long long i, j;
	mem[1] = 1;
	while(cin>>i>>j){
		long long mx= 0;
		for(long long x = min(i,j); x<= max(i,j); x++)
			mx =  max(cycles(x), mx);
		cout<<i<<" "<<j<<" "<<mx<<endl;
	}
    return 0;
}
