#include <iostream>
#include <string>

class Object
{
public:
	virtual void BeginPlay();

	void ObjectFunction()
	{
		std::cout << "Object Function called!\n";
	}
};

class Actor : public Object
{
public:
	virtual void BeginPlay() override;

	void ActorFunction()
	{
		std::cout << "Actor Function called!\n";
	}
};

class Pawn : public Actor
{
public:
	virtual void BeginPlay() override;


	void PawnFunction()
	{
		std::cout << "Pawn Function called!\n";
	}
};

int main()
{
	Object* Ptr_to_object = new Object;
	Actor* Ptr_to_actor = new Actor;
	Pawn* Ptr_to_pawn = new Pawn;

	Object* ObjectArray[] = { Ptr_to_object, Ptr_to_actor, Ptr_to_pawn };

	for (int i = 0; i < 3; i++)
	{
		//ObjectArray[i]->BeginPlay();

		Object* obj = ObjectArray[i];

		Actor* act = dynamic_cast<Actor*>(obj);

		if (act)
		{
			act->ActorFunction();
		}

		Pawn* pwn = static_cast<Pawn*>(obj);

		if (pwn)
		{
			pwn->PawnFunction();
		}



	}








	delete Ptr_to_pawn;
	delete Ptr_to_actor;
	delete Ptr_to_object;
	system("pause");
}

void Object::BeginPlay()
{
	std::cout << "Object called \n\n";
}

void Actor::BeginPlay()
{
	std::cout << "Actor called \n\n";
}

void Pawn::BeginPlay()
{
	std::cout << "Pawn called \n\n";
}