#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#define XXL 60
#define XL 15
#define RMP 30

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
	//AddWall(vec3(30, 60, 1), vec3(0, 30, 80), Blue);
	//AddWall(vec3(30, 15, 1), vec3(0, 7.5F, 40), Green);

	//AddWall(vec3(30, 30, 1), vec3(0, 7, 26.7), Red, 60.f, vec3(1, 0, 0)); 
	AddWall(vec3(100, XL, 3), vec3(54, 7.5F, 40), Green);
	AddWall(vec3(100, XL, 3), vec3(-54, 7.5F, 40), Green); //DERECHA
	AddWall(vec3(3, XL, 150), vec3(-75, 7.5F, 116.5F), Green); //DERECHA
	AddWall(vec3(7, XXL, 800), vec3(-115.5F, 30, 0), Blue); //DERECHA
	AddWall(vec3(30, XL, 3), vec3(-100, 7.5F, 116), Green); //DERECHA
	AddWall(vec3(50, XL, 3), vec3(-101, 7.5F, 137), Green,55.F,vec3(0,1,0)); //DERECHA
	AddWall(vec3(30, XL, 3), vec3(-90+1.5F, 7.5F, 166), Green); //DERECHA
	AddWall(vec3(50, XL, 3), vec3(-91+1.5F, 7.5F, 147), Green, 55.F, vec3(0, 1, 0)); //DERECHA
	AddWall(vec3(120, XL, 3), vec3(10, 7.5F, 65), Green); //DERECHA
	AddWall(vec3(40, XL, 3), vec3(-41.6 + 1.5F, 7.5F, 83.6), Green, -65.F, vec3(0, 1, 0)); //DERECHA
	AddWall(vec3(3, XL, 60), vec3(-60, 7.5F, 95), Green); //DERECHA
	AddWall(vec3(31, XL, 3), vec3(-45, 7.5F, 125), Green); //DERECHA
	AddWall(vec3(3, XL, 65), vec3(-31, 7.5F, 157), Green); //DERECHA
	AddWall(vec3(30, XL, 3), vec3(-60, 7.5F, 190), Green); //DERECHA
	AddWall(vec3(90, XL, 3), vec3(-74.5F, 7.5F, 210), Green); //DERECHA
	AddWall(vec3(3, XL, 150), vec3(102.5F, 7.5F, 116.5F), Green); //IZQUIERDA
	AddWall(vec3(66, XL, 3), vec3(70.5F, 7.5F, 100), Green); //IZQUIERDA
	AddWall(vec3(55, XL, 3), vec3(-6.5F, 7.5F, 100), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 15), vec3(40, 7.5F, 48), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 15), vec3(68.5F, 7.5F, 56), Green); //IZQUIERDA
	AddWall(vec3(7, XXL, 800), vec3(130.5F, 30, 0), Blue); //IZQUIERDA
	AddWall(vec3(49, 3, 40), vec3(108, 13.5f, 200), Green); //PLATAFORMA
	AddWall(vec3(30, 30, 1), vec3(98.5F, 7, 200-33), Green, 60.f, vec3(1, 0, 0)); //RAMPA
	AddWall(vec3(30, 30, 1), vec3(115, 7, 200-33), Green, 60.f, vec3(1, 0, 0)); //RAMPA
	AddWall(vec3(30, 30, 1), vec3(98.5F, 7, 200 + 32.6F), Green, -60.f, vec3(1, 0, 0)); //RAMPA
	AddWall(vec3(30, 30, 1), vec3(115, 7, 200 +32.6F), Green, -60.f, vec3(1, 0, 0)); //RAMPA
	AddWall(vec3(3, XL+7, 170), vec3(82.5F, 7.5F+3.5F, 205), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 180), vec3(102.5F, 7.5F, 335.5F), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 40), vec3(82.5F, 7.5F, 330), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 20), vec3(82.5F, 7.5F, 400), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 20), vec3(82.5F, 7.5F, 440), Green); //IZQUIERDA
	AddWall(vec3(185, XL, 3), vec3(10, 7.5F, 390), Green); //IZQUIERDA
	AddWall(vec3(28, XL, 3), vec3(90, 7.5F, 350), Green); //IZQUIERDA
	AddWall(vec3(40, XL, 3), vec3(40, 7.5F, 350), Green); //IZQUIERDA
	AddWall(vec3(3, XL, 65), vec3(-31, 7.5F, 243), Green); //DERECHA
	AddWall(vec3(3, XL, 125), vec3(-31, 7.5F, 360), Green); //DERECHA
	AddWall(vec3(37, XL, 3), vec3(-12, 7.5F, 350), Green); //IZQUIERDA
	AddWall(vec3(60, XL, 3), vec3(-90, 7.5F, 350), Green); //DERECHA
	AddWall(vec3(30, XL, 3), vec3(14, 7.5F, 370), Green); //IZQUIERDA
	AddWall(vec3(30, XL, 3), vec3(-44.5, 7.5F, 297), Green); //DERECHA
	AddWall(vec3(3, XL, 75), vec3(-60, 7.5F, 261), Green); //DERECHA
	AddWall(vec3(3, XL, 75), vec3(-80, 7.5F, 261), Green); //DERECHA
	AddWall(vec3(20, XL, 3), vec3(-70, 7.5F, 225.5F), Green); //DERECHA
	AddWall(vec3(3, XL, 20), vec3(-31, 7.5F, 450), Green); //DERECHA
	AddWall(vec3(3, XL, 60), vec3(30, 7.5F, 420), Green); //DERECHA
	AddWall(vec3(3, XL, 42.8F), vec3(50, 7.5F, 370), Green); //DERECHA



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

