#include <iostream>
#include "function.h"

string HexInFloat(string package) {
    string info = package.substr(2,8);
    uint32_t bigEndianData = strtoul(info.c_str(),NULL,16);
    float data;
    memcpy(&data, &bigEndianData, sizeof(data));
    string data_string = to_string(data);
    return data_string;
}

void PrintResult(DataFromPNItrax dataFromPNItrax) {
    cout << "Parsing complete" << endl;
    cout << "kHeading: " <<dataFromPNItrax.kHeading << " grad" << endl;
    cout << "kPitch: " <<dataFromPNItrax.kPitch << " grad" << endl;
    cout << "kRoll: " <<dataFromPNItrax.kRoll << " grad" << endl;
    cout << "kHeadingStatus: " <<dataFromPNItrax.kHeadingStatus << endl;
    cout << "kQuaternion: [" <<dataFromPNItrax.kQuaternion[0] << ", " << dataFromPNItrax.kQuaternion[1] << ", " << dataFromPNItrax.kQuaternion[2] << ", " << dataFromPNItrax.kQuaternion[3] << "] " << endl;
    cout << "kTemperature: " <<dataFromPNItrax.kTemperature << " grad C" << endl;
    cout << "kDistortion: " <<dataFromPNItrax.kDistortion << endl;
    cout << "kCalStatus: " <<dataFromPNItrax.kCalStatus << endl;
    cout << "kAccelX: " <<dataFromPNItrax.kAccelX << " g" << endl;
    cout << "kAccelY: " <<dataFromPNItrax.kAccelY << " g" << endl;
    cout << "kAccelZ: " <<dataFromPNItrax.kAccelZ << " g" << endl;
    cout << "kMagX: " <<dataFromPNItrax.kMagX << " mT" << endl;
    cout << "kMagY: " <<dataFromPNItrax.kMagY << " mT" << endl;
    cout << "kMagZ: " <<dataFromPNItrax.kMagZ << " mT" << endl;
    cout << "kGyroX: " <<dataFromPNItrax.kGyroX << " rad/sec" << endl;
    cout << "kGyroY: " <<dataFromPNItrax.kGyroY << " rad/sec" << endl;
    cout << "kGyroZ: " <<dataFromPNItrax.kGyroZ << " rad/sec" << endl;
    }
