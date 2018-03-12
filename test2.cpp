#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
//#define N 100001
#define ff first
#define ss second
const int N =  500 + 10;

int steps = 0;
/*void insert(int *a,int index){
	int temp = index;
	int par = index/2;
	while(par>=1){
		if(a[par] > a[index]){
			swap(a[index], a[par]);
			index /=2;
			par /=2;
		}
		else{
			break;
		}
	}
	return;
}*/
//code part
void heapify(int *a,int index, int size){
	int temp = index;
	int min1 = a[index];
	steps += 2;
	steps += 2;
	if(index*2 <= size && min1 > a[index*2]){
		steps += 2;
		min1 = a[index*2];
		temp = index*2;
	}
	steps += 2;
	if(index*2 + 1 <= size && min1 > a[index*2 + 1]){
		steps += 2;
		min1 = a[index*2 + 1];
		temp = index*2 + 1;
	}
	steps += 1;
	if(temp != index){
		steps += 2;
		swap(a[temp], a[index]);
		heapify(a, temp, size);
	}
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		steps = 0;
		int n;
		n = rand()%1000 + 1;
		int a[2*n+3];
		for(int i=1;i<=n;i++){
			a[i] = rand()%100001;
		//	cout<<a[i]<<" ";
			//insert(a,i);
		}
		sort(a ,a + n);
		//code part
		int k;
		k = rand()%n;
		for(int i=n;i>n-k;i--){
			steps += 3;\
			//cout<<a[1]<<" ";
			steps += 3;
			a[1] = a[i];
			heapify(a,1,i-1); 
		}
		cout<<k*(log2(n+1))<<" "<<steps<<"\n";
	}
}