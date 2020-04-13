#include "Recorder.h"
#include <iostream>
Recorder::Recorder() {
        std::vector<std::string> availableDevices = sf::SoundRecorder::getAvailableDevices();

    // choose a device
    std::string inputDevice = availableDevices[1];

    // create the recorder

    // set the device
    recorder.setDevice(inputDevice);
   
}

void Recorder::start() {
    recorder.start();
    std::cout<<"recording..."<<std::endl;
}
void Recorder::stop() {
    recorder.stop();
        std::cout<<"stopped..."<<std::endl;

}
void Recorder::save() {
    s.setBuffer(recorder.getBuffer());
    s.play();
    std::cout<<"playing..."<<std::endl;
    
}