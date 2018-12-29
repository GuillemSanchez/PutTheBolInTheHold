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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	AddWall((20, 20, 5), (1, 1, 1), 0, (0, 0, 0), 0.0f, Blue);
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
void ModuleSceneIntro::AddWall(vec3 dimvec, vec3 posvec, float angle, vec3 rotvec, float m, Color color) {

	Cube c(dimvec.x, dimvec.y, dimvec.z);
	c.SetPos(posvec.x, posvec.y, posvec.z);

	if (angle != 0)
		
		c.SetRotation(angle, vec3(rotvec.x, rotvec.y, rotvec.z));

	c.color = color;
	App->physics->AddBody(c, m);

	Walls.add(c);


}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

