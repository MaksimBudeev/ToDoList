#include "Task.h"
#include "ctest.h"

CTEST(findIndex, correct_find)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 4, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = findIndex(task_vector, "21.21.2021", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(findIndex, uncorrect_find)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 4, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = findIndex(task_vector, "21.21.2022", 4, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskDate, correct_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 4, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007", "08.07.2005");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskDate, uncorrect_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 4, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskDate(task_vector, "07.07.2007", 4, "Вернуть мой 2007", "08.07.2007");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskText, correct_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskText(task_vector, "21.21.2021", 5, "Поспать", "Поесть");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskText, uncorrect_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskText(task_vector, "21.21.2021", 1, "Поспать", "Поесть");

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskPriority, correct_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = changeTaskPriority(task_vector, "21.21.2021", 5, "Поспать", 4);

    ASSERT_EQUAL(expect, result);
}

CTEST(changeTaskPriority, uncorrect_change)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = changeTaskPriority(task_vector, "21.21.2021", 1, "Поспать", 5);

    ASSERT_EQUAL(expect, result);
}

CTEST(deleteTask, correct_delete)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 0;
    int result = deleteTask(task_vector, "21.21.2021", 1, "Поспать");

    ASSERT_EQUAL(expect, result);
}

CTEST(deleteTask, uncorrect_delete)
{
    std::vector<Task> task_vector;
    setTaskForDate(task_vector, "21.21.2021", 5, "Поспать");
    setTaskForDate(task_vector, "07.07.2007", 3, "Вернуть мой 2007");

    int expect = 1;
    int result = deleteTask(task_vector, "21.21.2021", 5, "Поспать");

    ASSERT_EQUAL(expect, result);
}
