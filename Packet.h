#ifndef PACKET_H
#define PACKET_H
#include <ostream>
/* Chức năng chính của file Packet.h :
	- Định nghĩa các loại dịch vụ và cấu trúc dữ liệu cơ bản của gói tin 
*/

// Các loại dịch vụ của gói tin: 
enum class ServiceType {   
    VOICE,   // Thoại - ưu tiên cao(3) - size nhỏ(100–200 bytes)
    VIDEO,   // Video - ưu tiên trung bình(2) - size trung bình(500–1000 bytes)
    DATA     // Dữ liệu - ưu tiên thấp(1) - size lớn(1000–1500 bytes)
    
/*	Dùng enum class thay vì enum thường do :
	enum class giúp tăng tính an toàn cho dữ liệu và tránh xung đột tên 
	vì nếu muốn sử dụng dữ liệu (VOICE,VIDEO,DATA) bắt buộc ghi rõ nguồn gốc (ServiceType::____)
*/
};

// Cấu trúc dữ liệu của một gói tin:
struct Packet {
    int id;                 // ID gói tin (tăng dần:1,2,3,..), mỗi 1 gói tin được gắn với 1 ID
    int size;               // Kích thước gói tin (bytes) (phụ thuộc vào dịch vụ của gói tin đó)
    int priority;           // Mức ưu tiên (1: thấp, 2: trung bình, 3: cao)
    double arrivalTime;     // Thời điểm gói tin đến router
    ServiceType service;    // Loại dịch vụ (VOICE,VIDEO,DATA)
};

// Khai báo toán tử in Packet
std::ostream& operator<<(std::ostream& os, const Packet& p);
#endif




