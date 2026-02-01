#include <iostream>
using namespace std;
void sortRec(int a[], int n){
    if(n==1) return;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) swap(a[i],a[i+1]);
    }
    sortRec(a,n-1);
}
int binRec(int a[],int l,int h,int k){
    if(l>h) return -1;
    int m=(l+h)/2;
    if(a[m]==k) return m;
    if(a[m]>k) return binRec(a,l,m-1,k);
    return binRec(a,m+1,h,k);
}

int main(){
    int a[]={9,2,2,33,44,222,11,33,123,21,999,7,1,5},n=sizeof(a)/sizeof(a[0]),k=222;
    sortRec(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    int idx=binRec(a,0,n-1,k);
    if(idx!=-1) cout<<"found at "<<idx; 
    else cout<<"not found";
}

