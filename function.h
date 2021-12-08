#ifndef FUNCTION_H
#define FUNCTION_H
#include "string.h"
#include "malloc/_malloc.h"
struct node
{
    double num;
    struct node* next;
};

struct nulist
{
    node* head;
};
class function
{
private:

public:
    function();
    int Position(char str[],int& d);
    void get(nulist* &L, char st[]);
    void DelNode(struct nulist L);
    void Plus(struct nulist* a,struct nulist* b);
    void Minus(struct nulist* a,struct nulist* b);
    void Mul(struct nulist* a,struct nulist* b);
    void Devide(struct nulist* a,struct nulist* b);
    void mode(char s,nulist* A,nulist* B);
};

#endif // FUNCTION_H
