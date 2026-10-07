// Large code

#include <iostream>
using namespace std;

struct Node
{
    int id;
    string itemName;
    int quantity;
    string status;
    Node* next;
};

Node* head = NULL;

// Add a new e-waste record
void addRecord()
{
    Node* newNode = new Node;

    cout << "Enter E-Waste ID: ";
    cin >> newNode->id;

    cout << "Enter Item Name: ";
    cin >> newNode->itemName;

    cout << "Enter Quantity: ";
    cin >> newNode->quantity;

    cout << "Enter Recycling Status: ";
    cin >> newNode->status;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Record added successfully!\n";
}

// Display all records
void displayRecords()
{
    if (head == NULL)
    {
        cout << "No records available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- E-Waste Records ---\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id << endl;
        cout << "Item: " << temp->itemName << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "Status: " << temp->status << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
}

// Search a record
void searchRecord()
{
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nRecord Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Item: " << temp->itemName << endl;
            cout << "Quantity: " << temp->quantity << endl;
            cout << "Status: " << temp->status << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Record not found.\n";
}

// Update recycling status
void updateRecord()
{
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter new recycling status: ";
            cin >> temp->status;

            cout << "Record updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Record not found.\n";
}

// Delete a record
void deleteRecord()
{
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
            {
                head = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }

            delete temp;

            cout << "Record deleted successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "Record not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== E-WASTE COLLECTION SYSTEM =====\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addRecord();
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                searchRecord();
                break;

            case 4:
                updateRecord();
                break;

            case 5:
                deleteRecord();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
