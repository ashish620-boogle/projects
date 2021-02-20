#include <bits/stdc++.h>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    Element *ele;
};

Sparse* sortSparse(Sparse *s){

    for (int i = 0; i < s->m - 1; i++)
    {
        for (int j = i+1; j < s->m; j++)
        {
            if (s->ele[i].i > s->ele[j].i)
            {
                swap(s->ele[i], s->ele[j]);
            }else if (s->ele[i].i==s->ele[j].i && s->ele[i].j > s->ele[j].j)
            {
                swap(s->ele[i], s->ele[j]);
            }
                
        }  
    }
    return s;  
}

void create(Sparse *s){
    cout<<"Enter the dimensions ";
    cin>>s->m>>s->n ;
    cout<<"Number of non-zero elements>>";
    cin>>s->num;
    s-> ele= new Element[s->num];
    cout<<"Enter all non-zero elements\n";
    for (int i = 0; i< s->num; i++)
    {
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }
    s=sortSparse(s);
}
void display(Sparse* s){
    int i,j,k=0;
    for (i = 0; i < s->m; i++)
    {
        for (j = 0; j < s->n; j++)
        {
            if(i==s->ele[k].i && j== s->ele[k].j)
                cout<<s->ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<" \n";
    }
}
Sparse *createTranspose(Sparse* s){
    Sparse *t;
    t=new Sparse[s->num];
    t->m = s->n;
    t->n = s->m;
    t->num = s->num;
    t-> ele= new Element[t->num];
    for (int i = 0; i< t->num; i++)
    {
        t->ele[i].i= s->ele[i].j;
        t->ele[i].j= s->ele[i].i;
        t->ele[i].x= s->ele[i].x;
    }
    t=sortSparse(t);
    return t;
}

int main(){
    Sparse *s, *t;
    s=new Sparse;
    create(s);
    display(s);
    t=createTranspose(s);
    cout<<"Transpose of the matrix is \n";
    display(t);
    return 0;
}