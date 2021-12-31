#include <cstddef>
#include <iostream>
#include <functional>
#include <string>
//#include <string_view>
#include <unordered_map>

using namespace std::literals;
using std::size_t;

// struct string_hash
// {
// 	using hash_type = std::hash<std::string_view>;
// 	using is_transparent = void;
// 
// 	size_t operator()(const char* str) const { return hash_type{}(str); }
// 	size_t operator()(std::string_view str) const { return hash_type{}(str); }
// 	size_t operator()(std::string const& str) const { return hash_type{}(str); }
// };

int main()
{
	// 简单比较演示
	std::unordered_map<int, char> example = { { 1,'a' },{ 2,'b' },{ 2,'c' } };

	auto search = example.find(2);
	if (search != example.end()) {
		std::cout << "Found " << search->first << " " << search->second << '\n';
	}
	else {
		std::cout << "Not found\n";
	}

	// C++20 演示：无序容器的异质查找（通透哈希）
// 	std::unordered_map<std::string, size_t, string_hash, std::equal_to<>> map{ { "one"s, 1 } };
// 	std::cout << std::boolalpha
// 		<< (map.find("one") != map.end()) << '\n'
// 		<< (map.find("one"s) != map.end()) << '\n'
// 		<< (map.find("one"sv) != map.end()) << '\n';

	getchar();
	return 0;
}