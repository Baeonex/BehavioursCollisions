#pragma once
#include <vector>
#include <iostream>
#include <MathLib4.h>
#include <Application.h>
#include <Renderer2D.h>
//class SceneObject sets up the hierarchy for the app 
class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();
	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw(aie::Renderer2D* renderer ) {}
	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	//SceneObject* getParent() const, returns the parent to this object
	//output:the parent to this object
	SceneObject* getParent() const { return m_parent; }
	//size_t childCount() const, returns the size of the m_children vector container
	//output:size_t size of the container
	size_t childCount() const { return m_children.size(); }
	//SceneObject* getChild() const, returns the child to this object
	//input:the position of the child in the vector container
	//output:the child to this object
	SceneObject* getChild(unsigned int index) const { return m_children[index]; }
	//virtual void addChild(SceneObject* child), adds a child to this object
	//input:SceneObject* child, child to be added to this object
	virtual void addChild(SceneObject* child);
	//virtual void removeChild(SceneObject* child), removes child from this object
	//input:SceneObject* child the child to be removed from this object
	virtual void removeChild(SceneObject* child);
	//void setPosition(float x, float y), sets the position of this object and stores it into local matrix variable
	//input:float x, float y, the new x,y position values to be inserted into the matrix
	void setPosition(float x, float y);
	//void setRotate(float radians), sets the rotation of the object 
	//input:float radians, how much the object is to be rotated
	void setRotate(float radians);
	//void setScale(float width, float height), sets the scale of the object
	//input:float width, float height, the dimensions of the object
	void setScale(float width, float height);
	//void translate(float x, float y), translates the object
	//input:float x, float y, how much the object is translated
	void translate(float x, float y);
	//void rotate(float radians), rotates this object
	//input:float radians, the amount the object is roated
	void rotate(float radians);
	//void scale(float width, float height), scales this object
	//input:float width, float height,the new dimensions of the object
	void scale(float width, float height);
	//virtual void updateTransform(), updates the transform of the object and the children of this object
	virtual void updateTransform();
	//const Matrix3& SceneObject::getLocalTransform() const, returns the local matrix 
	//output: the local matrix
	const Matrix3& SceneObject::getLocalTransform() const { return m_localTransform; }
	//const Matrix3& SceneObject::getGlobalTransform() const, returns the global matrix 
	//output: the global matrix
	const Matrix3& SceneObject::getGlobalTransform() const { return m_globalTransform; }
	SceneObject* m_parent = nullptr; // the parent of this object
	std::vector<SceneObject*> m_children; //a container containing the children of this object
	Matrix3 m_localTransform = identity.identity(); //this objects matrix
	Matrix3 m_globalTransform = identity.identity();//the parents matrix
	Matrix3 identity;
};

