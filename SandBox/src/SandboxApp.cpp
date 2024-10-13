#include <puzzle.h>

class TempLayer :public Puzzle::Layer {

public:
	TempLayer() :Layer("templat") {

	}

	void OnUpdate()override {

	};
	
	void OnEvent(Puzzle::Event& e) {
		PZ_WAEN("Template on Event {0}!",e.ToString());
	};
private:

};

class Sandbox :public Puzzle::Application {

public:
	Sandbox() {
		PushLayer(new TempLayer());
		PushOverLayer(new Puzzle::ImguiLayer());//×î¶¥²ã
	};

	~Sandbox() {

	}

};

Puzzle::Application* Puzzle::CreateApplication() {
	return new Sandbox;
}
