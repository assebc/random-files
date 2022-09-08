#include <iostream>
#include <string>
#include <list>

using namespace std;

class TodoItem{

    private:
        int id;
        string description;
        bool completed;

    public:
        TodoItem() : id(0), description(""), completed(false){}
        ~TodoItem() = default;

        bool create(string new_description){
            id = rand() % 100 + 1;
            description = new_description;
            return true;
        }

        // setters
        void setId(int id){ id = id; };
        void setDescription(string desc){ description = desc; };
        void setCompleted(bool b){ completed = b; };

        // getters
        int getId(){ return id; };
        string getDescription(){ return description; };
        bool isCompleted(){ return completed; };

};

int main(){

    list<TodoItem> todoItems;
    list<TodoItem>::iterator it;
    todoItems.clear();
    
    while(1){

        char input;
        int input_id;
        string input_desc;

        system("cls");
        system("clear");
        cout << "TODO List Maker" << endl;
        cout << endl << endl;

        for(it = todoItems.begin(); it != todoItems.end(); it++){

            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | " << completed << endl;
        }

        if(todoItems.empty())
            cout << "Add your first TODO!" << endl;


        cout << endl;
        cout << "[a]dd a new TODO" << endl;
        cout << "[c]omplete a TODO" << endl;
        cout << "[r]emove a TODO" << endl;
        cout << "[q]uit" << endl;   

        cout << endl << "choice ";
        cin >> input;
        cout << endl;
        
        if(input=='a'){
            cout << "Add a new description: " << endl;
            cin.clear();
            cin.ignore();
            getline(cin, input_desc);

            TodoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
        } else if(input == 'c'){
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for(it = todoItems.begin(); it!= todoItems.end(); it++)
                if(input_id == it->getId()){
                    it->setCompleted(true);
                    break;
                }
        } else if(input == 'r'){
            cout << "Enter id to remove: ";
            cin >> input_id;

            for(it = todoItems.begin(); it!= todoItems.end(); it++)
                if(input_id == it->getId()) todoItems.erase(it);
                
        } else if(input == 'q') cout << "Have a nice day!" << endl;
        else cout << "Invalid input" << endl;          
    }
};