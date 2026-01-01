#include "TrafficScenario.h"
#include "PacketGenerator.h"


// Kịch bản 1: Lưu lượng bình thường
std::vector<Packet> generateNormalTraffic(const TrafficConfig& config) {
    std::vector<Packet> packets;
    
    double currentTime = config.startTime;

    for (int i = 0; i < config.totalPackets; i++) {
        Packet p = generatePacket(i + 1, currentTime, config);
        packets.push_back(p);
        currentTime += config.packetIntervalof1;
    }

    return packets;
}

// Kịch bản 2: Tắc nghẽn (không QoS)
std::vector<Packet> generateCongestionTraffic(const TrafficConfig& config) {
    std::vector<Packet> packets;

	double currentTime = config.startTime;
    
    for (int i = 0; i < config.totalPackets; i++) {
        Packet p = generatePacket(i + 1, currentTime , config);
        p.priority = 1;    // tất cả gói như nhau và bằng 1
        packets.push_back(p);
        currentTime += config.packetIntervalof2;
    }

    return packets;
}
// Kịch bản 3: Tắc nghẽn + QoS 
std::vector<Packet> generateQoSTraffic(const TrafficConfig& config) {
    std::vector<Packet> packets;
    
 	double currentTime = config.startTime;
 	
    for (int i = 0; i < config.totalPackets; i++) {
        Packet p = generatePacket(i + 1, currentTime, config); 
        packets.push_back(p);
        currentTime += config.packetIntervalof3;
    }

    return packets;
}

