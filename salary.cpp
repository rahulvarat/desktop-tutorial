#include<iostream>
using namespace std;

void selectionsort(float arr[],int n){
    for(int i=0;i<n-1;i++){ 
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}

void bubblesort(float arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    float salary[]={20000.0,40000.0,30000.0,50000.0,60000.0,70000.0,};
    int n=6;

    float selectionarr[6];
    float bubblearr[6];
    for(int i=0;i<n;i++){
    selectionarr[i]=salary[i];
    bubblearr[i]=salary[i];
    }
    selectionsort(selectionarr,n);
    cout<<"selection sort  :";
    for(int i=0;i<n;i++){
        cout<<selectionarr[i]<<" ";

    }
    cout<<endl;

    bubblesort(bubblearr,n);
     cout<<"bubble sort  :";
     for(int i=0;i<n;i++){
        cout<<bubblearr[i]<<" ";
     }
     cout<<endl;
    cout<<"top 5 high salary  :" ;
    for(int i=n-1;i>n-5;i--){
        cout<<bubblearr[i]<<" ";
    }
    cout<<endl;

    

    return 0;
}