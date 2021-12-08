#include "function.h"

function::function(){}

int function::Position(char str[],int& d)
{
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='+') {d=1;return i;}
        else if(str[i]=='-') {d=-1;return i;}
    }
    return -1;
}

void function::get(nulist* &L,char st[])
{
    //char st[100];
    int flag1=1,flag2=1;
    //scanf("%s",st);
    char str[100];
    if(st[0]=='-'){
        flag1=-1;
        strcpy(str,st+1);
    }
    else strcpy(str,st);
    int pos = Position(str,flag2);
    double& f = L->head->num;
    double& s = L->head->next->num;
    int len = strlen(str);
    if(str[0]=='0') f=0,s=0;
    else if(pos==-1){
        if(str[len-1]=='i'){
            int p = -1;
            double num=0;
            for(int i=pos+1;i<len-1;i++){
                if(str[i]=='.') p=i;
                else num*=10,num+=str[i]-'0';
            }
            if(p!=-1){
                while(++p<len-1) num/=10;
            }
            s = num?num:1;
            s*=flag2;
        }
        else{
            int p = -1;
            double num=0;
            for(int i=0;i<len;i++){
                if(str[i]=='.') p=i;
                else num*=10,num+=str[i]-'0';
            }
            if(p!=-1){
                while(++p<len) num/=10;
            }
            f = num*flag1;
        }
    }
    else{
        int p = -1;
        double num=0;
        for(int i=0;i<pos;i++){
            if(str[i]=='.') p=i;
            else num*=10,num+=str[i]-'0';
        }
        if(p!=-1){
            while(++p<pos) num/=10;
        }
        f = num*flag1;
        num=0;
        for(int i=pos+1;i<len-1;i++){
            if(str[i]=='.') p =i;
            else num*=10,num+=str[i]-'0';
        }
        if(p!=-1){
            while(++p<len-1) num/=10;
        }
        s = num?num:1;
        s*=flag2;
    }
}


void function::DelNode(struct nulist L)
{
    struct node* p=L.head,*q=p->next;
    while(q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

void function::Plus(struct nulist* a,struct nulist* b)
{
    struct node* p=a->head,*q=b->head;
    double s,x;
    s=q->num;
    x=q->next->num;
    p->num+=s;
    p->next->num+=x;
    DelNode(*b);
}
void function::Minus(struct nulist* a,struct nulist* b)
{
    struct node* p=a->head,*q=b->head;
    double s,x;
    s=q->num;
    x=q->next->num;
    p->num-=s;
    p->next->num-=x;
    DelNode(*b);
}
void function::Mul(struct nulist* a,struct nulist* b)
{
    struct node* p=a->head,*q=b->head;
    double s1,s2,x1,x2;
    s1=p->num;
    x1=p->next->num;
    s2=q->num;
    x2=q->next->num;
    p->num=s1*s2-x1*x2;
    p->next->num=s1*x2+s2*x1;
    DelNode(*b);
}
void function::Devide(struct nulist* a,struct nulist* b)
{
    struct node* p=a->head,*q=b->head;
    double s1,s2,x1,x2;
    s1=p->num;
    x1=p->next->num;
    s2=q->num;
    x2=q->next->num;

    double m = s2 * s2 + x2 * x2;
    p->num = (s1 * s2 + x1 * x2) / m;
    p->next->num = (x1 * s2 - s1 * x2) / m;
    DelNode(*b);
}


void function::mode(char s,nulist* A,nulist* B)
{
    switch(s){
        case '+':Plus(A,B);break;
        case '-':Minus(A,B);break;
        case '*':Mul(A,B);break;
        case '/':Devide(A,B);break;
    }
}
