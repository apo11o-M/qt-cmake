#include <iostream>
#include <thread>

void sdr_thread() {
    while (true) {
        // TODO: generate data every 1 second, pass that data to a tcp port
        std::cout << "SDR thread running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
