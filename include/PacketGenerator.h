#ifndef PACKET_GENERATOR_H
#define PACKET_GENERATOR_H

#include "Packet.h"
#include "TrafficConfig.h"

// Hàm sinh một gói tin dựa trên cấu hình lưu lượng
Packet generatePacket(int id, double currentTime, const TrafficConfig& config);

#endif

/* 
Input :  - Id 
		 - currentTim: thời điểm tới router
		 - TrafficConfig: cấu hình lưu lượng 
		
Output : - 1 gói tin hoàn chỉnh đấy đủ dữ liệu, gồm:
                 * Id
				 * size
				 * priority
				 * arrivalTime
				 * ServiceType
*/			 
				              		 
						
