#include<iostream>
using namespace std;
typedef struct Node{
string name;
bool final=0;
Node* zeroinp=NULL;
Node* oneinp=NULL;
}state;

class dfa{
public:
    state q0,q1;
   Node* presentstate=&q0;
    dfa(){
    q0.name="q0";
    q0.zeroinp=&q0;
    q0.oneinp=&q1;

    q1.name="q1";
    q1.zeroinp=&q0;
    q1.oneinp=&q1;
    q1.final=1;
    }

    bool check(string input){
    for(int i=0;i<input.length();i++){
        char c=input[i];

        if(c =='0'){
            presentstate=presentstate->zeroinp;
        }
        if(c =='1'){
            presentstate=presentstate->oneinp;
        }
    }
    cout << "Final state: " << presentstate->name << endl;
        return presentstate->final;
    }
};
int main(){
dfa d;
string input;
cout<<"Enter string:";
cin>>input;

bool n=d.check(input);
if(n == 1){
    cout<<"accept";
}
else
    cout<<"not accept";
}

