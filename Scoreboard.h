#include "IScoreboard.h"
#include <vector>
#include <climits>
#include "ObserverPattern.hpp"
using namespace std;

class Scoreboard: public IScoreboard, public Observable {
  public:
    Scoreboard(int competitor_count, int period_count);
    void setScore(int competitor, int period, int score);
    int getScore(int competitor, int period);
    int getTotalScore(int competitor);
    void clearScoreboard();
  private:
    vector< vector<int> > m_scoreboard;
    bool validateIndex(int, int);
    int m_competitor_count;
    int m_period_count;
    int count;
    int periods;
   // int teams;
    int score;
};

