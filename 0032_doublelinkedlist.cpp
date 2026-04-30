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

       