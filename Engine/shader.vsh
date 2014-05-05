#version 150

in vec3 vert;
uniform mat4 camera;

void main() {
    // does not alter the verticies at all
    gl_Position = camera * vec4(vert, 1);
}