/*
 * Circle.cpp
 *
 *  Created on: 23-03-2013
 *      Author: _CORE7
 */

#include "Circle.h"

namespace OGLPool {

Circle::Circle() {}
Circle::Circle( vec2 p, float r ) : center(p), radius(r) {}

Circle::~Circle() {}

bool Circle::inside( vec2 p ){
	return dot( center-p, center-p ) < radius * radius;
}

Circle Circle::circumCircle(vec2 p1, vec2 p2, vec2 p3) {
	Circle circle;
	vec2 v21 = p2 - p1;
	vec2 v31 = p3 - p1;
	float cp = v21.x * v31.y - v21.y * v31.x;

	if (cp != 0.0){
		float den = (2.0f * cp);
		float p1Sq = p1.x * p1.x + p1.y * p1.y;
		float p2Sq = p2.x * p2.x + p2.y * p2.y;
		float p3Sq = p3.x * p3.x + p3.y * p3.y;
		float cx = (p1Sq*(p2.y - p3.y) + p2Sq*(p3.y - p1.y) + p3Sq*(p1.y - p2.y)) / den;
		float cy = (p1Sq*(p3.x - p2.x) + p2Sq*(p1.x - p3.x) + p3Sq*(p2.x - p1.x)) / den;

		circle.center = vec2(cx, cy);
	}

	circle.radius = distance( circle.center, p1 );
	return circle;
}

} /* namespace OGLPool */
