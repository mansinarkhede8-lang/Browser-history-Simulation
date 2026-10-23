
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    string url;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL;
string current = "";
stack<string> backStack, forwardStack;

void visit(string url)
{
    if (current != "")
        backStack.push(current);

    while (!forwardStack.empty())
        forwardStack.pop();

    Node *n = new Node{url, tail, NULL};

    if (tail != NULL)
        tail->next = n;
    else
        head = n;

    tail = n;
    current = url;

    cout << "Visited: " << current << endl;
}

void back()
{
    if (backStack.empty())
    {
        cout << "No previous website!\n";
        return;
    }

    forwardStack.push(current);
    current = backStack.top();
    backStack.pop();

    cout << "Current: " << current << endl;
}

void forward()
{
    if (forwardStack.empty())
    {
        cout << "No forward website!\n";
        return;
    }

    backStack.push(current);
    current = forwardStack.top();
    forwardStack.pop();

    cout << "Current: " << current << endl;
}

void showHistory()
{
    Node *temp = head;

    cout << "\nBrowser History:\n";
    while (temp != NULL)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    string url;

    do
    {
        cout << "\n--- Browser History Simulator ---\n";
        cout << "1. Visit Website\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. Show History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            visit(url);
            break;
        case 2:
            back();
            break;
        case 3:
            forward();
            break;
        case 4:
            showHistory();
            break;
        case 5:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
