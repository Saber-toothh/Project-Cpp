#ifndef TRAFFIC_SCENARIO_H
#define TRAFFIC_SCENARIO_H

#include "Packet.h"
#include "TrafficConfig.h"

#include <vector>

/*
    Kịch bản 1: Lưu lượng mạng bình thường
    - Các gói tin đến router theo thời gian tăng dần
    - Không gây tắc nghẽn
*/
std::vector<Packet> generateNormalTraffic(const TrafficConfig& config);

/*
    Kịch bản 2: Lưu lượng ồ ạt gây tắc nghẽn
    - Nhiều gói tin đến router cùng thời điểm
    - Không xét QoS
*/
std::vector<Packet> generateCongestionTraffic(const TrafficConfig& config);

/*
    Kịch bản 3: Kiểm thử QoS trong điều kiện tắc nghẽn
    - Nhiều gói tin đến router cùng thời điểm
    - Các gói tin có mức ưu tiên khác nhau
*/
std::vector<Packet> generateQoSTraffic(const TrafficConfig& config);

#endif 
