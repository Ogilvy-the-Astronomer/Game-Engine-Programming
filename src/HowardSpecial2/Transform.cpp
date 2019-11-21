#include "Transform.h"


Transform::Transform()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

void Transform::OnUpdate()
{
	
	glm::mat4 f(1.0f);
	f = glm::rotate(f, rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 r = glm::rotate(f, 1.5708f, glm::vec3(0, 1, 0));

	f = glm::translate(f, glm::vec3(0, 0, 1));
	forward = f * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	forward = glm::normalize(forward);	r = glm::translate(r, glm::vec3(0, 0, 1));	right = r * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);	right = glm::normalize(right);	
	/*
	forward = glm::vec3(cos(glm::radians(rotation.y))*sin(glm::radians(rotation.x)), 0.0f, cos(glm::radians(rotation.y))*cos(glm::radians(rotation.x)));
	forward = glm::normalize(forward);

	glm::mat4 r(1.0f);
	r = glm::rotate(r, 1.5708f, glm::vec3(0, 1, 0));
	right = r * glm::vec4(forward, 1);
	right = glm::normalize(right);
	*/

}

glm::mat4 Transform::GetModel()
{
	glm::mat4 model(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, scale);
	return model;
}
