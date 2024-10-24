#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

#include "../config.h"

void sdr_thread(std::string dataFilename) {
    std::ifstream fin(dataFilename, std::ios::binary);
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << dataFilename << std::endl;
        return;
    }
    std::vector<float> fftAbs(FFT_SIZE);

    while (true) {
        for (int i = 0; i < FFT_SIZE; i++) {
            float f;
            fin.read(reinterpret_cast<char *>(&f), sizeof(float));
            fftAbs[i] = f;
        }

        // send data through tcp socket

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
