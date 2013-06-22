/*
 * World.cpp
 *
 *  Created on: 17-03-2013
 *      Author: _CORE7
 */

#include "World.h"
#include <RigidBody/Sphere.h>
#include <RigidBody/Plane.h>
#include <Shape/Polygon/RandomPolygon.h>
#include <iostream>
#include <App/Input.h>
using namespace std;

namespace OGLPool {

World::World() : ct( CueTable( RandomPolygon( 10, 20 ), vector<vec2>() ) ) {
	addEntity( new Plane( vec3(0,1,0), vec3() ) );
	addEntity( new Plane( vec3(-1,0,0), vec3(50,50,0) ) );
	addEntity( new Plane( vec3(1,0,0), vec3(-50,50,0) ) );
	addEntity( new Plane( vec3(0,0,-1), vec3(0,50,50) ) );
	addEntity( new Plane( vec3(0,0,1), vec3(0,50,-50) ) );
	addEntity( ct.tableMesh );

	gravity = vec3(0,-10,0);
}

World::~World() {
	bodies.erase( remove_if( bodies.begin(), bodies.end(),
		[](RigidBody* element) -> bool {
			delete element;
			return true;
		}
	), bodies.end() );
}

void World::render(){
	for( auto it = bodies.begin(); it != bodies.end(); it++ ){
		RigidBody* e = (*it);
		e->render();
	}
}

void World::update( float dt ){
	for( auto it = bodies.begin(); it != bodies.end(); it++ ){
		RigidBody* e = (*it);
		e->update( dt );

		e->applyForce( gravity * e->mass );
	}

	physics.processBodies( bodies, dt );

	if( IO::Input::onKeyPressed( IO::Input::R ) ){
		Sphere* s = new Sphere( 5, vec3( 0, 30, 0 ) );
		s->setLinVel( vec3(0.1, 0.1, 15) );
		s->setAngVel( vec3(20.8, 1, 0) );
		addEntity( s );
	}
}

void World::addEntity( RigidBody* e ){
	bodies.push_back( e );
}

} /* namespace OGLPool */
