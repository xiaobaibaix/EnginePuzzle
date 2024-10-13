#pragma once

#include "Event.h"


namespace Puzzle {

	class PUZZLE_API WindowResizeEvent :public Event {

	public:
		WindowResizeEvent(unsigned int w,unsigned int h):m_Width(w), m_Height(h){}

		inline unsigned int GetW()const { return m_Width; }
		inline unsigned int GetH()const { return m_Height; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "WindowResizeEvent " << m_Width << " " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	private:

		unsigned int m_Width;
		unsigned int m_Height;

	};


	class PUZZLE_API WindowMoveEvent :public Event {

	public:
		WindowMoveEvent(unsigned int x, unsigned int y) :m_X(x), m_Y(y) {}

		inline unsigned int GetX()const { return m_X; }
		inline unsigned int GetY()const { return m_Y; }

		std::string ToString()const override {
			std::stringstream ss;
			ss << "WindowMoveEvent " << m_X << " " << m_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMove)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	private:

		unsigned int m_X;
		unsigned int m_Y;

	};


	class PUZZLE_API WindowCloseEvent :public Event {

	public:
		WindowCloseEvent() {}


		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	};

	class PUZZLE_API AppTickEvent :public Event {

	public:
		AppTickEvent() {}


		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	};

	class PUZZLE_API AppUpdateEvent :public Event {

	public:
		AppUpdateEvent() {}


		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	};

	class PUZZLE_API AppRenderEvent :public Event {

	public:
		AppRenderEvent() {}


		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY((int)EventCategory::EventCategoryApplication)

	};


}