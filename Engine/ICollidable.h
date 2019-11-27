#pragma once
#include "Box2D/Box2D.h"
#include "CollisionSystem.h"

class ICollidable
{
	friend class CollisionSystem;

private:

protected:
	bool staticCollider;
	b2Transform transform;
	b2Shape* shape;
	b2Manifold* manifold;

protected:
	ICollidable();
	inline const b2Transform& const getTransform() { return transform; }

public:
	bool trigger;

public:
	virtual ~ICollidable();
	inline const b2Shape* const getShape() { return shape; }
	inline const b2Manifold* const getManifold() { return manifold; }

};

