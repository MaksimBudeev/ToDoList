#include "ctest.h"
#include "Task.h"

CTEST(findIndex, correct_find)
{
    std::vector<Task> task_vector;
	setTaskForDate(node_vector, "21.21.2021",4, "Поспать");
	setTaskForDate(node_vector, "07.07.2007",3, "Вернуть мой 2007");

    int expect = 0;
    int result = findIndex(task_vector, "21.21.2021", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(findIndex, uncorrect_find)
{
    std::vector<Task> task_vector;
	setTaskForDate(node_vector, "21.21.2021",4, "Поспать");
	setTaskForDate(node_vector, "07.07.2007",3, "Вернуть мой 2007");

    int expect = 1;
    int result = findIndex(task_vector, "21.21.2022", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}
