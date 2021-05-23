#include "DataInput.h"
#include "Task.h"

void changeStringInFile(std::vector<Task>& taskVector, size_t index, Operation type)
{
    //добавление новой задачи
    if (type == Operation::Add) {
        std::fstream storage("storage.txt", std::ios::app);
        storage << taskVector[index].getDate() << " " << std::to_string(taskVector[index].getPriority()) << " " << taskVector[index].getText() << std::endl;
        storage.close();
        return;
    }

    std::string temp;
    std::vector<std::string> cache;
    std::fstream storage("storage.txt", std::ios::in);
    while (getline(storage, temp)) {
        cache.push_back(temp);
    }
    storage.close();

    //изменение
    if (type == Operation::Edit) {
    for (const auto& str : taskVector) 
    std::cout << str.getText() << std::endl;
        cache[index] = taskVector[index].getDate() + " " + std::to_string(taskVector[index].getPriority()) + " " + taskVector[index].getText();
    }
    //удаление
    if (type == Operation::Delete) {
        cache.erase(cache.begin() + index);
    }
    //заполнение вектора
    if (type == Operation::Read) {
        std::stringstream ss;
        std::string date, priority, text;
        for (const auto& taskStr : cache) {
            ss.str(taskStr);
            ss >> date >> priority;
            ss.get();
            getline(ss, text);
            setTaskForDate(taskVector, date, stoi(priority), text);
        }
        return;
    }
    
    storage.open("storage.txt", std::ios::out);
            if (storage.is_open())
        {
            std::copy(cache.begin(), cache.end(), 
                std::ostream_iterator<std::string>(storage, "\n"));
            storage.close();
        }
}

