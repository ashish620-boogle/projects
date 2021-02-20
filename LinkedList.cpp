#include<bits/stdc++.h>
using namespace std;

struct ll{
    string name;
    ll *next;
};
ll *top=NULL;


//Insertion of a new node at the lastmost position of the linked list.

void Insert_at_bottom(string d){
    if (top==NULL)      //when no element is present in the linked list
    {
        ll *temp;
        temp=new ll;
        temp->name=d;
        temp->next=NULL;
        top=temp;
        temp=NULL;
    }else
    {                   //when at least one element is present in the linked list
        ll *i=top;
        while (i->next!=NULL){
            i=i->next;
        }    
        ll *temp;
        temp=new ll;
        temp->name=d;
        temp->next=NULL;
        i->next=temp;
        temp=NULL;
        i=NULL;
    }   
}

//Insertion of a new node at the topmost position of the linked list.
void Insert_at_top(string d){
        ll *temp;
        temp=new ll;
        temp->name=d;
        temp->next=top;
        top=temp;
        temp=NULL;
}

//INSERT at a given position
void Insert_at_pos(string d, unsigned int pos=0){

    if (top==NULL || pos==0 || pos==1)
    {
        Insert_at_top(d);           //Insertion at top.
    }
    else
    {
        ll *i=top;              //Insertion at a given position.
        ll *temp;
        while (i->next!=NULL && pos-->2)
        {
            i=i->next;
        }
        if (pos>2)
        {
            cout<<"NO such position :("<<endl;
        }else{
            temp=new ll;
            temp->name=d;
            temp->next=i->next;
            i->next=temp; 
        }
        temp=NULL;
        i=NULL;      
    }
}

//to display all the elements in the linked list
void Display(){
    ll *i=top;
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;     //no element is present
    }else
    {
        while (i!=NULL)
        {   
            cout<<i->name<<" ";     //displays all the elements
            i=i->next;
        }
    }
}

//Delete the element from top
void Delete_from_top(){
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;    //when no element is present.
    }else{
        ll *temp=top;
        top=top->next;
        temp->next=NULL;
        delete temp;
    }
}

//Delete from the bottom
void Delete_from_bottom(){
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;    //when no element is present.
    }else{
        ll *temp, *i=top;
        while (i->next->next!=NULL)
        {
            i=i->next;
        }
        temp=i->next;
        i->next=NULL;
        delete temp;
    }
}

void Delete_from_pos(unsigned int pos=0){
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;    //when no element is present.
    }else{
        if (pos==0)
        {
            Delete_from_top();
        }else
        {
            ll *temp, *i=top;
            while (i->next->next!=NULL && pos-->1)
            {
                i=i->next;
            }
            if (pos>1)
            {
                cout<<"Underflow :("<<endl;  //when no element is present after given position to delete.
            }
            else
            {
                temp=i->next;
                i->next=temp->next;
                temp->next=NULL;
                delete temp;
            }
            i=NULL;
        }
    }
}
int main(){

    cout<<"Welcome to Linked list:)"<<endl;
    cout<<"1.Insert_at_bottom \n2.Display \n3.Insert_at_top \n4.Insert_at_pos \n5.Delete_from_pos \n6.Delete from top  \n7.Delete from bottom \n0.Exit";
    int choice;
    do{
        cout<<"Enter your choice>>";
        cin>>choice;
        switch (choice) 
        {
        case 1:{string h; cout<<"Enter Name>>>"; cin>>h; Insert_at_bottom(h);
            break;}
        case 2:{cout<<"Elements in the list>>>";Display(); cout<<endl;
            break;}
        case 3:{string h; cout<<"Enter Name>>>"; cin>>h; Insert_at_top(h);
            break;}
        case 4:{string h; unsigned int pos; cout<<"Enter Name>>>"; cin>>h; cout<<"Enter the position>>>"; cin>>pos; 
            Insert_at_pos(h,pos);   
            break;}
        case 5:{unsigned int pos; cout<<"Enter the position after which element should be poped>>>"; cin>>pos;     
            Delete_from_pos(pos);
            break;}
        case 6:{cout<<"Delete from top..."; Delete_from_top();
            break;}
        case 7:{cout<<"Delete from bottom..."; Delete_from_bottom();
            break;}
        case 0: {cout<<"Visit Again :)\n";break;}

        default:cout<<"Wrong choice :(\n";
            break;
        }
    }while (choice != 0);

    delete top;
    return 0;
}