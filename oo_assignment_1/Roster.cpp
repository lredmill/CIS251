#include "Roster.h"
#include <iostream>


Roster::Roster()
{

}

void Roster::AddPlayer(int jersey_number, int rating)
{
    std::pair<int,int> new_player;
    new_player.first = jersey_number;
    new_player.second = rating;
    m_activeRoster.push_back(new_player);
}

void Roster::RemovePlayer(int jersey_number)
{
    int index = - 1;
    int cnt = 0;
    for (auto player : m_activeRoster)
    {
        if (jersey_number==player.first)
        {
            index = cnt;
            break;
        }
        cnt++;
    }

    m_activeRoster.erase(m_activeRoster.begin()+index);
}

void Roster::PrintRoster()
{
    for (auto player : m_activeRoster)
    {
        std::cout << "Player #" << player.first << " has a rating of " << player.second << std::endl;
    }
}

void Roster::UpdateRating(int jersey_number, int new_rating)
{
    for (auto &player : m_activeRoster)
    {
        if (player.first == jersey_number)
        {
            player.second = new_rating;
            break;
        }
    }
}

void Roster::FilteredPrint(int min_rating)
{
    for (auto player : m_activeRoster)
    {
        if (player.second >= min_rating)
        {
            std::cout << "Player #" << player.first << " has a rating of " << player.second << std::endl;
        }
    }
}