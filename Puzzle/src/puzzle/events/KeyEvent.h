#pragma once

#include "Event.h"


namespace Puzzle {

	class PUZZLE_API KeyEvent :public Event{
	
	public:
		inline int GetKeyCode()const {return m_KeyCode;}

		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryKeyboard | (int)EventCategory::EventCategoryInput)
	protected:
		KeyEvent(int keycode) :m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class PUZZLE_API KeyPressedEvent :public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) :KeyEvent(keycode), m_RepearCount(repeatCount) {}

		inline int GetRepeatCount()const { return m_RepearCount; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyPressedEvent " << m_KeyCode << " (" << m_RepearCount << "repeats" << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepearCount;
	};

	class PUZZLE_API KeyReleasedEvent :public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) :KeyEvent(keycode){}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class PUZZLE_API KeyTypedEvent :public KeyEvent {
	public:
		KeyTypedEvent(int keycode) :KeyEvent(keycode) {}

		std::string ToString()const override {
			std::stringstream ss;
			ss << "KeyTypedEvent " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}