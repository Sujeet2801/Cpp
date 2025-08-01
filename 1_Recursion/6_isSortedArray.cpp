#include<iostream>
using namespace std;

bool isSortedArray(int arr[], int size){

    if(size == 1) return true;

    if(arr[0] > arr[1]){
        return false;
    }

    return isSortedArray(arr + 1, size - 1);
}

bool isSortedArrayIterative(int arr[], int size){

    if(size == 1) return true;

    for(int i=0; i<size; i++){
        if(arr[i] > arr[i+1] && (i+1) < size){
            return false;
        }
    }

    return true;
}

int main(){

    int arr[] = {1, 4, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << size << endl;
    cout << isSortedArrayIterative(arr, size) << endl;
    return 0;
}