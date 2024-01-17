#ifndef __VERTEX_H__
#define __VERTEX_H__

#pragma once
#include "Vec3.h"
#include <vector>

using namespace std;

class Face;
class Vertex
{
public:
	int position;
	int				_index;
	Vec3<double>	_pos;
	Vec3<double>	_normal;
	vector<Face*>	_nbFaces; // nb(neighbor faces)
public:
	Vertex();
	Vertex(int index, Vec3<double> pos)
	{
		_index = index;
		_pos = pos;
	}
	~Vertex();
public:
	inline double x(void) { return _pos[0] + position; }
	inline double y(void) { return _pos[1] + position; }
	inline double z(void) { return _pos[2] + position; }
};

#endif