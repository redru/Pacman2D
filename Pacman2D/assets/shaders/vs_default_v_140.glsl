#version 140

uniform mat4 u_mvpMatrix;

in vec4 a_position;

void main () {
	gl_Position = a_position;
}