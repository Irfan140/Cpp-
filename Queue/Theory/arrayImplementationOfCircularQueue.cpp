#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Queue{
    public:
    int f;
    int b;
    int s; // maintainig a size variable
    vector<int> arr;
    Queue(int val){
        f = 0;
        b = 0;
        s = 0;
        vector<int> v(val);
        arr = v; // v gets copied to arr;
    }
    void push(int val){
        if(b==arr.size()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[b] = val;
        b++;
        s++;
    }
    void pop(){
        if(s==0) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        f++;
        s--;
    }
    int front(){
        if(s==0) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s==0) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return s;
    }
    bool empty(){
        if(f-b==0) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    q.push(5);
    q.push(6);
    q.display();
    q.pop();
    q.display();
}