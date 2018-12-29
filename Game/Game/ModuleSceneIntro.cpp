#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(0.0F, 5.0F, -10.F));
	App->camera->LookAt(vec3(0, 0, 11));
	AddWall(vec3(30, 60, 1), vec3(0, 30, 80), Blue);
	AddWall(vec3(30, 15, 1), vec3(0, 7.5F, 40), Green);

	AddWall(vec3(30, 30, 1), vec3(0, 7, 26.7), Red, 60.f, vec3(1, 0, 0)); 


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.color = Black;
	p.axis = true;
	p.Render();
	PrintWalls();
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::PrintWalls() {

	p2List_item<Cube>* def_wall;
	def_wall = Walls.getFirst();

	while (def_wall != nullptr) {
		def_wall->data.Render();
		def_wall = def_wall->next;
	}
}
void ModuleSceneIntro::AddWall(vec3 size, vec3 position, Color color, float angle, vec3 rotvec, float mass) {

	Cube c(size.x, size.y, size.z);
	c.SetPos(position.x, position.y, position.z);

	if (angle != 0)
	{
		c.SetRotation(angle, vec3(rotvec.x, rotvec.y, rotvec.z));
	}

	c.color = color;
	App->physics->AddBody(c, mass);

	Walls.add(c);
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

