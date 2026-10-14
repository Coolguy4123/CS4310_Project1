#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> jobs;

    std::ifstream file("test5.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return 1;
    }

    int val;
    while (file >> val) {
        jobs.push_back(val);
    }

    // Sort for SJF
    sort(jobs.begin(), jobs.end());

    int curr_time = 0, total_time = 0, cnt = 0;

    for (int i : jobs) {
        int start_time = curr_time;

        curr_time += i;

        int end_time = curr_time;

        std::cout << "Job " << cnt + 1
                  << " | Start: " << start_time
                  << " | End: " << end_time
                  << " | Burst time: " << i
                  << "\n";

        total_time += curr_time;
        cnt++;
    }

    double avg_time = static_cast<double>(total_time) / cnt;

    std::cout << "SJF Average Turnaround Time: " << avg_time << " ms\n";

    return 0;
}
