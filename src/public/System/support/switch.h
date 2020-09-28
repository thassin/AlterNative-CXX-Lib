
#include <cctype>	// for isspace.
// https://stackoverflow.com/questions/21578544/stdremove-if-and-stdisspace-compile-time-error 

// https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html 
// https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html 
// https://www.geeksforgeeks.org/and-operators-in-c/ 

#define FULLFILLMAP(numArgs, ...)\
const char* _arr_ =  #__VA_ARGS__;\
std::string str = std::string(_arr_);\
std::vector<std::string> tokens;\
boost::algorithm::split(tokens, str, boost::algorithm::is_any_of(","));\
for ( int __i = 0; __i < numArgs; __i++ ) { \
	std::string tmp = tokens[__i];\
	auto f = [](unsigned char const c) { return std::isspace(c); };\
	tmp.erase( std::remove_if(tmp.begin(), tmp.end(), f), tmp.end() );\
	map->SetData(__i, new String(tmp.data()));\
}

// old 20200928
//	tmp.erase( remove_if(tmp.begin(), tmp.end(), isspace));\

// 20200928 it seems this can be either way:
//		FULLFILLMAP(numArgs, __VA_ARGS__);\
//		FULLFILLMAP(numArgs, #__VA_ARGS__);\

#define STRING_SWITCH(variable, numArgs, ...)\
struct variable##_struct {\
	enum labels { \
		__VA_ARGS__\
	};\
	\
	Array<String>* map;\
	\
	variable##_struct(){\
		map = new Array<String>(numArgs);\
		FULLFILLMAP(numArgs, __VA_ARGS__);\
	}\
	\
	int parseString(String* s){\
		for(int i=0; i < map->Length; i++)\
		{\
			String* tmp = map->GetData(i);\
			if(tmp->compare(s->data()) == 0)\
				return i;\
		}\
		return -1;\
	}\
} variable;\
typedef variable##_struct::labels variable##_labels;

