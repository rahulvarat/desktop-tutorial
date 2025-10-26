#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<string>undostack;
    stack<string>redostack;
    string document="";
    string newtext;
    int choice;
    while(true){
        cout<<"text editor"<<endl;
        cout<<"1 : make new changes"<<endl;
        cout<<"2 : undo action"<<endl;
        cout<<"3 : redo action"<<endl;
        cout<<"4 : display"<<endl;
        cout<<"5 : exit"<<endl;
        cout<<"enter the choices"<<endl;
        cin>>choice;
        cin.ignore();
        
    

    switch(choice){
        case 1:{
            undostack.push(document);
            cout<<"enter the new text"<<endl;
            getline(cin,newtext);
            document+=newtext;
            while(!redostack.empty()){
                redostack.pop();
            }
            cout<<"changes apppiled";
            break;
        }

        case 2:{
            if(undostack.empty()){
                cout<<"nothing is undo";
            }else{
            redostack.push(document);
            document=undostack.top();
            undostack.pop();

            }
            cout<<"undo is done"<<endl;
            break;

        }
        case 3:{
             if(redostack.empty()){
                cout<<"nothing is undo";
            }else{
            undostack.push(document);
            document=redostack.top();
            redostack.pop();

            }
            cout<<"undo is done"<<endl;
            break;
        }
        case 4:{
            cout<<"current document state"<<endl;;
            if(document.empty()){
                cout<<"empty";
            }else{
                cout<< document <<endl;
            }
            break;
        }
        case 5:{
            cout<<" existing....";
            return 0;
        }
        default:{
            cout<<"invalid choice";
            break;
        }
    }
}
}