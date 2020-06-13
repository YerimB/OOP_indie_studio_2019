#include <ECS/System/MoveSystem.h>
#include <Components/Cube.h>

MoveSystem::MoveSystem(EntityManager* pEntityManager) : BaseType(pEntityManager)
{
}

void MoveSystem::Update(const double& deltaTime)
{
	for (size_t i = 0; i < _components.size(); i += 1)
	{
		Drawable* drawable = std::get<Drawable*>(_components[i]);
		Collider* collider = std::get<Collider*>(_components[i]);
		Transform* transform = std::get<Transform*>(_components[i]);

		if (dynamic_cast<Cube*>(drawable))
		{
		}

		if (!drawable->GetDrawable())
			continue;

		for (size_t j = 1; j < _components.size(); j += 1)
		{
			if (i == j)
				continue;

			Drawable* drawable2 = std::get<Drawable*>(_components[j]);
			Collider* collider2 = std::get<Collider*>(_components[j]);

			if (!drawable2->GetDrawable())
				continue;

			if (MoveSystem::Collide(drawable, drawable2))
			{
				transform->SetPosition(drawable->GetPosition());
				transform->SetRotation(drawable->GetRotation());
				transform->SetScale(drawable->GetScale());
			}
			else
			{
				drawable->SetPosition(transform->GetPosition());
				drawable->SetRotation(transform->GetRotation());
				drawable->SetScale(transform->GetScale());
			}
		}
	}
}

bool MoveSystem::Collide(Drawable* drawable1, Drawable* drawable2)
{
	return drawable1->GetBounds().intersectsWithBox(drawable2->GetBounds());
}