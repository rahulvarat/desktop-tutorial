#include<iostream>
#include <algorithm>
using namespace std;
 bool linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }else{
            return false;
        }
    }
 }

 bool binarysearch(int arr[],int n,int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return true;
        }else if(arr[mid]<key){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
 }  

 int main(){
    int n;
    cout<<"enter no.of id card"<<endl;
    cin>>n;
      
   
    int arr[100];
    cout<<"enter the id number"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
     int key;
    cout<<"enter the key to search"<<endl;
    cin>>key;


    if(linearsearch(arr ,n,key)){
        cout<<"id: id is found"<<endl;
    }else{
        cout<<"id: not found";
    }


    sort(arr,arr+n);
    if(binarysearch(arr,n,key)){
        cout<<" id: found"<<endl;
    }else{
        cout<<"id not found";
    }

 }

 