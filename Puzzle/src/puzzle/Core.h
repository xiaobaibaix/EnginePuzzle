#pragma once

#ifdef PZ_PLATFORM_WINDOWS
	#ifdef PZ_BUILD_DLL
		#define PUZZLE_API __declspec(dllexport)
	#else
		#define PUZZLE_API __declspec(dllimport)
	#endif // PZ)BUILD_DLL
#else
	#error puzzle only supports windows!
#endif // PZ_PLATFORM_WINDOWS

#ifdef  PZ_ENABLE_ASSERTS
	#define PZ_ASSERTS(x,...) {if(!(x)){PZ_ERROR("Assertion Failed: {0}",__VA_ARGS__),__debugbreak;}}
	#define PZ_CORE_ASSERTS(x,...) {if(!(x)){PZ_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__),__debugbreak;}}
#else
	#define PZ_ASSERTS(x,...)  
	#define PZ_CORE_ASSERTS(x,...) 

#endif //  PZ_ENABLE_ASSERTS



#define BIT(num) (1<<num)

#define PZ_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)