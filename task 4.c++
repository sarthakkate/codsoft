//************ TASK--4 *****************//

/*Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.
*/


#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist
{
  int id;
  string task;
};

 int ID = 0;
void banner();
void addTask();
void viewTask();
int searchTask();
void removeTask();
void completedTask();

int main()
{
    system("cls");
    while(true)
    {
        banner();
        cout<<"\n\t1.Add Task";
        cout<<"\n\t2.View Task";
        cout<<"\n\t3.Search Task";
        cout<<"\n\t4.Remove Task";
        cout<<"\n\t1.Marks Task as Completed";

          int choice;
          cout<<"\n\tEnter Choise";
          cin>> choice;
          switch (choice)
          {
            case 1 :
            addTask();
            break;

            case 2 :
            viewTask();
            break;

            case 3 :
            searchTask();
            break;

            case 4 :
            removeTask();
            break;

            case 5 :
            completedTask();
            break;

            default:
              break;       
          }
    }
return 0 ;    
}


void banner()
{
  cout<<"________________________________"<<endl;
  cout<<"\t To Do List"<<endl;
  cout<<"________________________________"<<endl;
}

void addTask()
{
  system("cls");
  banner();
  todolist todo;
  cout<<"Entre new task"<<endl;
  cin.get();
  getline(cin, todo.task);
  char save;
  cout<<"Save? (Y/N)";
  cin >> save;
  if (save=='Y')
  {
    ID++;
    ofstream fout;
    fout.open("todo.txt",ios::app);
    fout<<"\n"<< ID;
    fout<<"\n"<<todo.task;
    fout.close();

    char more;
    cout<<"Add more task? (Y/N)";
    cin>>more;
    if (more == 'Y')
    {
      addTask();
    }
    else
    {
      system("cls");
      cout<<"Added successfully"<<endl;
      return;

    }
  }
  system("cls");
}
void viewTask()
{
  system("cls");
  banner();
  todolist todo;
  ifstream fin;
  fin.open("todo.txt");
  cout<<"Task"<<endl;

  while(!fin.eof())
  {
    fin>>todo.id;
    fin.ignore();
    getline(fin, todo.task);
    if(todo.task!="")
    {
      cout<<"\t"<< todo.id <<":"<<todo.task<<endl;
    }
    else
    {
      cout<<"\tEmpty!"<<endl;
    }
  }
  fin.close();
  char exit;
  cout<<"Exit? (Y/N)";
  cin >> exit;
  if (exit != 'Y')
  {
    viewTask(); 
  }
  system("cls");
}

int searchTask()
{
  system("cls");
  banner();
  int id;
  cout<<"Enter task id";
  cin>> id;
  todolist todo;
  ifstream fin("todo.txt");
  while (!fin.eof())
  {
    fin>> todo.id;
    fin.ignore();
    getline(fin,todo.task);
    if(todo.id== id)
    {
      system("cls");
      cout<< "\t"<<todo.id<<":"<<todo.task<< endl;
      return id;
    }
  }
  system("cls");
  cout<< "Not Found!"<< endl;
  return 0;
}
void removeTask()
{
  system("cls");
  int id = searchTask();
  if (id !=0)
  {
    char remov;
    cout<<"\n\tDelete? (Y/N)";
    cin >> remov;
    if(remov == 'Y')
    {
      todolist todo;
      ofstream tempfile;
      tempfile.open("todo.txt");
      ifstream fin;
      fin.open("todo.txt");
      int index = 1;
      while (!fin.eof())
      {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id != id)
        {
          tempfile <<"\n" << index;
          tempfile <<"\n" <<  todo.task;
          index++;
          ID--;
        }
      }
      fin.close();
      tempfile.close();
      remove("todo.txt");
      rename("temp.txt","todo.txt");
      system("cls");
      cout<<"\n\tRemove Successfully!"<<endl;
    }
    else{
      system("cls");
      cout<<"Not Remove!"<<endl;
    }
  }
}

void completedTask()
{
  system("cls");
  banner();
  int id = searchTask();
  if (id != 0)
  {
    char markcomplete;
    cout << "\n\tMark as completed? (Y/N)";
    cin>>markcomplete;
    if(markcomplete == 'Y')
    {
      todolist todo;
      ifstream fin("todo.txt");
      ofstream tempfile("temp.txt");

      while (!fin.eof())
      {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);

        if(todo.id == id)
        {
          tempfile << todo.id << "\n";
          tempfile << todo.task <<"(completed)\n";
        }
        else
        {
          tempfile << todo.id << "\n";
          tempfile << todo.task << "\n";
        }
      }
      fin.close();
      tempfile.close();
      remove("todo.txt");
      rename("temp.txt","todo.txt");

      system("cls");
      cout<<"\n\tNot Marked as Completed" << endl;
    }
  }
}
