#ifndef __MESH_H__
#define __MESH_H__

#pragma once
#include "Face.h"
#include "GL\glut.h"
#include"Texture.h"
class Mesh
{
public:
	vector<Face*>		_faces;
	vector<Vertex*>		_vertices;
	vector<Texture*>	_textureCoords;
	GLuint				_textureIndex;
	Vec3<double>	_minBound;
	Vec3<double>	_maxBound;

	float _thanos_angle;


public:

	Mesh();
	Mesh(char *file,char *texture)
	{
		open(file);
		loadTexture(texture, _textureIndex);
	}
	~Mesh();
public:
	void	open(char *file);
	void	loadTexture(char* file, GLuint & texture_index);
	void	computeNormal(void);
	void	makeAdjacencyList(void);
	void	moveToCenter(double scale = 1.0);
public:
	void	drawWire(void);
	void	drawPoint(void);
	void	drawSolid(bool smoothing = false);
	void	drawSolid2(bool smoothing = false);
	void	drawSolid3(bool smoothing = false);
	void	drawSolid4(bool smoothing = false);
	void	drawSolid5(bool smoothing = false);

	void	drawSolid6(bool smoothing = false);
};

#endif