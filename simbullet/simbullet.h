#ifndef SIMBULLET_H__
#define SIMBULLET_H__

#include <btBulletDynamicsCommon.h>
#include <simbullet/vehicle.h>
#include <simbullet/version.h>

///////////////////////////////////////
#include <../examples/CommonInterfaces/CommonExampleInterface.h>
#include <../examples/CommonInterfaces/CommonGUIHelperInterface.h>
#include <../examples/Vehicles/Hinge2Vehicle.h>
#include <../examples/Utils/b3Clock.h>

#include <../examples/OpenGLWindow/SimpleOpenGL3App.h>
#include <stdio.h>
#include <../examples/ExampleBrowser/OpenGLGuiHelper.h>


// b3MouseMoveCallback prevMouseMoveCallback = 0;
// static void OnMouseMove(float x, float y)
// {
// 	bool handled = false;
// 	handled = example->mouseMoveCallback(x, y);
// 	if (!handled)
// 	{
// 		if (prevMouseMoveCallback)
// 			prevMouseMoveCallback(x, y);
// 	}
// }

// b3MouseButtonCallback prevMouseButtonCallback = 0;
// static void OnMouseDown(int button, int state, float x, float y)
// {
// 	bool handled = false;

// 	handled = example->mouseButtonCallback(button, state, x, y);
// 	if (!handled)
// 	{
// 		if (prevMouseButtonCallback)
// 			prevMouseButtonCallback(button, state, x, y);
// 	}
// }

// class LessDummyGuiHelper : public DummyGUIHelper
// {
// 	CommonGraphicsApp* m_app;

// public:
// 	virtual CommonGraphicsApp* getAppInterface()
// 	{
// 		return m_app;
// 	}

// 	LessDummyGuiHelper(CommonGraphicsApp* app)
// 		: m_app(app)
// 	{
// 	}
// };
//////////////////////////////////////

class simbullet{
public:
    simbullet();
    ~simbullet();
    int dosth(int a);
    int run_example();
    int run_gui_example();
    int cnt;
};

#endif// SIMBULLET_H__