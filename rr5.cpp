
#include <iostream>
#include <algorithm>
#include <random>
#include <queue>
#include <vector>

// RNG generation
std::vector<int> generateJobs(int JOB_NUM) {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(1, 20);

    std::vector<int> jobs;
    jobs.reserve(JOB_NUM);

    for (int i = 0; i < JOB_NUM; ++i) {
        jobs.push_back(distribution(generator));
    }

    return jobs;
}

int main() {
    const int JOB_NUM = 5;
    std::vector<int> jobs = generateJobs(JOB_NUM);
    std::queue<int> q;
    const int TIME_SLICE = 5;

    std::cout << "Generated " << JOB_NUM << " jobs\n";
    std::cout << "Job times: ";
    for (int job : jobs) {
        std::cout << job << " ";
    }
    std::cout << "\n";

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
