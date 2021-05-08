#include "DataInput.h"
#include "Node.h"

int main()
{
    vector<Node> node_vector;

    UpdateTask(node_vector);
    cout << "\n";
    GetTaskForDate(node_vector, "08.05.2021");
    SetTaskInFile(node_vector, "08.05.2021", 1, "написать программу");
    SetTaskInFile(node_vector, "08.05.2021", 2, "удалить репозиторий");
    cout << "\n";
    ChangePriorityInFile(node_vector, "08.05.2021", 1, "написать программу", 3);
    ChangeTextInFile(node_vector, "08.05.2021", 1, "написать программу", "закомитить в репозиторий");
    ChangeDateInFile(node_vector, "08.05.2021", 1, "закомитить в репозиторий", "09.05.2024");

    DeleteTaskInFile(node_vector, "08.05.2021", 2, "удалить репозиторий");

    GetTaskForDate(node_vector, "08.05.2021");
    GetTaskForDate(node_vector, "09.05.2024");
    return 0;
}
