#pragma once
#include "puzzle/Core.h"
#include "Window.h"

#include "events\ApplicationEvent.h"
#include "LayerStack.h"

namespace Puzzle {

	class PUZZLE_API Application
	{
	public:
		Application();
		virtual~Application();

		void OnEvent(Event& e);
		void run();

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);

		inline static Application& Get() { return *s_Instence; }
		inline Window& GetWindow() { return *m_Window; }
	private:

		bool OnWindowClose(WindowCloseEvent& e);
	private:
		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instence;
	};


	Application* CreateApplication();
}

