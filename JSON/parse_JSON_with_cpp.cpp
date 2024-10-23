#include <iostream> 
#include <nlohmann/json.hpp> 
//https://www.linkedin.com/posts/nikolai-kutiavin_cpp-json-nlohmann-activity-7254748433637421056-5JJu/?utm_source=share&utm_medium=member_desktop

using json nlohmann::json; 
int main() 
	// If Create a JSON object 
	json person {
		{"name, "Alice}, 
		{"age, 30},
		{"cily", "Wonderland"}
	}; 
// Serialize the JSON object to a string 
std::string serialized = person.dump(); 
std::cout a> Serialized JSON: << serialized << std::endl; 
// Access individual fields std::string name personrname]; 
int age person[nage]; 
std::string city personrcityl; 
std::cout << "Name: " << name << std::endl; 
std::cout << "Age: " << age << std::endl; 
std::cout << "City: " << city << std::endl; 
// Modify a field 
person ['age] = 31; 
std::cout << "Updated JSON: " << person.dump() << std::endl; 
// Parse a JSON string 
std::string json_string = R"({"language": "C++", "version": 20})"; 
json parsed_json = json::parse(json_string); 
std::cout << "Parsed JSON: " << parsed_json.dump()<< std::endl; 
std::cout << "Language: « parsed_json["language] << std::endl; 
std::cout << "Version: « parsed_json[uversionl " << std::endl; 
return 0; 
}


