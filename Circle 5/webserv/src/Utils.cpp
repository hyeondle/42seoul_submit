#include "Utils.hpp"
#include <sstream>
#include <iostream>
#include <cctype>
#include <locale>
#include <arpa/inet.h>

// Function definitions

void left_trim(std::string &s) 
{
    std::string::iterator it = s.begin();
    while (it != s.end() && std::isspace(*it))
        it++;
    s.erase(s.begin(), it);
}

void right_trim(std::string &s)
{
    std::string::reverse_iterator rit = s.rbegin();
    while (rit != s.rend() && std::isspace(*rit))
        rit++;
    s.erase(rit.base(), s.end());
}

void trim(std::string &s) {
	left_trim(s);
	right_trim(s);
}

size_t convert_to_bytes(const std::string& number) {
	try {
		return std::stoull(number);
	} catch (const std::invalid_argument&) {
		size_t result = std::stoull(number.substr(0, number.size() - 1));
		switch(std::toupper(number.back())) {
			case 'K':
				result *= 1024;
				break;
			case 'M':
				result *= 1024 * 1024;
				break;
			case 'G':
				result *= 1024 * 1024 * 1024;
				break;
			default:
				throw std::runtime_error("Utils::convert_to_bytes : Invalid size unit");
		}
		return result;
	}
}

std::vector<std::string> string_to_tokens(std::string string) {
	::trim(string);
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream iss(string);
	while (iss >> token) tokens.push_back(token);
	return tokens;
}


static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	d;
	unsigned char	*e;

	a = 0;
	e = (unsigned char *) b;
	d = (unsigned char) c;
	while (a < len)
	{
		e[a] = d;
		a++;
	}
	return (b);
}


struct sockaddr_in string_to_address(const std::string& address) {
    struct sockaddr_in addr;
    ft_memset(&addr, 0, sizeof(addr)); // 구조체 초기화

    addr.sin_family = AF_INET; // 주소 패밀리 설정

    std::istringstream addr_stream(address);
    int segment;
    char dot;
    uint32_t ip_addr = 0;

    for (int shift = 24; shift >= 0; shift -= 8) {
        if (!(addr_stream >> segment) || segment < 0 || segment > 255 || (shift > 0 && addr_stream >> dot && dot != '.')) {
            std::cerr << "Invalid IP address format" << std::endl;
            exit(EXIT_FAILURE);
        }
        ip_addr |= segment << shift;
    }

    int port;
    if (addr_stream >> dot && dot == ':' && addr_stream >> port) {
        addr.sin_port = htons(port); // 포트 번호 설정
    } else {
        std::cerr << "Invalid port format" << std::endl;
        exit(EXIT_FAILURE);
    }

    addr.sin_addr.s_addr = htonl(ip_addr);

    return addr;
}

std::string address_to_string(const struct sockaddr_in& addr) {
    uint32_t ip_addr = ntohl(addr.sin_addr.s_addr);  // 네트워크 바이트 순서를 호스트 바이트 순서로 변환
    int port = ntohs(addr.sin_port);  // 네트워크 바이트 순서로 된 포트를 호스트 바이트 순서로 변환

    std::stringstream ss;
    ss << ((ip_addr >> 24) & 0xFF) << '.';  // 첫 번째 바이트
    ss << ((ip_addr >> 16) & 0xFF) << '.';  // 두 번째 바이트
    ss << ((ip_addr >> 8) & 0xFF) << '.';   // 세 번째 바이트
    ss << (ip_addr & 0xFF);                 // 네 번째 바이트
    ss << ':' << port;                      // 포트

    return ss.str();
}

// Note: Any additional helper functions like ft_memset that are only used in utils.cpp should also be defined here.
