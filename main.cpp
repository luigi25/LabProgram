#include <iostream>
#include "Date.h"
#include "TaskList.h"
#include <vector>
#include <string>


int main() {
    char command;
    int day,month, year;
    int i=0;
    std::string target;
    Date tempDate;
    std::vector<TaskList> myAgenda;

    tempDate = Date(20, Months::July, 2018);
    TaskList taskN1("You must buy the bread!", tempDate, true);
    myAgenda.push_back(taskN1);

    tempDate = Date(22, Months::July, 2018);
    taskN1 = TaskList("You must pay the bill!", tempDate, true);
    myAgenda.push_back(taskN1);

    tempDate = Date(27, Months::July, 2018);
    taskN1 = TaskList("You must go to the bank!", tempDate, false);
    myAgenda.push_back(taskN1);
    bool finish=false;

    while (!finish) {
        std::cout<<"Insert command:"<<std::endl;
        std::cout<<"w->Insert new task"<<std::endl;
        std::cout<<"r->Read your tasks"<<std::endl;
        std::cout<<"q->Quit"<<std::endl;
        std::cin>>command;
        if(std::cin){
            switch(command){
                case 'w':
                    std::cout<<"Insert target:"<<std::endl;
                    std::cin>>target;
                    std::cout<<"Insert day:"<<std::endl;
                    std::cin>>day;
                    std::cout<<"Insert month:"<<std::endl;
                    std::cin>>month;
                    std::cout<<"Insert year:"<<std::endl;
                    std::cin>>year;
                    if(month>=1 && month<=12)
                        tempDate=Date(day,(Months)(month-1),year);
                    else
                        tempDate=Date(day,Months::January,year);
                    taskN1=TaskList(target,tempDate,false);
                    myAgenda.push_back(taskN1);
                    break;
                case 'r':
                    for(std::vector<TaskList>::iterator it=myAgenda.begin(); it!=myAgenda.end(); it++ ){
                        std::cout<<"Task:"<<i<<std::endl;
                        it->printTask();
                        i++;
                    }
                    break;
                case 'q':
                    finish=true;
                    break;
                default:
                    std::cout<<"Invalid command "<<std::endl;
                    break;
            }
        }
    }
}