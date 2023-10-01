//************ TASK--1 *****************//

/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
    srand(time(nullptr));
    int target_number = rand() % 100 + 1;
    int guess = 0;
    int attempts =0;

    cout<<"Welcome to the Number Guessing Game"<<endl;

    while(true)
    {
        cout << "Guess the number (between 1 and 100)"<<endl;
        cin >> guess;
        attempts++;

        if (guess == target_number)
        {
            cout << "Congratulations! You guessed the number\n " << target_number << " correctly in " << attempts << " attempts." << endl;
            break;
        }
        else if(guess < target_number)
        {
            cout << "Too low. Try again" << endl;
        }
        else
        {
            cout << "Too high. Try again." << endl;
        }
    }
    return 0;
}


//************ TASK--2 *****************//

/*Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform*/

#include <iostream>

using namespace std;

int main()
{
    float num1,num2,result;
    char operation;

    cout<<"Entre First Number"<<endl;
    cin>>num1;


    cout<<"Entre An Operation(+,-*,/)"<<endl;
    cin>>operation;

    cout<<"Entre Second Number"<<endl;
    cin>>num2;

    switch(operation)
    {
        case '+':
            result=num1 + num2;
            cout<<"Result"<<num1<<"+"<<num2<<"="<<result<<endl;
            break;
        case '-':
            result=num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } 
            else 
            {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }
    return 0;
}


//************ TASK--3 *****************//

/*Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other

Game Board: Create a 3x3 grid as the game board.
Players: Assign
"X"
and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player
'
s move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between
"X"
and "O"
players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game
*/


#include<iostream>
using namespace std;

class TicTacToe {
  public:

  void createBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++){
      for(int j =0; j<3; j++){
        board [i][j]=' ';
      }
    }
  }
  void printBoard(char board[3][3]){
    cout<< "\n\nCurrent Board : \n";
    for(int i = 0;i < 3; i++){
      cout << "\n --- --- --- \n";
      for (int j=0;j<3;j++){
        cout<<" | " << board[i][j];
      }
      cout << " | ";
    }
    cout<<"\n --- --- --- \n";
  }

  int checkboard(char board[3][3], char x){
    for (int i = 0;i < 3; i++){
      if((board [i][0] == x) && (board[i][1] == x) && (board[i][2] == x)){
        if (x =='X')return 1;
        else return 2;
    }
    else if((board[0][i]==x) &&(board[1][i]==x) && (board[2][i]==x)) {
      if (x =='X')return 1;
      else return 2;
    }
  }
  if ((board[0][0]==x) &&(board[1][1]==x) &&(board[2][2]==x)){
    if (x =='X')return 1;
    else return 2;
  }
  return 0;
}
};

int main(){
  char board[3][3],choice;
  int r,c;
  TicTacToe t;

  while (1){
    cout<<"\n>>> Tic-Tac-Toe <<<\n";
    cout<<" 'X' assigned to player 1";
    cout<<" 'O' assigned to player 2";
    t.createBoard(board);
    t.printBoard(board);

    for (int i = 1; i <= 9; i++){
      if(i%2 != 0){
        cout << "\nPlayer 1 : Enter Position Of X ";
        cin>>r>>c;
        board[r-1][c-1]='X';
        if(t.checkboard(board,'X')==1){
           t.printBoard(board);
           cout<<"\n>>> Congratulations, Player 1! You won the game!<<<\n";
           cout<<"\nUp for another game?(Y/N)";
           cin >> choice;
           if (choice == 'Y' || choice == 'y') main();
           else exit(0);
        }
      }
      else{
        cout<<"\nPlayer 2: Entre Position of O ";
        cin>>r>>c;
        board[r-1][c-1]='O';
        if(t.checkboard(board,'O')==2){
           t.printBoard(board);
           cout<<"\n>>> Congratulations, Player 2! You won the game!<<<\n";
           cout<<"\nUp for another game?(Y/N)";
           cin >> choice;
           if (choice == 'Y' || choice == 'y') main();
           else exit(0);
      }
    }
    t.printBoard(board);
  }
  cout << "\n >>> Match Drawn <<<\n";
  cout << " \nUp for another game? (Y/N)";
  if (choice == 'Y' || choice =='y')main();
  else exit(0);
}
}


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