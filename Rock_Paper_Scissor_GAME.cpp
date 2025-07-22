#include <iostream>
#include <conio.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>
using namespace std;
int main(){
    srand(time(0));
    string user_menu_choice;
    string user_RPS_choice;
    string choices[3] = {"rock","paper","scissor"};
    string computer_choice;
    int random;
    while (true){

        cout<<"1. Play";
        cout<<"\n2. Exit";
        cout<<"\nEnter your choice [Play,Exit] : ";
        cin>>user_menu_choice;
        transform(user_menu_choice.begin(),user_menu_choice.end(),user_menu_choice.begin(), ::tolower);//to lower case
        if (user_menu_choice != "play" && user_menu_choice != "exit"){
            cout<<"\nInvalid Input!";
            cout<<"\nPlease enter correct choice.";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            continue;
        }
        else if (user_menu_choice == "play"){
            cout<<"Loading...";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            while (true){
                random = rand() % 3;
                computer_choice = choices[random];
                cout<<"\nEnter your choice [Rock,Paper,Scissor] : ";
                cin>> user_RPS_choice;
                transform(user_RPS_choice.begin(),user_RPS_choice.end(),user_RPS_choice.begin(), ::tolower);
                if (user_RPS_choice != "rock" && user_RPS_choice != "paper" && user_RPS_choice != "scissor"){
                    cout<<"\nInvalid Input!";
                    cout<<"\nPlease enter correct choice.";
                    this_thread::sleep_for(chrono::seconds(2));
                    system("cls");
                    continue;
                }
                else if(user_RPS_choice == computer_choice){
                    cout<<"\nDraw";
                    cout<<"\nComputer choice was also \'"<<computer_choice<<"\'";
                    while (true){
                        cout<<"\n\nPress enter to go back to menu. ";
                        cin.ignore();
                        if(cin.get()!='\n'){
                            cout<<"\nInvalid input!\nPlease press enter to go back to menu";
                            continue;
                        }
                        break;
                    }
                    system("cls");
                    cout<<"\nLoading to menu...";
                    this_thread::sleep_for(chrono::seconds(2));
                    system("cls");
                    break;
                }
                else if ((user_RPS_choice == "rock" &&  computer_choice == "scissor") ||
                         (user_RPS_choice == "paper" &&  computer_choice == "rock") ||
                         (user_RPS_choice == "scissor" &&  computer_choice == "paper") ) {
                    cout<<"\nYou win!";
                    cout<<"\nComputer choice was : "<<computer_choice;
                    while (true){
                        cin.ignore();
                        cout<<"\n\nPress enter to go back to menu. ";
                        if(cin.get()!='\n'){
                            cout<<"Invalid input!\nPlease press enter to go back to menu";
                            continue;
                        }
                        break;
                    }
                    cout<<"Loading to menu...";
                    this_thread::sleep_for(chrono::seconds(2));
                    system("cls");
                    break;
                }
            }
        }
        else if (user_menu_choice == "exit"){
            system("cls");
            cout<<"\nExiting...";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            cout<<"\nGame exited successfully";
            cout<<"\nHope you enjoyed the game.";
            break;
        }
    }
    cout<<"\n\nDeveloped by Muhammad Hammad Ateeq.";
    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}