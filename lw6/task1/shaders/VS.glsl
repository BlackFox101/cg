#version 330 core

in vec3 pos;

uniform mat4 v_projectionMatrix;
uniform mat4 v_modelViewMatrix;

void main()
{
	float R = (1 + sin(pos.x)) * (1 + 0.9 * cos(8*pos.x)) * (1 + 0.1*cos(24*pos.x)) * (0.5 + 0.05*cos(140*pos.x));
	gl_Position = v_projectionMatrix * v_modelViewMatrix * vec4(R * cos(pos.x), R * sin(pos.x), pos.z, 1.0);
};
