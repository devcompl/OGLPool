/*
 * TestMenu.h
 *
 *  Created on: 24-06-2013
 *      Author: _CORE7
 */

#ifndef TESTMENU_H_
#define TESTMENU_H_

#include "Menu.h"
#include <World/World.h>
#include <Util/Table/CueTable.h>
#include "Component/SliderComponent.h"
#include "Component/LabelComponent.h"

namespace OGLPool {

class TestMenu : public Menu {
public:
	TestMenu( RenderWindow* window );
	virtual ~TestMenu();

	void render();
	void update( float dt );
	void generateTable();

	CueTable cueTable;
	World* world;

	SliderComponent* seedSlider;
	SliderComponent* polygonSidesSlider;
	SliderComponent* polygonPointsSlider;
	SliderComponent* polygonNumTriesSlider;
	SliderComponent* polygonScaleSlider;

	LabelComponent* seedLabel;
	LabelComponent* polygonSidesLabel;
	LabelComponent* polygonPointsLabel;
	LabelComponent* polygonNumTriesLabel;
	LabelComponent* polygonScaleLabel;
};

} /* namespace OGLPool */
#endif /* TESTMENU_H_ */
