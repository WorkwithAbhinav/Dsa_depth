#include <bits/stdc++.h>
using namespace std;

class heap{
public:
vector<int> arr;
int size ;

    heap(){
        size =0;
        arr.push_back(-1);
    }

    // time complexity of insertion is :- O(log(n))
    // space used is :- O(n);

    void insert(int data){
        // increasing size pointer because of zero based indexing 
        size = size+1;
        //creating a temp variable to iterate through the array 
        int index = size;
        // at that index basically at the last index add the data 
        arr.push_back(data);

        // now traversing and checking if the parent is not smaller then the added index 
        while(index > 1){
            // the parent will lie in the i/2 index 
            int parent = index/2;
            
            // if the parent is smaller then swap the values 
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }//else just return the current heap
            else{
                return;
            }
        }
    }

    void print(){
        for(int i =1; i<=size ;i++){
            cout << i << "->" << arr[i] << " ";
        }cout << endl;
    }

    void del(){
        // in heap deletion is allowed only on the root node 
        arr[1] =arr[size];
        // so enter the last element in the root node 
        size--;
        // decrease the size of the arr so now the last node is at first and the root node is deleted 


        // in this part we just have to check if the first node which is also the replaces node is in the correct position
        // if not take it to the correct position 
        int index =1;
        while(index <size){
        
            int leftindex = index*2; // take out the left index 
            int rightindex = index*2 +1; // take out the right index 

            if(leftindex <size && arr[leftindex] >arr[index]){ // checking if the arr [left index > index ]  
                swap(arr[leftindex] , arr[index]);// if not swap them 
                index =leftindex; // and increament the index 
            }
            else if(rightindex <size && arr[rightindex] >arr[index]){
                swap(arr[rightindex] , arr[index]);
                index =rightindex;
            }
            else{
                return ;
            }
        }
    }
};

void heapify(vector<int> &arr, int index, int size) {
    int maxelement = index;
    int leftindex = index * 2;
    int rightindex = index * 2 + 1;

    if (leftindex <= size && arr[leftindex] > arr[maxelement]) {
        maxelement = leftindex;
    }
    if (rightindex <= size && arr[rightindex] > arr[maxelement]) {
        maxelement = rightindex;
    }

    if (maxelement != index) {
        swap(arr[index], arr[maxelement]);
        heapify(arr, maxelement, size);
    }
}

void heapsort(vector<int> &arr , int size){
    int s =size;
    while(s>1){
        swap(arr[1] ,arr[s]);
       
        s--;

        heapify(arr,1,s);
    }
}


int main(){
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.del();
    // h.print();

    vector<int> arr = {-1,54,55,53,52,50};
    int n = arr.size();
    for(int i = n/2 ; i >0 ;i--){
        heapify(arr,i,n);
    }
    for(int i =1 ;i <n;i++){
        cout << arr[i] << " " ;
    }cout << endl;

    heapsort(arr,n);
    for(int i =2 ;i <=n;i++){
        cout << arr[i] << " " ;
    }cout << endl;


}