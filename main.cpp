#include <bits/stdc++.h>
#include <string>
using namespace std;
class Node
{
public:
    string key;
    Node**next;
    Node(string val,int level);
};
Node::Node(string val, int level)
{
    this->key=val;
    next=new Node*[level+1];
    memset(next,0,sizeof(Node*)*(level+1));
}
class SkipList
{
    int maxlvl;
    float p;
    int lvl;
    Node *header;
public:
    SkipList(int x, float p);
    int randomLevel();
    Node* createNode(string key,int level);
    void insertElement(string key);
    void display();
    int searchElement(string key);
    void deleteElement(string key);
};
SkipList::SkipList(int MAXLVL,float P)
{
    this->maxlvl=MAXLVL;
    this->p=P;
    lvl=0;
    header=new Node("",MAXLVL);
}
Node* SkipList::createNode(string key, int level)
{
    Node *n=new Node(key,level);
    return n;
}
int SkipList::randomLevel()
{
    float r=(float)rand()/RAND_MAX;
    int lvl=0;
    while(r<p&&lvl<maxlvl)
    {
        lvl++;
        r=(float)rand()/RAND_MAX;
    }
    return lvl;
}
void SkipList::insertElement(string key)
{
    Node *current=header;
    Node *update[maxlvl+1];
    memset(update, 0, sizeof(Node*)*(maxlvl+1));
    for(int i=lvl; i>=0; i--)
    {
        while(current->next[i]!=NULL&&current->next[i]->key<key)
            current=current->next[i];
        update[i]=current;
    }
    current=current->next[0];
    if(current==NULL||current->key!=key)
    {
        int rlevel=randomLevel();
        if(rlevel>lvl)
        {
            for(int i=lvl+1; i<rlevel+1; i++)
                update[i]=header;
            lvl=rlevel;
        }
        Node* n=createNode(key,rlevel);
        for(int i=0; i<=rlevel; i++)
        {
            n->next[i]=update[i]->next[i];
            update[i]->next[i]=n;
        }
    }
}
void SkipList::display()
{
    Node *node=header->next[0];
    while(node)
    {
        cout<<node->key<<" ";
        node=node->next[0];
    }
        cout<<endl;
}
int SkipList::searchElement(string key)
{
    Node *help=header;
    for(int i=lvl; i>=0; i--)
    {
        while(help->next[i]&&help->next[i]->key<key)
            help=help->next[i];
    }
    help=help->next[0];
    if(help&&help->key==key)
        return 1;
    return 0;
}
void SkipList::deleteElement(string key)
{
    Node *help=header;
    Node*update[maxlvl+1];
    memset(update,0,sizeof(Node*)*(maxlvl+1));
    for(int i=lvl;i>=0;i--)
    {
        while(help->next[i]!=NULL&&help->next[i]->key<key)
            help=help->next[i];
        update[i]=help;
    }
    help=help->next[0];
    if(help&&help->key==key)
    {
        for(int i=0;i<=lvl;i++)
        {
            if(update[i]->next[i]==help)
            update[i]->next[i]=help->next[i];
        }
        while(lvl>0&&header->next[lvl]==0) lvl--;
    }
}
int main()
{
    srand((unsigned)time(0));
   SkipList mylist(10,0.5);
    int ok=1,n;
    string x;
    do
    {
    cout<<endl<<"Welcome to Malina's program! Please choose what would you like to do"<<endl;
    cout<<"1 - reserve a ticket"<<endl<<"2 - cancel a reservation"<<endl<<"3 - check whether you have a reservation"<<endl<<"4 - display all the reservations"<<endl<<"5 - exit";
    cout<<endl<<"Enter a number:";cin>>n;
    switch(n)
    {
    case 1:
        cout<<endl;
        cout<<"Please enter your name:";cin>>x;
        if(mylist.searchElement(x)==0) mylist.insertElement(x);
        else cout<<"You already have a reservation!"<<endl;
        break;
    case 2:
        cout<<endl;
        cout<<"Please enter your name:";
        cin>>x;
        if(mylist.searchElement(x)==0) cout<<"You do not have a reservation!"<<endl;
            else mylist.deleteElement(x);
        break;
    case 3:
        cout<<endl;cout<<"Please enter your name:";
        cin>>x;
        if(mylist.searchElement(x)) cout<<"You have a reservation!"<<endl;
        else cout<<"You do not have a reservation"<<endl;
        break;
    case 4:
        cout<<endl;
        mylist.display();
        cout<<endl;
        break;
    case 5:
        ok=0;
        break;
    default:
        ok=0;
    }
    }while(ok);


    return 0;
}
