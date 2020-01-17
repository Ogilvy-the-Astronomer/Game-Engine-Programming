#pragma once
#include "Component.h"
#include <glm/ext.hpp>

/**
 * camera component
 */
struct Camera : public Component {
	Camera();
	glm::mat4 GetView(); ///< get view matrix
	glm::mat4 GetProjection(); ///< get projection matrix
	void OnUpdate();
private:
	glm::mat4 projection; ///< projection matrix
	//const float clampVal = glm::radians(70.0f);
};