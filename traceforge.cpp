#include <iostream>
#include <string>
using namespace std;

struct Event
{
    int id;        // event id number
    string action; // what happened
    Event *next;   // address of the next event
};

void appendEvent(Event *&head, int id, string action)
{
    // create a new node
    Event *newEvent = new Event;

    // store the event information
    newEvent->id = id;
    newEvent->action = action;
    newEvent->next = nullptr;

    // check if the event are empty or not?
    if (head == nullptr)
    {
        head = newEvent;
        return;
    }
    // Start from the first event
    Event *current = head;

    // check the last event and connect it with the new one
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newEvent;
}

void displayEvent(Event *head)
{
    Event *current = head;
    if (head == nullptr)
    {
        cout << " Nothing in the event list to display." << endl;
        return;
    }

    while (current != nullptr)
    {
        cout << current->id << " " << current->action << " " << '\n';
        current = current->next;
    }
}
void searchEvent(const Event *head, int target_id)
{
    if (head == nullptr)
    {
        cout << "Nothing in the event list to searech !";
        return;
    }
    // start from the first event
    const Event *current = head;

    // check the event exists or not
    while (current != nullptr)
    {
        // check if the current id is matched with the targeted_id or not?
        if (current->id == target_id)
        {
            // print the event if found
            cout << "Targeted id has been found !" << endl;
            cout << current->id << " "
                 << current->action << endl;
            return;
        }
        current = current->next;
    }
    cout << "Invalid id !" << endl;
}

void destroyEvent(Event *&head)
{
    while (head != nullptr)
    {
        Event *temp = head;
        head = head->next;
        delete temp;
    }
}
void deleteEvent(Event *&head, int target_id)
{
    // An empty list has nothing to delete.
    if (head == nullptr)
    {
        cout << " Cannot delete the event list is empty !" << endl;
        return;
    }
    // Handle deletion of the first event separately.
    if (head->id == target_id)
    {
        // Save the first event and move head to the next event.
        Event *temp = head;
        head = head->next;
        // Print the deleted event's information
        cout << "Deleted Event: " << temp->id
             << " " << temp->action << endl;
        delete temp;
        return;
    }
    Event *current = head;
    // Stop at the event before the target, or at the end of the list.
    while (current->next != nullptr &&
           current->next->id != target_id)

    {
        current = current->next;
    }
    if (current->next != nullptr)
    {
        // save the address of the event we want to delete
        Event *temp = current->next;
        // Connect around the target before freeing its memory.
        current->next = temp->next;
        cout << "Deleted Event: " << temp->id
             << " " << temp->action << endl;
        delete temp;
    }
    else
    {
        cout << "Invalid id to delete :" << target_id << " " << endl;
    }
}

int main()
{
    // create the head pointer and initilize it as empty
    Event *head = nullptr;
    int choice;
    int id;
    string action;

    cout << "=============== Welcome to Traceforge Program ====================" << endl;
    cout << "================= Event Tracking System ==========================" << endl;
    do
    {
        cout << "\n ========== Traceforge Main Menu ========== " << endl;
        cout << " ============================================ " << endl;
        // Display the avaliable options in the menu
        cout << "\n 1.Add the event. " << endl;
        cout << "\n 2.Display the event. " << endl;
        cout << "\n 3.Search the event. " << endl;
        cout << "\n 4.Delete the event. " << endl;
        cout << "\n 5.Destroy the all Event." << endl;
        cout << "\n 6. Exit. " << endl;
        cout << "----------------------------------------------------------------" << endl;
        // Ask the user to select the avaliable Choice
        cout << "\n Enter your choice (1 to 6): ";
        if (!(cin >> choice))
        {
            cin.clear();

            cin.ignore(1000, '\n');
            cout << "Event ID must be a number !" << endl;
            continue;
        }
        else
        {
            cout << " Valid choice " << endl;
        }
        // display all the menu
        if (choice == 1)
        {
            cout << " \nEnter the Id (numbers):";
            cin >> id;

            cout << "\nEnter the action(alphabetics) :";
            cin >> ws;
            getline(cin, action);

            appendEvent(head, id, action);

            cout << "Sucessfully Added : " << " ";
            displayEvent(head);
        }
        else if (choice == 2)
        {
            displayEvent(head);
        }

        else if (choice == 3)
        {
            cout << "\n Enter the ID to search :"; // ask user the id
            cin >> id;

            // call the search function
            searchEvent(head, id);
        }

        else if (choice == 4)
        {
            cout << "Enter the ID to delete :";
            cin >> id;
            // call the delete funtion to delete specific id
            deleteEvent(head, id);
        }

        else if (choice == 5)
        {
            destroyEvent(head);
            if (head == nullptr)
            {
                cout << "Successfully deleted the linked list." << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "================= EXITING TRACEFORGE ======================" << endl;
        }
        else
        {
            cout << " Invalid choice ! * Try again from 1 to 6 *" << endl;
        }
    } while (choice != 6);

    destroyEvent(head);
    return 0;
}
