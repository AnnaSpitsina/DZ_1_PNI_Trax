#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

using namespace std;

struct DataFromPNItrax {
    string kHeading = "---";
    string kPitch = "---";
    string kRoll = "---";
    string kHeadingStatus = "---";
    string kQuaternion[4]= {"---", "---", "---", "---"};
    string kTemperature = "---";
    string kDistortion = "---";
    string kCalStatus = "---";
    string kAccelX = "---";
    string kAccelY = "---";
    string kAccelZ = "---";
    string kMagX = "---";
    string kMagY = "---";
    string kMagZ = "---";
    string kGyroX = "---";
    string kGyroY = "---";
    string kGyroZ = "---";
};

void parsing_package(char* pack);
string HexInFloat(std::string package);
void PrintResult(DataFromPNItrax dataFromPNItrax);

#endif // FUNCTION_H
