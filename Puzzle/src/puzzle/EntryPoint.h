#pragma once

#ifdef PZ_PLATFORM_WINDOWS

#include "puzzle/Log.h"

extern Puzzle::Application* Puzzle::CreateApplication();

int main(int argc, char** argv) {

	Puzzle::Log::Init();
	PZ_CORE_WAEN("initialized of CoreLogger!");
	PZ_INFO("initialized of ClientLogger! {}",12);

	auto app = Puzzle::CreateApplication();
	app->run();
	delete app;
	return 0;
}


#endif // PZ_PLATFORM_WINDOWS
