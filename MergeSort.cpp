#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v , int start , int mid , int end){
	int L = (mid - start + 1);
	int R = (end - mid);

	vector<int> left(L);
	vector<int> right(R);

	for(int i=0 ; i<L ;i++){
		left[i] = v[start + i];
	}
	for(int j=0 ; j<R ;j++){
		right[j] = v[mid + j + 1];
	}

	int i=0,j=0,k=start;
	while(i < L and j < R){
		if(left[i] <= right[j]){
			v[k] = left[i];
			i++;
		}
		else{
			v[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < L){
		v[k] = left[i];
		k++,i++;
	}
	while(j < R){
		v[k] = right[j];
		k++,j++;
	}
}

void mergeSort(vector<int> &v , int start , int end){
	if(start < end){
		int mid = start + (end-start)/2;
		mergeSort(v,start,mid);
		mergeSort(v,mid+1,end);
		merge(v,start,mid,end);
		return;
	}
	return;
}
int main(){
	vector<int> v {9,5,3,1,7,4,6,2};
	mergeSort(v,0,v.size()-1);
	cout<<"Sorted array is : ";
	for(auto x : v)
		cout<<x<<" ";
}
