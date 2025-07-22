#include <iostream>
#include <conio.h>
#include <random>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;
int score = 0;
void print_score_label() {
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << "Score : 0";
}


int numberOFrounds(){
    int rounds = 0;
    while(true){
        rounds = 0;
        cout<<"Enter number of rounds you want to play (MAX : 10):  ";
        cin>>rounds;
        if(cin.fail()){
            cout << "Invalid input! Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (rounds > 10 || rounds < 1){
            cout<<"\nMaximum number of rounds could be 1-10.\n";
            continue;
        }
        break;
    }
    return rounds;
}
void update_score_number() {
    COORD coord;
    coord.X = 8; // right after "Score : "
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << score << "  ";  // Extra spaces to clear previous digits
    coord.X = 0; // right after "Score : "
    coord.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//User Menu Choice.
string get_menu_choice(){
    string menu_choice;
    while (true){
        cout<<"1. Play\n2. Exit\nEnter your choice [Play,Exit] : ";
        cin>>menu_choice;
        transform(menu_choice.begin(),menu_choice.end(),menu_choice.begin(), ::tolower);
        if (menu_choice != "play" && menu_choice != "exit"){
            cout<<"\n\nInvalid Input!!!";
            cout<<"\nPlease enter correct choice.";
            this_thread::sleep_for(chrono::seconds(3));
            system("cls");
            continue;
        }
        break;
    }
    system("cls");
    return menu_choice;
}
//User Choice.
string get_user_choice(){
    string user_choice;
    while (true){
        cout<<"Enter your choice [Rock,Paper,Scissor] : ";
        cin>>user_choice;
        transform(user_choice.begin(),user_choice.end(),user_choice.begin(), ::tolower);
        if (user_choice != "rock" && user_choice != "paper" && user_choice != "scissor"){
            cout<<"\nInvalid Input!!!";
            cout<<"\nPlease enter correct choice.";
            this_thread::sleep_for(chrono::seconds(3));
            system("cls");
            continue;
        }
        break;
    }
    return user_choice;
}
//Computer Choice
string get_computer_choice(){
    string choices[3] = {"rock","paper","scissor"};
    string computer_choice;
    int random;
    random = rand() % 3;
    return computer_choice = choices[random];
}
//Choosing Winner
string winner(string user_choice,string computer_choice){
    if (user_choice == computer_choice){
        return "Draw";
    }
    else if ((user_choice == "rock" &&  computer_choice == "scissor") ||
             (user_choice == "paper" &&  computer_choice == "rock") ||
             (user_choice == "scissor" &&  computer_choice == "paper") ){
        score++;
        update_score_number();
        return "You win!";
    }
    else {
        return "Computer Wins.";
    }
}
int main(){
    srand(time(0));
    while (true){    
        string menu_choice = get_menu_choice();
        if (menu_choice == "play"){
            cout<<"Loading...";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            int number_of_rounds = numberOFrounds();
            int current_round=1;
            while (number_of_rounds > 0){
                system("cls");
                cout<<"Loading...";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
                print_score_label();
                cout<<"\n====== Round  "<<current_round<<" ======\n";
                string user_choice = get_user_choice();
                string computer_choice = get_computer_choice();
                cout << "You chose: " << user_choice << endl;
                cout << "Computer chose: " << computer_choice << endl;
                string result = winner(user_choice, computer_choice);
                update_score_number();
                cout << "Result: " << result << endl;
                if (number_of_rounds != 1){
                    cout<<"Round "<<current_round+1<<" will start in ";
                    for (int i=5;i>=1;i--){
                        cout<<i<<" ";
                        this_thread::sleep_for(chrono::seconds(1));
                    }
                }
                current_round++;
                number_of_rounds--;
            }
            while (true){
                cout<<"\n\nPress enter to go back to menu.";
                cin.ignore();
                if (cin.get() != '\n'){
                    cout<<"Invalid Input!!!";
                    cout<<"\nPlease press enter."<<endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                }
                system("cls");
                cout<<"Loading back to menu...";
                this_thread::sleep_for(chrono::seconds(3));
                system("cls");
                break;
            }
        }
        else if (menu_choice == "exit"){
            system("cls");
            cout<<"Exiting...";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            cout<<"Developed By Muhammad Hammad Ateeq";
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }
    }

    return 0;
}
