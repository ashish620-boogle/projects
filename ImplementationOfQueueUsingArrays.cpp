#include<bits/stdc++.h>
using namespace std;
template <typename Queue>
void Insert(Queue arr[], int size, int &top, int &bottom, int element){
    if(bottom==size-1) {cout<<"Queue Overflow :(\n"; return;}
    else {
        if(top==bottom && top<0) { top++; bottom++; arr[bottom]=element;} 
        else {bottom++; arr[bottom]=element;}
    }   
}
template <typename Queue>
void Delete(Queue arr[], int &top, int bottom){
    if(top<0 || top>bottom) cout<<"Queue Underflow :(\n";
    else top++;
}
template <typename Queue>
void Display(Queue arr[], int top, int bottom){
    if(top<0 || top>bottom) cout<<"Queue Underflow :(\n";
    else 
    {
        cout<<"\nElements in Queue>>>";
            while (top<=bottom)
                {cout<<arr[top]<<"\t"; top++;}
        cout<<endl;   
    }
}

int main(){

    cout<<"WELCOME TO QUEUE:)"<<endl;
    cout<<"Enter maximum size of the queue>>";
    int size; cin>>size; int arr[size], top=-1, bottom=-1;
    int choice;
    do{

        cout<<"Enter your choice(1 to Insert, 2 to Delete, 3 to Display, 0 to exit)>>>";
        cin>>choice;
        switch (choice)
        {
        case 0:{cout<<"Thanks...:)"<<endl;
            break;}
        case 1:{cout<<"Enter element you want to Insert>>>";int el; cin>>el; Insert(arr,size,top,bottom,el);
            break;}
        case 2:{cout<<"Element being deleted...";Delete(arr,top,bottom);
            break;}
        case 3:{Display(arr,top,bottom);
            break;}
        default:{cout<<"Wrong Choice:(...Choose Again:)"<<endl;
            break;}
        }
    }while(choice != 0);
    return 0;
}