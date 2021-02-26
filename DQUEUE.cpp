#include<bits/stdc++.h>
using namespace std;
template <typename T>
union Ret
{
    T a; bool rtrn;
};

template <typename T>
void Insert_at_front(T arr[], int size, int &front, int &rear, T element){
    if(front<0 && rear<0){
        front=0; rear=0; arr[front]=element;
    }else if(rear-front+1==size || rear+1==front) cout<<"Queue Overflow :("<<endl;
    else
    {
        if(front==0 && rear<size-1){
            front=size-1;
            arr[front]=element;
        }else{
            arr[--front]=element;
        }
    }
}
template <typename T>
void Insert_at_rear(T arr[], int size, int &front, int &rear, T element){
    if(front<0 && rear<0){
        front=0; rear=0; arr[rear]=element;
    }else if(rear-front+1==size || rear+1==front) cout<<"Queue Overflow :("<<endl;
    else
    {
        if(front>0 && rear==size-1){
            rear=0;
            arr[rear]=element;
        }else{
            arr[++rear]=element;
        }
    }
}
template <typename T>
void Delete_at_front(T arr[], int size, int &front, int &rear){
    if(front==-1) {cout<<"Queue Underflow:("<<endl; return;}
    else if(front==rear) front=rear=-1;
    else if(front==size-1) front=0;
    else front++;
    cout<<"Successful :)"<<endl;
}
template <typename T>
void Delete_at_rear(T arr[], int size, int &front, int &rear){
    if(front==-1) {cout<<"Queue Underflow:("<<endl; return;}
    else if(front==rear) front=rear=-1;
    else if(rear==0) rear=size-1;
    else rear--;
    cout<<"Successful :)"<<endl;
}
template <typename T>
T Show_front(T arr[], int front){
    if(front==-1) {cout<<"Queue Underflow :("<<endl; Ret<T> dta; dta.rtrn=false; return dta.a; }
    return arr[front];
}
template <typename T>
T Show_rear(T arr[], int rear){
    if(rear==-1) {cout<<"Queue Underflow :("<<endl; Ret<T> dta; dta.rtrn=false; return dta.a; }
    return arr[rear];
}
template <typename T>
void Display(T arr[], int size, int front, int rear){
    if(front==-1 && rear==-1) cout<<"Queue Underflow :("<<endl;
    else
    {
        while(rear!=front){
            cout<<arr[front]<<"\t";
            if(front==size-1) front=0;
            else front++;
        }
        cout<<arr[front]<<endl;
    }  
}
int main(){

    int n;
    cout<<"WELCOME TO DQUEUE :)"<<endl;
    cout<<"Enter length of the DQueue>>>"; cin>>n;
    cout<<"1. Insert at top \n2. Insert at bottom \n3. Delete from top \n4. Delete from bottom \n5. Show top \n6. Show bottom \n7. Display the array \n0. Exit \nEnter your choice:-";
    int choice;
    int _num_, arr[n], front=-1, rear=-1;
    do{
        cin>>choice;
        switch (choice)
        {
        case 1:{cout<<"Enter the element>>>";  cin>>_num_; Insert_at_front(arr,n,front,rear,_num_);
            break;}
        case 2:{cout<<"Enter the element>>>";  cin>>_num_; Insert_at_rear(arr,n,front,rear,_num_);
            break;}
        case 3:{cout<<"Deleting the front element..."; Delete_at_front(arr,n,front,rear);
            break;}
        case 4:{cout<<"Deleting the rear element..."; Delete_at_rear(arr,n,front,rear);
            break;} 
        case 5:{cout<<"Peeking the front element..."; if(Show_front(arr,front))cout<<Show_front(arr,front)<<endl;
            break;}
        case 6:{cout<<"Peeking the rear element..."; if(Show_rear(arr,front))cout<<Show_rear(arr,front)<<endl;
            break;}
        case 7:{cout<<"Elements in the queue>>>"; Display(arr,n,front,rear);
            break;}
        case 0: {cout<<"Hope you liked it...;)"<<endl;
            break;}
        default:{cout<<"Wrong Input :("<<endl;
            break;}
        }
        if(choice!=0)
        cout<<"1. Insert at top \n2. Insert at bottom \n3. Delete from top \n4. Delete from bottom \n5. Show top \n6. Show bottom \n7. Display the array \n0. Exit \nEnter your choice:-";
        
    }while (choice != 0);    
    return 0;
}