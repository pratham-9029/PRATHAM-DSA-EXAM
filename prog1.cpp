#include<iostream>
using namespace std;

class Node{
public:
    int data; 
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;

public:

    LinkedList()
    {
        this->head = nullptr;
    }

    void InserAtFront(int data)   
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout<<"Data Succesfully Inserted From Front."<<endl;
    }

    void InsertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout<<"Data Succesfully Inserted From End."<<endl;
    }

    void InsertAtIndex(int index,int value)
    {
        if(head == nullptr)
        {
            cout<<"List is Already Empty."<<endl;
            return;
        }

        if(index == 0)
        {
            InserAtFront(value);
        }
        else
        {
            Node* newNode = new Node(value);
            Node* temp = head;
            int pos = 0;

            while(temp->next != nullptr && pos < index - 1)
            {
                temp = temp->next;
                pos++;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            cout<<value<<" inserted at index : "<<index<<endl;
        }
    }

    void DeleteAtFront()
    {
        if(head == nullptr)
        {
            cout<<"List Already Empty."<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"Deleted Succesfully."<<endl;
    }

    void DeleteAtEnd()
    {
        if(head == nullptr)
        {
            cout<<"List Already Empty."<<endl;
            return;
        }

        if(head->next == nullptr)
        {
            delete head;
            cout<<"Deleted Succesfully From End."<<endl;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        cout<<"Deleted Succesfully From End."<<endl;
        temp->next = nullptr;
    }

    void DeleteAtIndex(int index)
    {
        if(head == nullptr)
        {
            cout<<"List is Already Empty."<<endl;
            return;
        }

        if(index == 0)
        {
            DeleteAtFront();
            cout<<"Deleted At Index : "<<index<<endl;
            return ;
        }
        else
        {
            Node* temp = head;
            int pos = 0;

            while(temp->next != nullptr && pos < index - 1)
            {
                temp = temp->next;
                pos++;
            }

            Node* dlt = temp->next;
            temp->next = dlt->next;
            delete dlt;
            cout<<"Deleted at Index : "<<index<<endl;
    }

    }

    void Display()
    {
        Node* temp = head;
        cout<<"List is : ";
        while (temp != nullptr)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }cout<<"NULL"<<endl;
        
    }
};

int main()
{
    LinkedList list;
    int choice,data,index;

    do
    {
        cout<<endl<<"1. Insert From Front."<<endl;
        cout<<"2. Inser From End."<<endl;
        cout<<"3. Inser At Index."<<endl;
        cout<<"4. Delete From Front"<<endl;
        cout<<"5. Delete From End."<<endl;
        cout<<"6. Delete At Index."<<endl;
        cout<<"7. Display List"<<endl;
        cout<<endl<<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"Code Exited. "<<endl;
                break;
            case 1: 
                cout<<"Enter Data To Insert : ";
                cin>>data;
                list.InserAtFront(data);
                break;

            case 2:
                cout<<"Enter Data To Insert : ";
                cin>>data;
                list.InsertAtEnd(data);
                break;

            case 3:
                cout<<"Enter Index : ";
                cin>>index;
                cout<<"Enetr Data To Insert : ";
                cin>>data;
                list.InsertAtIndex(index,data);
                break;
            case 4:
                list.DeleteAtFront();
                break;
            case 5:
                list.DeleteAtEnd();
                break;
            case 6:
                cout<<"Enter Index : ";
                cin>>index;
                list.DeleteAtIndex(index);
                break;
            case 7:
                list.Display();
                break;
            default:
                cout<<"Invalid Index ."<<endl;
        }

    } while (choice != 0);
    
    return 0;
}