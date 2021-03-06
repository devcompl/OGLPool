/*
 * Triangle.h
 *
 *  Created on: 22-03-2013
 *      Author: _CORE7
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <Shape/Edge.h>
#include <glm/glm.hpp>
using namespace glm;

namespace OGLPool {

template< class T >
class Triangle : public Shape {
public:
	Triangle();
	Triangle( T v0, T v1, T v2 );
	Triangle( Edge<T> e0, Edge<T> e1, Edge<T> e2 );
	virtual ~Triangle();

	void render() const;

	//@TODO getPlane();
	Edge<T> getEdge( int i );
	Edge<T>* getEdges();
	const Edge<T>* getEdges() const;
	T getVertex( int i );
	T* getVertices();
	const T* getVertices() const;
	vec3 getNormal();
	T& operator[](int i);

	T closestPoint( T source );
	bool inside( T point );
private:
	T vertices[ 3 ];
	Edge<T> edges[ 3 ];
};

typedef Triangle< vec2 > Triangle2;
typedef Triangle< vec3 > Triangle3;

} /* namespace OGLPool */
#endif /* TRIANGLE_H_ */
