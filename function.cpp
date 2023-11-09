#include <iostream>
#include "function.h"

void parsing_package(char* pack) {

    std::string package;
    package = pack;
    DataFromPNItrax dataFromPNItrax;

    cout << "Received package" << endl << package << endl;
    while (package.length()>0) {
        string ID = package.substr(0,2);
        int ID_field = stoul(ID, nullptr, 16);
        switch(ID_field)
        {
            case 5:{
                dataFromPNItrax.kHeading = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 7:{
                dataFromPNItrax.kTemperature = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 8:{
                string Distortion = package.substr(2,2);
                int info_Distortion = stoul(Distortion, nullptr, 16);
                if (info_Distortion == 1) {
                    dataFromPNItrax.kDistortion = "true";
                } else {
                    dataFromPNItrax.kDistortion = "false";
                }
                package.erase(0,4);
                break;
            }
            case 9:{
                string CalStatus = package.substr(2,2);
                int info_CalStatus = stoul(CalStatus, nullptr, 16);
                dataFromPNItrax.kCalStatus = info_CalStatus;
                if (info_CalStatus == 1) {
                    dataFromPNItrax.kCalStatus = "true";
                } else {
                    dataFromPNItrax.kCalStatus = "false";
                }
                package.erase(0,4);
                break;
            }
            case 21:{
                dataFromPNItrax.kAccelX = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 22:{
                dataFromPNItrax.kAccelY = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 23:{
                dataFromPNItrax.kAccelZ = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 24:{
                dataFromPNItrax.kPitch = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 25:{
                dataFromPNItrax.kRoll = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 27:{
                dataFromPNItrax.kMagX = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 28:{
                dataFromPNItrax.kMagY = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 29:{
                dataFromPNItrax.kMagZ = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 74:{
                dataFromPNItrax.kGyroX = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 75:{
                dataFromPNItrax.kGyroY = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 76:{
                dataFromPNItrax.kGyroZ = HexInFloat(package);
                package.erase(0,10);
                break;
            }
            case 77:{
                package.erase(0,2);
                for (int i=0; i<4; i++) {
                    string info = package.substr(0,8);
                    uint32_t bigEndiankQuaternion_i = strtoul(info.c_str(),NULL,16);
                    float float_Quaternion_i;
                    memcpy(&float_Quaternion_i, &bigEndiankQuaternion_i, sizeof(float_Quaternion_i));
                    string Quaternion_i = to_string(float_Quaternion_i);
                    dataFromPNItrax.kQuaternion[i] = Quaternion_i;
                    package.erase(0,8);
                    }
            break;
            }
            case 79:{
                string info = package.substr(2,2);
                char char_kHeadingStatus = static_cast<char>(std::stoi(info, nullptr, 16));
                //dataFromPNItrax.kHeadingStatus = static_cast<int>(char_kHeadingStatus);
                dataFromPNItrax.kHeadingStatus = to_string(char_kHeadingStatus);
                package.erase(0,4);
                break;
            }
            default:
            cout << "Error, try again";
       }
    }
    PrintResult(dataFromPNItrax);
}

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
