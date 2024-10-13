#pragma once
#include "events/Event.h"

namespace Puzzle {

	class PUZZLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};//附加
		virtual void OnDetach() {};//分离
		virtual void OnUpdate() {};//更新
		virtual void OnEvent(Event& e) {};//事件更新

		inline const std::string& GetName()const { return m_Name; }

	private:
		std::string m_Name;
	};

}

