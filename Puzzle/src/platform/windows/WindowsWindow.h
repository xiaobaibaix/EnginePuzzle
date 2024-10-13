#pragma once

#include "puzzle/Window.h"

#include <glad/glad.h>
#include <KHR/khrplatform.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace Puzzle {
	class PUZZLE_API WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual~WindowsWindow();

		void OnUpdate()override;

		inline unsigned int GetWidth()const override { return m_Data.Width; }
		inline unsigned int GetHeight()const override { return m_Data.Height; }

		// Ù–‘
		inline void SetEventCallback(const EventCallback& callback)override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enable)override;
		virtual bool IsVSync()const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window=nullptr; 

		struct WindowData {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallback EventCallback;
		};

		WindowData m_Data;
	};

}


