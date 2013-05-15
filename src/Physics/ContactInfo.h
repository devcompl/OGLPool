/*
 * ContactInfo.h
 *
 *  Created on: 19-03-2013
 *      Author: _CORE7
 */

#ifndef CONTACTINFO_H_
#define CONTACTINFO_H_

#include <Entity/Entity.h>
#include <glm/glm.hpp>

using namespace glm;

namespace OGLPool {

class ContactInfo {
public:
	enum {
		INVALID = -1, OVERLAPPING = 1, COLLIDING
	};

	ContactInfo( float deltaTime );
	virtual ~ContactInfo();

	bool isOverlapping();
	bool isColliding();
	bool isValid();

	void setOverlapping( bool f );
	void setColliding( bool f );
	void setEntities( Entity* e0, Entity* e1 );

	Entity* e0;
	Entity* e1;

	vec3 normal;
	vec3 point0;
	vec3 point1;

	float depth;
	float time;

	float deltaTime;


	float m_combinedRollingFriction;
	float m_combinedFriction;
	float m_combinedRestitution;
	float m_appliedImpulse;

	float m_appliedImpulseLateral1;
	float m_appliedImpulseLateral2;
	bool m_lateralFrictionInitialized;
	vec3 m_lateralFrictionDir1;
	vec3 m_lateralFrictionDir2;
private:
	int contactType;
};

} /* namespace OGLPool */
#endif /* CONTACTINFO_H_ */
