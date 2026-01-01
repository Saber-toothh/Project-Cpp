#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp" // Thư viện xử lý JSON

using json = nlohmann::json;
using namespace std;

// 1. Định nghĩa Struct tương ứng với file JSON
struct TrafficRate {
    double normal;
    double vip;
};

struct Config {
    string simulation_name;
    int total_time;
    int bandwidth_mbps;
    int max_queue_size;
    TrafficRate traffic_rate;
};

// 2. Hàm đọc file
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

int main() {
    // Gọi hàm đọc file
    Config myConfig = loadConfig("data/config.json");

    // In thử ra màn hình để kiểm tra
    cout << "Ten mo phong: " << myConfig.simulation_name << std::endl;
    cout << "Bang thong: " << myConfig.bandwidth_mbps << " Mbps" << std::endl;
    cout << "Ti le Normal: " << myConfig.traffic_rate.normal << std::endl;
    cout << "Ti le VIP: " << myConfig.traffic_rate.vip << std::endl;

    return 0;
}
