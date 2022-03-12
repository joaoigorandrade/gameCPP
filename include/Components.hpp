#pragma once
#include "EntityComponentSystem.hpp"

class PositionComponent : public Component {
private:
	int xPosition, yPosition;
public:
	int x() { return xPosition; }
	int y() { return yPosition; }

	void init() override {
		xPosition = 0;
		yPosition = 0;
	}
	void setPosition(int x, int y) {
		xPosition = x;
		yPosition = y;
	}
	void update() override {
		xPosition++;
		yPosition++;
	}
};