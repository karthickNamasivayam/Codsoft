#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\n===== To-Do List Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
}

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n===== Your Tasks =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        const string status = tasks[i].completed ? "Completed" : "Pending";
        cout << i + 1 << ". " << tasks[i].description << " - " << status << endl;
    }
}

void deleteTask(vector<Task>& tasks, size_t taskIndex) {
    if (taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        displayMenu();
        int choice;

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                viewTasks(tasks);
                size_t taskIndex;
                cout << "Enter the task index to delete: ";
                cin >> taskIndex;
                deleteTask(tasks, taskIndex - 1);
                break;
            }
            case 4:
                cout << "Exiting the to-do list manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        system("clear");
    }

    return 0;
}