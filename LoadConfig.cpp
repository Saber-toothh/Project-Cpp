#include <iostream>
#include <fstream>
#include <string>
#include "Config.h"
#include "json.hpp" // Thư viện xử lý JSON

using json = nlohmann::json;
using namespace std;

Config loadConfig(const string& filePath) {
    ifstream file(filePath);
    json j;
    file >> j; // Đọc nội dung file vào biến json

    Config cfg;
    cfg.simulation_name = j["simulation_name"];
    cfg.total_time = j["total_time"];
    cfg.bandwidth_mbps = j["bandwidth_mbps"];
    cfg.max_queue_size = j["max_queue_size"];
    cfg.traffic_rate.normal = j["traffic_rate"]["normal"];
    cfg.traffic_rate.vip = j["traffic_rate"]["vip"];

    return cfg;
}


