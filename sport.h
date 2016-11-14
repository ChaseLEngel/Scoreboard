#include "IScoreboard.h"
#include <vector>
#include <climits>

using namespace std;

class Sport: public IScoreboard {
  public:
    Sport(int competitor_count, int period_count);
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
    int teams;
    int score;
};

Sport::Sport(int competitor_count, int period_count) {
  m_scoreboard.resize(competitor_count, vector<int>(period_count, 0));
  m_competitor_count = competitor_count;
  m_period_count = period_count;
}

bool Sport::validateIndex(int competitor, int periods) {
  if(competitor > m_competitor_count || competitor <= 0) {
    return false;
  }
  if(periods > m_period_count || periods <= 0) {
    return false;
  }
  return true;
}

void Sport::setScore(int competitor, int period, int score) {
  if(!validateIndex(competitor, period)) { return; }
  m_scoreboard[competitor][period] = score;
}

int Sport::getScore(int competitor, int period) {
  if(!validateIndex(competitor, period)) { return INT_MIN; }
  return m_scoreboard[competitor][period];
}

int Sport::getTotalScore(int competitor) {
  int total = 0;
  for(auto period : m_scoreboard[competitor]) {
    total += period;
  }
}

void Sport::clearScoreboard() {
  m_scoreboard.clear();
}
