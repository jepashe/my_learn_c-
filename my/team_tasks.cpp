#include <iostream>
#include <string>
#include <map>
#include <tuple>


using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    TasksInfo task_info_person = users.at(person);
    return task_info_person;
  };
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
    TasksInfo new_task_person = {
      {TaskStatus::NEW, 1},
      {TaskStatus::IN_PROGRESS, 0},
      {TaskStatus::TESTING, 0},
      {TaskStatus::DONE, 0}
    };
    users[person] = new_task_person;
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);

private:
  map<string, TasksInfo> users;
};

void PrintTaskInfo(TasksInfo task_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main(){
  
  map<string, TasksInfo> m = {{"Pavel", {{TaskStatus::NEW, 1},
	  {TaskStatus::IN_PROGRESS, 2},
	  {TaskStatus::TESTING, 3},
	  {TaskStatus::DONE, 4}
  }}};

	//TaskInfo task_info = {{TaskStatus::NEW, 3}, {TaskStatus::IN_PROGRESS, 4}, {TaskStatus::TESTING, 2}, {TaskStatus::DONE, 4}};

	//PrintTaskInfo(task_info);

  

	
	return 0;
}
