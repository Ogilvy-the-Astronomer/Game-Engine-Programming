uniform mat4 in_Model;
uniform mat4 lightSpaceMatrix;

attribute vec3 in_Position;

varying vec4 ex_FragPos;

void main()
{
    gl_Position = lightSpaceMatrix * in_Model *  vec4(in_Position, 1.0);
	ex_FragPos = in_Model * vec4(in_Position, 1.0);
}