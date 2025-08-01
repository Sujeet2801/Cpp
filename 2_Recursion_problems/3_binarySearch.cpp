#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int start, int end , int key){

    if(start > end) return -1;

    int mid = start + (end - start)/2;
    cout << "mid: " << mid << endl;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        return binarySearch(arr, size, start, mid-1, key);
    }
    else {
        return binarySearch(arr, size, mid+1, end, key);
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    cout << binarySearch(arr, size, 0, size, key) << endl;

    return 0;
}