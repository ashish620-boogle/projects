#include<bits/stdc++.h>
using namespace std;

struct ll{
    string name;
    ll *next;
};
ll *top=NULL;
void Create(string d){
    if (top==NULL)
    {
        ll *temp;
        temp=new ll;
        temp->name=d;
        temp->next=NULL;
        top=temp;
        temp=NULL;
    }else
    {
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
void Display(){
    ll *i=top;
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;
    }else
    {
        while (i!=NULL)
        {   
            cout<<i->name<<" ";
            i=i->next;
        }
    }
}
void Reverse()
{
    if (top!=NULL)
    {
       ll *prev=NULL, *curr=top, *nextnode=top->next;
       while (curr!=NULL)
       {
           curr->next=prev;
           prev=curr;
           curr=nextnode;
           if (nextnode!=NULL)    
            nextnode=nextnode->next;
       }
       top=prev;   
    }else
    {
        cout<<"Underflow :("<<endl;
    } 
}
void Sort_And_Display(){
    if (top==NULL){}
    else
    for (ll* i = top; i->next != NULL; i=i->next)
    {
        for (ll* j = i->next; j != NULL; j=j->next)
        {
            if (i->name > j->name)
            {
                swap(i->name, j->name);
            }
            
        }
        
    }
    Display();
}
void Insert(string d, string s="\0", unsigned int pos=0){

    if (top==NULL)
    {
        Create(d);
    }
    else if (pos>0)
    {
        ll *i=top;
        ll *temp;
        if (pos==1)
        {  
            temp=new ll;
            temp->name=d;
            temp->next=i;
            top=temp;
        }
        else
        {
            while (i->next!=NULL && pos-->2)
            {
                i=i->next;
            }
            if (pos>2)
            {
                cout<<"NO such position :("<<endl;
            }
            else
            {
                temp=new ll;
                temp->name=d;
                temp->next=i->next;
                i->next=temp; 
            }  
        }
        temp=NULL;
        i=NULL;
            
    }else if (pos==0)
    {
        ll *i=top,*temp;
        if (s == "\0")
        {
            temp=new ll;
            temp->name=d;
            temp->next=i;
            top=temp;
        }
        else
        {
            while (i->next!=NULL)
            {
                if(i->name==s) break;
                i=i->next;
            }
            temp=new ll;
            temp->name=d;
            temp->next=i->next;
            i->next=temp;
        }
        temp=NULL;
        i=NULL;
    }
    
}
void Delete(string d){
    if (top==NULL)
    {
        cout<<"Underflow:("<<endl;
    }else
    {
        ll *i=top;
        if (i->name==d)
        {
            ll *temp;
            temp=top;
            top=top->next;
            temp->next=NULL;
            delete temp;   
            return;
        }
        while (i->next!=NULL)
        {
            if (i->next->name==d){break;}
            i=i->next;
        }       
        if (i->next->name==d){
            ll* temp;
            temp=i->next;
            i->next=temp->next;
            temp->next=NULL;
            delete temp;
        }else{
            cout<<"\nElement not present:(\n";
        }  
    }  
}

int main(){
    
    cout<<"Welcome to Students:)"<<endl;
    cout<<"1.Create \n2.Display \n3.Reverse \n4.Sort \n5.Insert \n6.Delete \n0.Exit";
    int choice;
    do{
        cout<<"Enter your choice>>";
        cin>>choice;
        switch (choice) 
        {
        case 1:{string h; cout<<"Enter Name>>>"; cin>>h; Create(h);
            break;}
        case 2:{cout<<"Elements in the list>>>";Display(); cout<<endl;
            break;}
        case 3:{cout<<"Elements from the end>>>";Reverse(); Display(); cout<<endl;
            break;}
        case 4:{cout<<"Sorted elements>>>";Sort_And_Display();
            break;}
        case 5:{cout<<"Insert element>>>"; string h; cin>>h; 
                cout<<"Enter p to mention position or otherwise to mention element:-"; char ch; cin>>ch;
                if (ch=='p')
                {
                    unsigned int pos; cout<<"enter position>>"; cin>>pos;Insert(h,"\0",pos);
                }else
                {
                    string hi; cout<<"Enter name of student to insert after>>"; cin>>hi;Insert(h,hi);
                }     
                
            break;}
        case 6:{cout<<"Enter element to delete>>>"; string h; cin>>h; Delete(h);
            break;}
        case 0: {cout<<"Visit Again :)\n";break;}

        default:cout<<"Wrong choice :(\n";
            break;
        }
    }while (choice != 0);
        
    return 0;
}



