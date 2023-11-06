#include<iostream>
using namespace std;




class base_datastructure{
    public:
        int front;
        int end;
        int arr[100];
        int startpoint;
        int controler;

       void display(){
        for(int i=startpoint;i>=0 && i<=end;i=i+controler){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
       }
       void top(){
            cout<<"Top Element is: "<<arr[startpoint]<<"\n \n";
       }
       
};



class stack: public base_datastructure{
    public:
    stack(void){
        end=99;
        startpoint=-1;
        controler=-1;
    }
    void push(int x){
        arr[++startpoint]=x;
    }
    int pop(){
        if(startpoint==-1){
            cout<<"Empty";
            return -1;
        }
        else{
            startpoint--;
            return arr[startpoint+1];
        }
    }
    void operator+=(int param){
            push(param);

       }
    void operator-=(int param){
            while(param){
                pop();
                param--;
            }

       }
    friend ostream& operator <<(ostream& o,stack rian);

    



};
class queue: public base_datastructure{
    public:
    queue(void){
        front =-1;
        end=-1;
        startpoint=-1;
        controler=1;
    }
    void push(int x){
        if(front==-1){
            startpoint=0;
            front=0;
        } 
        arr[++end]=x;
        
    }
    int pop(){
        if(front!=-1 && end+1==front){
            cout<<"Empty";
            return -1;
        }
        else{
            front++;
            startpoint++;
            return arr[front-1];
        }
    }
    void operator+=(int param){
            push(param);

       }
    void operator-=(int param){
            while(param){
                pop();
                param--;
            }

       }
    friend ostream& operator <<(ostream& o,queue rian);
};

typedef struct node{
    int val;
    node* next;
}node;

class linkedlist: public base_datastructure{
    private:
    
    node* rear;

    public:
    node* head;
    linkedlist(void){
        head = (node*)malloc(sizeof(node));
        rear=NULL;
        head->next=NULL;
    }
    node* create(int x){
        node* temp= (node*)malloc(sizeof(node));
        temp->next=NULL;
        temp->val=x;
    }

    void push(int x){
        node* temp = create(x);
        if(rear==NULL){
            head->val = x;
            rear=head;

        }
        else{
            rear->next =temp;
            rear=rear->next;
        }
        
    }

    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;

        }
        cout<<"NULL";
    }
    void operator+=(int param){
            push(param);

       }
    bool operator==(linkedlist rian){
            node* temp1 =rian.head;
            node* temp2=head;
            while(temp1!=NULL && temp2!=NULL){
                if(temp1->val!=temp2->val){
                    return 0;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if(temp1==NULL ^ temp2==NULL){
                return 0;
            }
            else{
                return 1;
            }
            

    }
    node* operator+(linkedlist rian){
        node* temp1 =rian.head;
        node* temp2=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next= temp2;
        return head;
    }
    friend ostream& operator <<(ostream& o,linkedlist rian);

};

ostream &operator <<(ostream&o,linkedlist rian){
    rian.display();
}


ostream &operator <<(ostream&o,stack rian){
    rian.display();
}

ostream &operator <<(ostream&o,queue rian){
    rian.display();
}


int main(){

    stack s;
    queue q;
    for (int i = 1; i <= 5; i++) {
        s+=i;
        q+=i;
    }
    cout<<"Stack: ";
    s.display();
    s.top();
    cout<<"Queue: ";
    q.display();
    q.top();

    s-=1;
    q-=1;

    cout<<"After 1 Pop: \n";
    cout<<"Stack: ";
    cout<<s;
    s.top();
    cout<<"Queue: ";
    cout<<q;
    q.top();

    cout<<"Linked List 1"<<endl;
    linkedlist rian;
    for(int i=10;i<=100;i+=10){
        rian.push(i);
    }
    cout<<rian<<endl;
    cout<<"Linked List 2"<<endl;
    linkedlist shane;
    for(int i=100;i>=10;i-=10){
        shane.push(i);
    }
    cout<<shane<<endl;
    cout<<"Linked List 3"<<endl;
    linkedlist pinto;
    for(int i=10;i<=100;i+=10){
        pinto.push(i);
    }
    cout<<pinto<<endl<<endl;
    if(rian==shane){
        cout<<"Linked Lists 1 & 2 are equal"<<endl;
    }
    else{
        cout<<"Linked Lists 1 & 2 are Unequal"<<endl;
    }
    if(rian==pinto){
        cout<<"Linked Lists 1 & 3 are equal"<<endl;
    }
    else{
        cout<<"Linked Lists 1 & 3 are Unequal"<<endl;
    }
    rian+pinto;
    cout<<"Concatenating 1 and 3"<<endl;
    cout<<pinto<<endl;


   
    



}

