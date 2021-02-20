#include<bits/stdc++.h>
using namespace std;
template <typename Stack>
void Peek(Stack arr[], int top){
    if(top>=0)
    cout<<arr[top];
    else cout<<"Stack Underflow :(";
}
template <typename Stack>
void Push(Stack arr[], int size, int &top, int element){
    if(top==size-1) {cout<<"Stack Overflow :(\n"; return;}
    else {top++; arr[top]=element;}   
}
template <typename Stack>
void Pop(Stack arr[], int &top){
    if(top<0) cout<<"Stack Underflow :(\n";
    else {cout<<"Element "<<arr[top]<<" is deleted :)\n";
    top--;}
}
template <typename Stack>
void Display(Stack arr[], int top){
    if(top<0) cout<<"Stack Underflow :("<<endl;
    else {cout<<"\nElements in Stack>>>";
    while (top>=0)
        {cout<<arr[top]<<"\t"; top--;}
    cout<<endl;}
}

int main(){

    cout<<"WELCOME TO STACK:)"<<endl;
    cout<<"Enter maximum size of the stack>>";
    int size; cin>>size; int arr[size], top=-1;
    int choice;
    do{

        cout<<"Enter your choice(1 to Push, 2 to pop, 3 to peek, 4 to display stack, 0 to exit)>>>";
        cin>>choice;
        switch (choice)
        {
        case 0:{cout<<"Thanks...:)"<<endl;
            break;}
        case 1:{cout<<"Enter element you want to Push>>>";int el; cin>>el; Push(arr,size,top,el);
            break;}
        case 2:{cout<<"Element being poped...";Pop(arr,top);
            break;}
        case 3:{cout<<"Element at top>>>";Peek(arr,top); cout<<endl;
            break;}
        case 4:{Display(arr,top);
            break;}
        default:{cout<<"Wrong Choice:(...Choose Again:)"<<endl;
            break;}
        }
    }while(choice != 0);
    return 0;
}