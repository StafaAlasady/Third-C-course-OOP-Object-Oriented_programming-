#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct DataPoint {
    double value;
    string label;
    int timestamp;
};
// Function using reference for efficient parameter passing
void processDataPoint(DataPoint& data) {
    data.value *= 1.1;  // Apply 10% scaling factor
    data.timestamp += 1000;  // Update timestamp
    cout << "Processed: " << data.label << " = " << data.value << endl;
}
// Function using const reference for read-only access
void displayDataPoint(const DataPoint& data) {
    cout << "Data: " << data.label << " | Value: " << data.value 
         << " | Time: " << data.timestamp << endl;
}
int main() {
    DataPoint sensor1 = {25.5, "Temperature", 1000};
    cout << "=== Before Processing ===" << endl;
    displayDataPoint(sensor1);    
    // Create reference to the data point
    DataPoint& sensorRef = sensor1;
    cout << "Reference value: " << sensorRef.value << endl;
    cout << "Original and reference have same address: " 
         << (&sensor1 == &sensorRef ? "true" : "false") << endl;    
    processDataPoint(sensorRef);    
    cout << "\n=== After Processing ===" << endl;
    displayDataPoint(sensor1);  // Shows modified values
    //sensor 2 starts here with calculations of humidity levels instead of temp
    cout << "\n=== Sensor 2 ===" << endl;
    DataPoint sensor2 = {54.5, "HumidityLevelsPerSqareMeter",2000};
    sensorRef = sensor2;
    displayDataPoint(sensor2);
    DataPoint& sensorRef2 = sensor2;
    cout << "Refrence value: " << sensorRef2.value << endl;
    cout << "Original and refrence have the same adress: "
        << (&sensor2 == &sensorRef2 ? "true" : "false") << endl;
        processDataPoint(sensorRef2);
    cout << "\n=== After Processing ===" << endl;
    displayDataPoint(sensor2);//shows the modified values in sensor 2
    return 0;
}