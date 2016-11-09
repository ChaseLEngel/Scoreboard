#include "IScoreboard.h"
#include <vector>

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
}

Sport::Sport(int competitor_count, int period_count) {
  m_scoreboard.resize(competitor_count, vector<int>(period_count, 0));
  m_competitor_count = competitor_count;
  m_period_count = period_count;
}

bool Sport::validateIndex(int competitor, int periods) {
  if(competitor > competitor_count || competitor <= 0) {
    return false;
  }
  if(period > period_count || period <= 0) {
    return false;
  }
  return true;
}

void Sport::setScore(int competitor, int period, int score) {
  if(!validateIndex) { return; }
  m_scoreboard[competitor][period] = score;
}

int Sport::getScore(int competitor, int period) {
  if(!validateIndex) { return; }
  return m_scoreboard[competitor][period];
}

int getTotalScore(int competitor) {
  int total = 0;
  for(auto period : m_scoreboard[competitor]) {
    total += period;
  }
}

void clearScoreboard() {
  m_scoreboard.clear():
}

int main() {
  Sport s = Sport(2, 4);
  return 0;
}
