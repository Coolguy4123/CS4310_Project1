#include <iostream>
#include <random>
#include <vector>

//RNG Generator
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

    std::cout << "Generated " << JOB_NUM << " jobs\n";
    std::cout << "Job times: ";
    for (int job : jobs) {
        std::cout << job << " ";
    }
    std::cout << "\n";

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

    std::cout << "FCFS Average Turnaround Time: " << avg_time << " ms\n";

    return 0;
}
