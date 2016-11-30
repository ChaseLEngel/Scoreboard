#include "Scoreboard.h"

Scoreboard::Scoreboard(int competitor_count, int period_count) {
  m_scoreboard.resize(competitor_count, vector<int>(period_count, 0));
  m_competitor_count = competitor_count;
  m_period_count = period_count;
}

bool Scoreboard::validateIndex(int competitor, int periods) {
  if(competitor > m_competitor_count || competitor <= 0) {
    return false;
  }
  if(periods > m_period_count || periods <= 0) {
    return false;
  }
  return true;
}

void Scoreboard::setScore(int competitor, int period, int score) {
  if(!validateIndex(competitor, period)) { return; }
  m_scoreboard[competitor-1][period-1] = score;
  notifyObservers();
}

int Scoreboard::getScore(int competitor, int period) {
  if(!validateIndex(competitor, period)) { return INT_MIN; }
  return m_scoreboard[competitor-1][period-1];
}

int Scoreboard::getTotalScore(int competitor) {
  int total = 0;
  for(auto period : m_scoreboard[competitor-1]) {
    total += period;
  }
  return total;
}

void Scoreboard::clearScoreboard() {
  m_scoreboard.clear();
  notifyObservers();
}
