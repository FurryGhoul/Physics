#pragma once
#include "Module.h"
#include "Globals.h"
#include "Box2D/Box2D/Box2D.h"

#define PIXEL_PER_METER 50.0f
#define PIXEL_PER_PIXEL 0.02f

#define METERS_TO_PIXELS(m) ((int) PIXELS_PER_METER * m)
#define PIXEL_TO_METERS(p) ((float) METERS_PER_PIXEL * p)
class b2World;

class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

private:
	float32 timeStep = 1.0f / 60.0f;
	b2World *world;
	b2Vec2 gravity;
	b2BodyDef groundBodyDef;
	b2PolygonShape groundBox;
	bool debug;
};