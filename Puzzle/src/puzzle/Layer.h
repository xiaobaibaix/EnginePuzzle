#pragma once
#include "events/Event.h"

namespace Puzzle {

	class PUZZLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};//����
		virtual void OnDetach() {};//����
		virtual void OnUpdate() {};//����
		virtual void OnEvent(Event& e) {};//�¼�����

		inline const std::string& GetName()const { return m_Name; }

	private:
		std::string m_Name;
	};

}

