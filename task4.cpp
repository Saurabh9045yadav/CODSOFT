#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::remove_if

using namespace std;

// 1. Define a structure to hold task details
struct Task {
    int id;
    string description;
    bool isCompleted;
};

// Global vector to store all tasks
vector<Task> tasks;
int nextId = 1; // Used to assign a unique ID to each new task

// --- FUNCTION PROTOTYPES ---

// 2. Add Task Function
void addTask(const string& description) {
    Task newTask;
    newTask.id = nextId++;
    newTask.description = description;
    newTask.isCompleted = false; // Initially, all tasks are pending
    tasks.push_back(newTask);
    cout << "Task #" << newTask.id << " added: " << description << endl;
}

// 3. View Tasks Function
void viewTasks() {
    if (tasks.empty()) {
        cout << "\n--- Your To-Do List is Empty! ---" << endl;
        return;
    }

    cout << "\n--- Current To-Do List ---\n";
    for (const auto& task : tasks) {
        string status = task.isCompleted ? "[COMPLETED]" : "[PENDING]";
        cout << task.id << ". " << status << " " << task.description << endl;
    }
    cout << "--------------------------\n";
}

// 4. Mark Task as Completed Function
void markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.isCompleted = true;
            cout << "Task #" << id << " marked as COMPLETED." << endl;
            return;
        }
    }
    cout << "Error: Task with ID " << id << " not found." << endl;
}

// 5. Remove Task Function
void removeTask(int id) {
    // Using erase-remove idiom to safely remove an element from a vector
    auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& t) {
        return t.id == id;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task #" << id << " successfully removed." << endl;
    } else {
        cout << "Error: Task with ID " << id << " not found." << endl;
    }
}

// --- MAIN MENU AND LOGIC ---
int main() {
    int choice;
    int taskId;
    string description;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer after reading an integer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: // Add Task 
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(description);
                break;
            case 2: // View Tasks 
                viewTasks();
                break;
            case 3: // Mark Completed [cite: 61]
                cout << "Enter the ID of the task to mark as completed: ";
                cin >> taskId;
                markTaskCompleted(taskId);
                break;
            case 4: // Remove Task [cite: 62]
                cout << "Enter the ID of the task to remove: ";
                cin >> taskId;
                removeTask(taskId);
                break;
            case 0: // Exit
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}