#include<iostream>
using namespace std;
// array1 ->  {5 10 15 2 29 20}
// array2 ->  {5 1 15 2 9 21}
// output -> {5 15 2}

int* intersectionOfArray(int arr1[], int arr2[], int size, int &count){
    int *comman = new int[size]; //new array to store result
    int k = 0; // iterate over comman[]
    for(int i = 0; i < size; i++){ //array 1
        for(int j = 0; j < size; j++){ //array 2 element
            if(arr1[i] == arr2[j]){ //found comman element
                bool alreadyExist = false; 
                for(int m = 0; m < k; m++){  //check if element already exist in comman[]
                    if(arr1[i] == comman[m]){ 
                        alreadyExist = true; //exit loop if yes
                        break;
                    }
                }
                if(!alreadyExist){ //if Bot found element in comman[] 
                    comman[k] = arr1[i]; //store this element in comman[]
                    k++; count++;
                }
                break; //exit j loop here
                }
            }   
    }
    if(k == 0){ // no element is comman
        comman[k] = -1;
        cout<<comman[k];
    }
    else{
        return comman;
    }
}

int main(){
    int n;
    cout<<"enter size of array: "<<endl;
    cin>>n;
    int arr1[n], arr2[n];
    //array input 1.
    cout<<"enter array1 elements:"<<endl;
    for(int i = 0; i < n; i++)
        cin>>arr1[i];

    //array input 2.
    cout<<"enter array2 elements:"<<endl;
    for(int i = 0; i < n; i++)
        cin>>arr2[i];
    
    int count = 0;
    int * comman = intersectionOfArray(arr1, arr2, n, count);
    //print array
    for(int i = 0; i < count; i++){
        cout<<comman[i]<<" ";
    }
    delete[] comman;
    return 0;
}
