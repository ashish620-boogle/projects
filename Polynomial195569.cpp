#include<bits/stdc++.h>
using namespace std;

struct polynomial{
    int coeff,exp;
    polynomial *next;
};
polynomial *p3=NULL;

void Create(int exp, int coeff, polynomial **top){
    if (*top==NULL)
    {
        polynomial *temp;
        temp=new polynomial;
        temp->coeff=coeff;
        temp->exp=exp;
        temp->next=NULL;
        *top=temp;
        temp=NULL;
    }else
    {
        polynomial *i=*top;
        while (i->next!=NULL){
            i=i->next;
        }    
        polynomial *temp;
        temp=new polynomial;
        temp->coeff=coeff;
        temp->exp=exp;
        temp->next=NULL;
        i->next=temp;
        temp=NULL;
        i=NULL;
    }   
}

void Display(polynomial *top){
    
    if (top==NULL)
    {
        cout<<"Underflow :("<<endl;
    }else
    {
        polynomial *i=top;
        while (i!=NULL)
        {   
            if(i->coeff > 0)
            cout<<i->coeff<<"x^"<<i->exp;
            else cout<<(-1)*i->coeff<<"x^"<<i->exp;
            if (i->next==NULL)
            {
                cout<<"=0"<<endl;
            }else
            {
                if(i->next->coeff>0)
                cout<<" + ";
                else cout<<" - ";
            }
            i=i->next;
        }
    }
}


void Sort(polynomial **top){
    if (*top==NULL){}
    else
    for (polynomial* i = *top; i->next != NULL; i=i->next)
    {
        for (polynomial* j = i->next; j != NULL; j=j->next)
        {
            if (i->exp < j->exp)
            {
                swap(i->exp, j->exp);
                swap(i->coeff, j->coeff);
                
            }else if (i->exp == j->exp)
            {
                i->coeff+=j->coeff;
                polynomial *temp=j;
                j->coeff=0;
                j->exp=0;
            }
              
        }   
    }

    for (polynomial* i = *top; i->next != NULL; i=i->next)
    {
        if (i->next->coeff==0)
        {
            polynomial *temp=i->next;
            i->next=NULL;
            delete temp;
            return;
        } 
    }  
}


void Subtract(polynomial *p1, polynomial *p2){
    
    Sort(&p1); Sort(&p2);
    for (polynomial *j = p1, *i = p2; j != NULL || i != NULL;)
    {
        if (i!=NULL && j!=NULL)
        {
            if (j->exp==i->exp)
            {
                Create(i->exp, j->coeff - i->coeff, &p3);
                j=j->next; i=i->next;
            }else if (j->exp > i->exp && j!=NULL)
            {
                Create(j->exp, j->coeff, &p3);
                j=j->next;
            }else if (j->exp < i->exp)
            {
                Create(i->exp, (i->coeff*(-1)), &p3);
                i=i->next;
            }

        }else if (j!=NULL){
            Create(j->exp, j->coeff, &p3);
            j=j->next;
        }else if (i!=NULL)
        {
            Create(i->exp, (i->coeff*(-1)), &p3);
            i=i->next;
        }
            
    }   
}

void Product(polynomial *p1, polynomial *p2){
    
    for (polynomial *i = p1; i != NULL; i=i->next)
    {
        for (polynomial *j = p2; j != NULL; j=j->next)
        {
            Create(j->exp+i->exp, j->coeff * i->coeff, &p3);               
        }
    }
    Sort(&p3);
}


int main(){

    polynomial *p1=NULL, *p2=NULL;
    Create(5,7,&p1); Create(2,7,&p2); Create(5,6,&p1); Create(6,8,&p1);Create(4,9,&p2); Create(1,2,&p2);
    
    cout<<"\np1:";
    Display(p1);
    cout<<"\np2:";
    Display(p2);
    cout<<"\n Product(p1*p2)>>>\n";
    Product(p1,p2);
    Display(p3);

    polynomial *temp=p3;
    p3=NULL;
    delete temp;

    cout<<"\n Difference>>>\n";
    Subtract(p1,p2);
    Display(p3);
    delete p3;

    return 0;
}