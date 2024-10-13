#pragma once

#include "puzzle/Core.h"
#include "puzzle/events/Event.h"

namespace Puzzle {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& tile="Puzzle",
			unsigned int w=1280,
			unsigned int h=720 ):Title(tile),Width(w),Height(h) {
		}
	};

	class PUZZLE_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()const = 0;
		virtual unsigned int GetHeight()const = 0;

		// Ù–‘
		virtual void SetEventCallback(const EventCallback& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync()const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}