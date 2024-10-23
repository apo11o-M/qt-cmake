#include <iostream>
#include <thread>

#include "qt/entry.cpp"
#include "sdr/entry.cpp"

int main(int argc, char *argv[]) {
    std::thread gui(qt_thread);
    std::thread sdr(sdr_thread);

    gui.join();
    sdr.join();
}
