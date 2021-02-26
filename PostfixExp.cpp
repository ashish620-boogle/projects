#include<bits/stdc++.h>
using namespace std;

union intchar{
    int a; char b;
};

int main(){

    string s;
    cout<<"Enter the postfix exp in form of variables(operators=+,-,*,/,%,^,|,&,!)>>>";
    cin>>s;
    stack <intchar> eval;
    
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'){
            intchar d; d.b=s[i];
            eval.push(d);
        }else {
            intchar b = eval.top();
            eval.pop();
            intchar a = eval.top();
            eval.pop();
            int ainteger,binteger;

            ainteger=isalpha(a.b)?0:a.a;
            binteger=isalpha(b.b)?0:b.b;

            if(isalpha(a.b)){
            cout<<"Enter value of "<<a.b<<"=";
            cin>>ainteger;}if(isalpha(b.b)){
            cout<<"enter value of "<<b.b<<"=";
            cin>>binteger;}
            switch(s[i]){
                case '+':{ainteger+=binteger; break;}
                case '-':{ainteger-=binteger; break;}
                case '*':{ainteger=ainteger * binteger; break; }
                case '/':{if(binteger!=0) ainteger/=binteger; else cout<<"Error!"<<endl; break;}
                case '%':{if(binteger!=0) ainteger%=binteger; else cout<<"Error!"<<endl; break;}
                case '^':{ainteger=pow(ainteger,binteger); break;}
                case '!':{binteger=!binteger; intchar k; k.a=ainteger; eval.push(k); ainteger=binteger; break;}
                case '|':{ainteger=ainteger|binteger;break;}
                case '&':{ainteger=ainteger&binteger;break;}
                default : break;
            }
            intchar d; d.a=ainteger;
            eval.push(d);
        }
    }
    
    cout<<eval.top().a<<endl;
    return 0;
}