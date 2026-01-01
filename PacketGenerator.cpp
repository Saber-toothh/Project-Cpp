#include "PacketGenerator.h"
#include "TrafficConfig.h"
#include <random>
#include <map>

// Bộ sinh số ngẫu nhiên tạo nguồn cho các hàm - std::mt19937 rng (...)
static std::mt19937 rng (std::random_device{}());
	/*
	static : cho phép sử dụng hàm trong cả file.
	mt19937 : thuật toán Mersenne Twister (máy quay số).
	random_device{}() : bộ khởi tạo giá trị ban đầu cho bộ sinh số.
	*/

// Hàm sinh số nguyên ngẫu nhiên trong [min, max] xác xuất bằng nhau:
int randomInt (int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);  // sinh ra 1 số ngẫu nhiên nằm trong [min, max].
	
	// std::uniform_int_distribution<int>: bộ phân phối ngẫu nhiên đều.
}

// Hàm sinh gói tin dựa trên cấu hình lưu lượng:
Packet generatePacket (int id, double currentTime, const TrafficConfig& config) {
    Packet p;
    p.id = id;
    p.arrivalTime = currentTime;
    
	// Hàm sinh số ngẫu nhiên theo tỉ lệ:
    std::discrete_distribution<int> serviceDist({
        config.serviceRate.at(ServiceType::VOICE),      // 0,2 ---> gán với 0
        config.serviceRate.at(ServiceType::VIDEO),      // 0,3 ---> gán với 1
		config.serviceRate.at(ServiceType::DATA) 		// 0,5 ---> gán với 2
		// nếu gọi hàm 10 lần: 2 1 0 2 2 1 0 2 1 2
		// std::discrete_distribution<int>: bộ phân phối ngẫu nhiên theo tỉ lệ
		 
    });

    int service = serviceDist(rng);

    if (service == 0) {
        p.service = ServiceType::VOICE;
        p.size = randomInt(
			config.packetSize.at(ServiceType::VOICE).first,
			config.packetSize.at(ServiceType::VOICE).second
			);			   
        p.priority = config.servicePriority.at(ServiceType::VOICE);                 
    }
    else if (service == 1) {
        p.service = ServiceType::VIDEO;
        p.size = randomInt(
			config.packetSize.at(ServiceType::VIDEO).first,
			config.packetSize.at(ServiceType::VIDEO).second
			);  
        p.priority = config.servicePriority.at(ServiceType::VIDEO);
    }
    else {
        p.service = ServiceType::DATA;
        p.size = randomInt(
			config.packetSize.at(ServiceType::DATA).first,
			config.packetSize.at(ServiceType::DATA).second
			); 
        p.priority = config.servicePriority.at(ServiceType::DATA);                 
    }

    return p;
}

