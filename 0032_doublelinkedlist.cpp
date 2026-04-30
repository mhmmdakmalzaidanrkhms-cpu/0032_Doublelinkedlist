// 4NimBelakang_DoubleLinkedList
#include <iostream>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *newNode = new Node();
        newNode->noMhs = nim;

        // Insert di awal
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed\n";
                return;
            }

            newNode->next = START;
            if (START != NULL)
                START->prev = newNode;

            newNode->prev = NULL;
            START = newNode;
            return;
        }

        // Cari posisi
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed\n";
            return;
        }

        // Insert tengah / akhir
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        int rollNo;
        cout << "\nEnter roll number to delete: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found\n";
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current;
        cout << "Record deleted\n";
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        Node *current = START;
        cout << "\nAscending order:\n";

        while (current != NULL)
        {
            cout << current->noMhs << " ";
            current = current->next;
        }
        cout << endl;
    }

    void revTraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        Node *current = START;
        while (current->next != NULL)
            current = current->next;

        cout << "\nDescending order:\n";
        while (current != NULL)
        {
            cout << current->noMhs << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        int rollNo;
        cout << "\nEnter roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
            cout << "Record not found\n";
        else
            cout << "Record found\n";
    }
};

