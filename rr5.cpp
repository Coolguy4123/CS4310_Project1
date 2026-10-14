
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::vector<int> jobs;
    std::ifstream file("test5.txt");
    int val;
    std::queue<int> q;
    const int TIME_SLICE = 5;

    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return 1;
    }

    while (file >> val) {
        jobs.push_back(val);
    }

    std::vector<int> remaining = jobs;
    for (int i = 0; i < jobs.size(); i++) {
        q.push(i);
    }

    int curr_time = 0, total_time = 0, cnt = 0;

    while (!q.empty()) {
        int indx = q.front();
        q.pop();

        int start_time = curr_time;

        int burst_duration = std::min(TIME_SLICE, remaining[indx]);

        curr_time += burst_duration;
        remaining[indx] -= burst_duration;

        int end_time = curr_time;

        std::cout << "Job " << indx + 1
                  << " | Start: " << start_time
                  << " | End: " << end_time
                  << " | Burst time: " << burst_duration
                  << " | Remaining time: " << remaining[indx]
                  << "\n";

        if (remaining[indx] > 0) {
            q.push(indx);
        } else {
            total_time += curr_time;
            cnt++;
        }
    }

    double avg_time = static_cast<double>(total_time) / cnt;

    std::cout << "RR 5 Average Turnaround Time: "
              << avg_time << " ms\n";

    return 0;
}
