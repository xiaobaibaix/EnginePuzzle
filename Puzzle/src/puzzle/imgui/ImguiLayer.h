#pragma once

#include "../Core.h"
#include "puzzle/Layer.h"

#include "puzzle/events/ApplicationEvent.h"
#include "puzzle/events/KeyEvent.h"
#include "puzzle/events/MouseEvent.h"

namespace Puzzle {

	class PUZZLE_API ImguiLayer : public Layer{
		 
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach()override;
		void OnDetach()override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrollredEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);

	private:
		float m_Time=0;

	};
}