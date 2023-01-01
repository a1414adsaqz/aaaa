#include <iostream> 
using namespace std;

class Hotel 
{
    private:
    struct Node
    {
        int id, date ;
        string name , roomtype ;
        Node *next;
    };

    public:
    Node* head=NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
    void list();
};

void Hotel :: menu()
{
    P:
    int choice;
    cout<<"\n";
    cout<<"\tWelcome To Hotel Management System Application" <<endl;
    cout<<"\n\t _______Hotel Management System_______";
    cout<<"\n\nS.No     Functions                           Description"<<endl;
    cout<<"\n1\tAllocate Room\t\t\tInsert New Room";
    cout<<"\n2\tSearch Room\t\t\tSearch Room With Room Id";
    cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout<<"\n4\tDelete Room\t\t\tDelete Room With Room Id";
    cout<<"\n5\tShow Room Records\t\tShow Room Records that We Added";
    cout<<"\n6\tExit"<<endl;

    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    
    switch (choice){
        case 1:
        insert();
        menu();
        break;
            
        case 2:
        search();
        menu();
        break;

        case 3:
        update();
        menu();
        break;

        case 4:
        del();
        menu();
        break;

        case 5:
        sort();
        show();
        menu();
        break;

        case 6:
        exit(0);

        default:
          cout<<"invalid";
        }
        
}

void Hotel::insert(){

    P:
    cout << "\n\t____Hotel Mangement System____";
    Node* new_Node = new Node;
    cout << "\nEnter Room ID " << endl;
    cin>> new_Node->id;
    cout << "\nEnter Customer Name " << endl;
    cin>> new_Node->name;
    cout << "\nEnter Allocated Date " << endl;
    cin>> new_Node->date;
    cout << "\nEnter Room Type(single/double/twist) " << endl;
    cin>> new_Node->roomtype;

    if(head == NULL){
        head = new_Node;

    }else{
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_Node;
    }
    cout << "\n\n\t\t New Room Inserted";

}

void Hotel::search(){

    P:
    cout << "\n\t____Hotel Mangement System____";
    int t_id;
    if(head == NULL){
        cout << "\n\nLinked List Is Empty";

    }else{
        cout << "\n\nRoom ID";
        cin>> t_id;
        Node* ptr = head;
        while(ptr != NULL){
            if(t_id == ptr->id){
                cout << "\n\nRoom ID "<<ptr->id;
                cout << "\n\nCustomer Name "<<ptr->name; 
                cout << "\n\nAllocated Date "<<ptr->date; 
                cout << "\n\nRoom Type "<<ptr->roomtype;  
            }
            ptr = ptr->next;
        }
    }
    

}

void Hotel::update(){

    P:
    cout << "\n\t____Hotel Mangement System____";
    int t_id;
    if(head == NULL){
        cout << "\n\nLinked List Is Empty";

    }else{
        cout << "\n\nRoom ID";
        cin>> t_id;
        Node* ptr = head;
        while(ptr != NULL){
            if(t_id == ptr->id){
                cout<< "\n\nRoom ID";
                cin>>ptr->id;

                cout<< "\n\nCustomer Name";
                cin>>ptr->name;

                cout<< "\n\nAllocated date";
                cin>>ptr->date;

                cout<< "\n\nRoom Type";
                cin>>ptr->roomtype;

                cout << "\n\n\t\t Update Record Successfully";
            }
            ptr = ptr->next;
        }
    }

}

void Hotel::del()
{
    cout << "\n\t____Hotel Mangement System____";
    int t_id;
    if(head == NULL){
        cout << "\n\nLinked List Is Empty";
    }else{
        cout << "\n\nRoom ID";
        cin>> t_id;
        if(t_id  == head->id){
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Delete Room Record Successfully\n";
        }else{
            Node* pre = head;
            Node* ptr = head;
            while(ptr != NULL){
                if(t_id == ptr->id){
                    pre->next = ptr->next;
                    delete ptr;
                cout << "Delete Room Record Successfully\n";
                break;    
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }

}

void Hotel::show(){
    Node* ptr = head;
    while(ptr != NULL){
        cout << "\nRoom ID "<<ptr->id;
        cout << "\nCustomer Name "<<ptr->name;
        cout << "\nAllocated Date "<<ptr->date;
        cout << "\nRoom Type "<<ptr->roomtype;
        ptr = ptr->next;
    }
}

void Hotel::sort(){
    if(head == NULL){
        cout << "\n\nLinked List Is Empty";
        menu();
    }

    int count = 0, t_date, t_id;
    string t_name, t_roomtype;
    Node* ptr = head;
    while(ptr!= NULL){
        count++;
        ptr = ptr->next;
    }
    for(int i = 1; i < count; i++){
        Node* ptr = head;
        for(int j = 1; j < count; j++){
            if(ptr->id > ptr->next->id){

                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;

                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;

                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->roomtype = t_roomtype;

            }
            ptr = ptr->next;
        }
    }
}

int main(){
    Hotel Done;
    Done.menu();
    
}