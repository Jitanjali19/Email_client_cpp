#include<iostream>
#include<vector>
#include<string>
using namespace std;

class attachment{
    public:
    
    string filename;
    string content;
    
    attachment(string filename,string content){
       this-> filename=filename;
        this->content=content;
    }
            
        
};

class Email{
    public:
    string sender;
    string receiver;
    string subject;
    string body;
    
    vector<attachment>Attachment;
    bool read;
    
    Email(string sender,
    string receiver,
    string subject,
string body,vector<attachment>Attachment={}){
        this->sender=sender;
        this->receiver=receiver;
        this->subject=subject;
        this-> body= body;
        Attachment={};
        read=false;
    }
    
    void markAsRead(){
        read=true;
    }
    
    void display(){
        cout<<"from:"<<sender<<"\nto:"<<receiver<<"\nsubject:"<<subject<<"\n\n"<<body<<"\n";
    }
};

class folder{
    public:
    string name;
    vector<Email>emails;
    
    folder(string name){
        this->name=name;
    }
    
    void addEmail(Email email){
        emails.push_back(email);
        
    }
    void displayEmails(){
        for(auto& email: emails){
            email.display();
            cout<<"----------------\n";
        }
    }
};

void sendEmail(string sender,string receiver,
string subject,string body,vector<attachment>Attachment,folder &inbox,folder &sent){
        Email email(sender ,receiver,subject,body,Attachment);
        inbox.addEmail(email);
        sent.addEmail(email);
        cout<<" Email sent from "<<sender<<" to "<<receiver<<"\n";
    }

void receiveEmail(string sender,string receiver,string subject,string body,vector<attachment>Attachment,folder &inbox){
        Email email(sender ,receiver,subject,body,Attachment);
        inbox.addEmail(email);
       
        cout<<" Email received from "<<sender<<" to "<<receiver<<"\n";
    }
    
    
    int main(){
        folder inbox("Inbox");
        folder sent("Sent");
        folder drafts("drafts");
        
        while(true){
            cout<<"\n1.send email\n2.receive email\n3.view inbox\n4.viewsent\n5 exit\nchoose an option:";
            
            int choice;
            cin>>choice;
            cin.ignore();
            
if(choice==1){
     string sender, receiver ,subject ,body;
     
     cout<<"enter sender: ";
     getline(cin,sender);
       cout<<"enter receiver: ";
     getline(cin,receiver);
       cout<<"enter subject: ";
     getline(cin,subject);
       cout<<"enter body: ";
     getline(cin,body);
     
    sendEmail(sender ,receiver,subject,body,{},inbox,sent);
            }else if(choice==2){
  string sender ,receiver,subject,body;
            
      cout<<"enter sender: ";
     getline(cin,sender);
       cout<<"enter receiver: ";
     getline(cin,receiver);
       cout<<"enter subject: ";
     getline(cin,subject);
       cout<<"enter body: ";
     getline(cin,body);
     
    receiveEmail(sender ,receiver,subject,body,{},inbox);
            }else if(choice==3){
                cout<<"inbox: \n";
                inbox.displayEmails();
                
            }else if(choice==4){
                cout<<"sent:\n";
                sent.displayEmails();
                
            }else if(choice==5){
                break;
            }else{
                cout<<"Invalid choice.please try again.\n";
            }
        }
        return 0;
    }
