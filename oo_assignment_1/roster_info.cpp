#include <iostream>
#include "Roster.h" 

using namespace std;
int main()
{
    const int starting_lineup = 5;
    int jersey_number;
    int rating, updated_rating, filter_rating;
    Roster* report = new Roster();


    //Populate the inital roster
    std::cout << "Input the initial team of 5 players. Jersey # first"<<std::endl;
    for (int i = 0; i < starting_lineup; i++)
    {
        std::cout << "Enter the jersey number for player #" <<i+1<<std::endl;
        cin >> jersey_number;
        std::cout << "Enter the rating for player #" <<i+1<<std::endl;
        cin >> rating;
        report->AddPlayer(jersey_number, rating);
    }

    //Input loop for roster management
    bool valid_input = true;
    do 
    {
        char input;
        std::cout << "Type 'A' to add a player, 'R' to remove a player, 'U' to update player rating, 'P' to print the roster, 'F' for a filtered print, and  to quit" << std::endl;
        cin >> input;
        if ((input == 'A') or (input == 'a'))
        {

            std::cout << "Add Player mode:" << std::endl;
            std::cout << "Enter the player's jersey number" << std::endl;
            std::cin >> jersey_number;
            std::cout << "Enter the player's rating" << std::endl;
            std::cin >> rating;
            report->AddPlayer(jersey_number, rating);
        }
        else if ((input == 'R')or(input=='r'))
        {
            int jersey_number;
            std::cout << "Remove Player mode:" << std::endl;
            std::cout << "Enter the the jersey number of the player you would like to remove" << std::endl;
            std::cin >> jersey_number;
            report->RemovePlayer(jersey_number);
        }
        else if((input=='U') or (input=='u'))
        {
            std::cout << "Update Player rating mode:" << std::endl;
            std::cout << "Enter the the jersey number of the player whose rating is to be updated:" << std::endl;
            std::cin >> jersey_number;
            std::cout << "Enter the player's updated rating" << std::endl;
            std::cin >> updated_rating;
            report->UpdateRating(jersey_number, updated_rating);
        }
        else if ((input=='F') or (input =='f'))
        {
            std::cout << "Filtered print mode:" << std::endl;
            std::cout << "Enter the minimum player rating for which you want to filter against" << std::endl;
            cin >> filter_rating;
            report->FilteredPrint(filter_rating);
        }
        else if((input=='P')or(input=='p'))
        {
            std::cout << "Print roster:" << std::endl;
            report->PrintRoster();
        }
        else
        {
            valid_input = false;
        }
    } while (valid_input);
    
    delete report;
}