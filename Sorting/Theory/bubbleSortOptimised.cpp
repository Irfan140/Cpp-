#include <iostream>
using namespace std;
int main(){
    int arr[]={4,3,2,1};
    int n=4;
    
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag==true) break; // Swap did not happen
        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}