#include<iostream>
#include<queue>
using namespace std;
 
class call{
    public:
    int customerid;
    int calltime;

    call(int id,int time){
        customerid=id;
        calltime=time;
    }

};

class callcenter{
    private:
    queue<call>callqueue;

    public:
    void addcall(int id,int time){
        call c(id,time);
        callqueue.push(c);
        cout<<"add customer id :"<<id<<" :time :"<<time<<endl;
    }

    
    void answercall(){
        if(callqueue.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }else{
            call c=callqueue.front();
            callqueue.pop();
            cout<<"answer call :"<<c.customerid<<endl;
        }

    }
    void viewqueue(){
        if(callqueue.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
            queue<call>temp=callqueue;
            cout<<"....view queue..."<<endl;
            call c=temp.front();
            while(!temp.empty()){
            cout<<"customer id: "<<c.customerid<<"call time"<<c.calltime<<endl;
            temp.pop();
        }
        cout<<"......................"<<endl;

        }

    
    void queueempty(){
        if(callqueue.empty()){
            cout<<"queue is empty";
        }
        cout<<"queue not empty";

    }

};
int main(){
    callcenter center;
    center.addcall(101,6);
    center.addcall(105,8);
    center.addcall(107,4);
    center.viewqueue();

    center.answercall();
    center.viewqueue();
    center.queueempty();

}