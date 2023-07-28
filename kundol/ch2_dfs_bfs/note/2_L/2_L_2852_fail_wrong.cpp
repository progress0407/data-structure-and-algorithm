#include <bits/stdc++.h>

using namespace std;

int n; // 골 횟수 (0..104)

int team_1_score;
int team_2_score;

int team1_tot_sec;
int team2_tot_sec;

int sec; // 주의 가변변수

struct WinHistory {
    int team; // 1 or 2 or 0(동점)
    int timeSec; // 시각 정보를 초로 환산한 것
};

vector<WinHistory> winHistories;

void convertTime(string& timeStr) {

    int minute = stoi(timeStr.substr(0, 2));
    sec = stoi(timeStr.substr(3));

    sec = minute*60 + sec;
}

string innerShow(int t) {

    // if(t< 10) {
        // if (t == 0) {
            // return "00";
        // } else {
            // return "0" + t;
        // }
    // } else {
        // return to_string(t);
    // }

    return t<10? (t == 0? "00" : "0" +t) : to_string(t);
}

string show(int t) {
    int m = t / 60;
    int s = t % 60;

    string m_str = innerShow(m);
    string s_str = innerShow(s);

    return m_str + ":" + s_str;
}

void calcWinHistories() {

    if(winHistories.empty()) {
        if(team_1_score > team_2_score) {
            winHistories.push_back({1, sec});
        } else if(team_1_score < team_2_score) {
            winHistories.push_back({2, sec});
        } else {
            winHistories.push_back({0, sec});
        }
    } else {

        int lastTeam = winHistories.back().team;

        if(team_1_score > team_2_score) {
            if(lastTeam != 1) {
                winHistories.push_back({1, sec});
            }
        } else if (team_1_score < team_2_score) {
            if(lastTeam != 2) {
                winHistories.push_back({2, sec});
            }
        } else { // 동점
            if(!winHistories.empty() && lastTeam != 0) {
                winHistories.push_back({0, sec});
            }
        }
    }
}

void calcWinScore() {

    int prevTeam = 0;
    int prevSec = 0;

    for(auto& e : winHistories) {
        if (e.team == 1) {
            prevTeam = 1;
        } else if (e.team == 2) {
            prevTeam = 2;
        } else if(e.team == 0) {
            int time_duration = e.timeSec - prevSec;
            if(prevTeam == 1) {
                team1_tot_sec += time_duration;
            } else if (prevTeam == 2) {
                team2_tot_sec += time_duration;
            }
            prevTeam = 0;
        }
        prevSec = e.timeSec;
    }
}

void calcWinScore2() {
    
    int size = winHistories.size();
    for (int i = 1; i < size; i++)
    {
        auto before = winHistories[i-1];
        auto current = winHistories[i];

        int timeDuration = current.timeSec - before.timeSec;
        if(before.team == 1 && current.team == 0) {
            team1_tot_sec += timeDuration;
        } 
        else if(before.team == 2 && current.team == 0) {
            team2_tot_sec += timeDuration;
        }
    }
}


int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // input
        int teamNo;
        string timeInput;
        cin >> teamNo >> timeInput;
        convertTime(timeInput);

        if(teamNo == 1) team_1_score++;
        else team_2_score++;

        calcWinHistories();
    }

    winHistories.push_back({0, 48 * 60});

    calcWinScore2();
    
    // for(auto& e : winHistories) 
        // cout << e.team << ":: " 
            // << e.timeSec/60 << " : " << e.timeSec % 60 << '\n';

    cout << show(team1_tot_sec) << "\n";
    cout << show(team2_tot_sec) << "\n";

    return 0;
}
