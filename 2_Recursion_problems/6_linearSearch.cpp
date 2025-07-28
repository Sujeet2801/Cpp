#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key){

    if(size == 0) return false;

    if(arr[0] == key){
        return true;
    }

    return linearSearch(arr+1, size-1, key);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 7;

    cout << linearSearch(arr, size, key) << endl;

    return 0;
}