//
//  ProgramPack.h
//  ModelView
//
//  Created by Bowen Yang on Aug 13, 2016.
//  Copyright (c) 2016 Bowen Yang. All rights reserved.
//

# ifndef PROGRAMPACK
# define PROGRAMPACK

# include "AllinGL.h"
# include "ShaderPack.h"
# include <map>
# include <unordered_map>
# include "UBOPack.h"

class ProgramPack : public GLAttachable, public GLObject
{
private:
	std::unordered_map<GLenum, ShaderPack*> ShaderTable;
	GLint Fetch(std::string name);
	//std::unordered_map<GLuint, UniformPack*> UniformMap;
public:
	/**
	@brief
	Create the program, so that its ID's registered.
	Compile all the shaders and attach them to the program.
	Finally link all these shaders into this program.
	*/
	void Attach() override;

	/**
	Delete the program.
	*/
	void Detach() override;

	/**
	Call glUseProgram.
	Deprecated. Now it's merged with Attach().
	*/
	//void Use();

	/**
	Add some shaders to this program so that it knows where to start.
	Purely consists of client side invokes.
	*/
	void AddShader(std::string Path, GLenum type);

	/*
	Add some shaders, type told by its postfix.
	*/
	void AddShader(std::string Path);

	/**
	Reallocate its resources.
	*/
	~ProgramPack();

	/**
	A serie of functions that feeds the program with uniforms.
	*/
	void Uniform1(std::string name, GLfloat val);
	void Uniform1(std::string name, GLdouble val);
	void Uniform1(std::string name, GLint val);
	void Uniform1(std::string name, GLuint val);
	
	void Uniform2(std::string name, GLfloat* valLoc);
	void Uniform2(std::string name, GLdouble* valLoc);
	void Uniform2(std::string name, GLint* valLoc);
	void Uniform2(std::string name, GLuint* valLoc);

	void Uniform3(std::string name, GLfloat* valLoc);
	void Uniform3(std::string name, GLdouble* valLoc);
	void Uniform3(std::string name, GLint* valLoc);
	void Uniform3(std::string name, GLuint* valLoc);

	void Uniform4(std::string name, GLfloat* valLoc);
	void Uniform4(std::string name, GLdouble* valLoc);
	void Uniform4(std::string name, GLint* valLoc);
	void Uniform4(std::string name, GLuint* valLoc);
	
	/**
	A serie of functions that feeds the program with uniform matrices.
	isTransposed is set to GL_TRUE by default, making the matrix row-major.
	*/
	void UniformMat2(std::string name, GLfloat* valLoc, GLenum isTransposed = GL_TRUE);
	void UniformMat2(std::string name, GLdouble* valLoc, GLenum isTransposed = GL_TRUE);

	void UniformMat3(std::string name, GLfloat* valLoc, GLenum isTransposed = GL_TRUE);
	void UniformMat3(std::string name, GLdouble* valLoc, GLenum isTransposed = GL_TRUE);

	void UniformMat4(std::string name, GLfloat* valLoc, GLenum isTransposed = GL_TRUE);
	void UniformMat4(std::string name, GLdouble* valLoc, GLenum isTransposed = GL_TRUE);

	/**
	Feed the program with uniform blocks. Time to make them global.
	*/
};

# endif