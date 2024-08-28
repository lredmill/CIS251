#include <string>
#include <vector>
#include <utility>

using namespace std;
class Roster
{
    private:
        std::vector<std::pair<int,int> > m_activeRoster;
    public:
        Roster();
        void AddPlayer(int jersey_number, int rating);
        void RemovePlayer(int jersey_number);
        void PrintRoster();
        void UpdateRating(int jersey_number, int new_rating);
        void FilteredPrint(int min_rating);
};