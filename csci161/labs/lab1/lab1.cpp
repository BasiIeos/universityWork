#include <iostream>

using namespace std;

// Data
struct Record {
    int id;
    string name;
};

// Linked List
struct Node {
    Record *data;
    Node *next;
};

Node *createEmptyList()
{
    Node *list = new Node;
    list->next = 0;
    return list;
}

// read user input and create a new data record
Record *readData()
{
    string restOfLine;
    Record *data = new Record;
    cout << "Please enter the id: ";
    cin >> data->id;
    getline(cin, restOfLine);
    cout << "Please enter the name: ";
    getline(cin, data->name);
    return data;
}

void insert(Node *list, Record *data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = list->next;
    list->next = ptr;
}

void display(Node *list)
{
    Node *ptr = list->next;
    while (ptr != 0)
    {
        cout << "id: " << ptr->data->id << "; name: " << ptr->data->name << ";" << endl;
        ptr = ptr->next;
    }
}

char userCmdInput()
{
    char c;
    cin >> c;
    return c;
}

void deleteList (Node *list)
{
    list = list->next;
    Node *ptr;
    while (list != 0)
    {
        ptr = list;
        list = list->next;
        delete ptr->data;
        delete ptr;
    }
}

int main()
{
    Record *data;
    Node *list = createEmptyList();
    char cmd;
    cmd = userCmdInput();
    while (cmd != 'T')
    {
        if (cmd == 'E')
        {
            data = readData();
            insert(list, data);
        }
        else
            display(list);
        cmd = userCmdInput();
    }
    deleteList(list);
    return 0;
}
