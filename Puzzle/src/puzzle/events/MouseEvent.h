#pragma once

#include "Event.h"

namespace Puzzle {

	class PUZZLE_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float x, float y) :m_MouseX(x), m_MouseY(y){};

		inline float GetX()const { return m_MouseX; }
		inline float GetY()const { return m_MouseY; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseMoveEvent " << m_MouseX << " " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryInput | (int)EventCategory::EventCategoryMouse)

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class PUZZLE_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffSet, float yOffSet) :m_XOffSet(xOffSet), m_YOffSet(yOffSet) {};

		inline float GetXOffSet()const { return m_XOffSet; }
		inline float GetYOffSet()const { return m_YOffSet; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent " << m_XOffSet << " " << m_YOffSet;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryInput | (int)EventCategory::EventCategoryMouse);

	private:
		float m_XOffSet;
		float m_YOffSet;
	};


	class PUZZLE_API MouseButtonEvent :public Event {

	public:
		inline int GetMouseButton()const { return m_Button; }

		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryInput | (int)EventCategory::EventCategoryMouseButton);

	protected:
		MouseButtonEvent(int button):m_Button(button){}

		int m_Button;
	};

	class PUZZLE_API MouseButtonPressedEvent :public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int button) :MouseButtonEvent(button){}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent " << m_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class PUZZLE_API MouseButtonReleasedEvent :public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) :MouseButtonEvent(button) {}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}