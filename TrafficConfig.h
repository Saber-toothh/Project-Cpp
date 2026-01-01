#ifndef TRAFFIC_CONFIG_H
#define TRAFFIC_CONFIG_H

#include "Packet.h"
#include <map>
#include <utility>

struct TrafficConfig {
    int totalPackets;          // Tổng số gói tin
     
	double startTime;          // Thời điểm bắt đầu sinh gói
	
	double packetIntervalof1;     // Khoảng thời gian giữa các gói của kich bản 1
	double packetIntervalof2;     // Khoảng thời gian giữa các gói của kich bản 1
	double packetIntervalof3;     // Khoảng thời gian giữa các gói của kich bản 1

    // Tỉ lệ sinh gói tin từng loại dịch vụ:
    std::map <ServiceType, double> serviceRate;

    // Kích thước gói tin (min, max):
    std::map <ServiceType, std::pair<int, int>> packetSize;

    // Mức ưu tiên theo dịch vụ: 
    std::map<ServiceType, int> servicePriority;
    
    // Constructor: tạo cấu hình mặc định
    TrafficConfig() {
        totalPackets = 100;   
        packetIntervalof1 = 0.1; // giây
        packetIntervalof2 = 0.01;
        packetIntervalof3 = 0.01;
        
		startTime = 0;
		
        serviceRate[ServiceType::VOICE] = 0.2;
        serviceRate[ServiceType::VIDEO] = 0.3;
        serviceRate[ServiceType::DATA]  = 0.5;

        packetSize[ServiceType::VOICE] = {100, 200}; // bytes
        packetSize[ServiceType::VIDEO] = {500, 1000};
        packetSize[ServiceType::DATA]  = {1000, 1500};

        servicePriority[ServiceType::VOICE] = 3; 
        servicePriority[ServiceType::VIDEO] = 2;
        servicePriority[ServiceType::DATA]  = 1;
    }
    
};

#endif
