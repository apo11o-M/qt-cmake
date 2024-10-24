#include <iostream>
#include <thread>

#include "qt/entry.h"
#include "sdr/entry.h"

int main(int argc, char *argv[]) {
    std::thread gui(qt_thread, std::ref(argc), argv);
    std::thread sdr(sdr_thread, "../../gen_data/ffts_NFFT=16384_N=20.32f");

    gui.join();
    sdr.join();
}
