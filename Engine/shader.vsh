#version 150

in vec3 aVertexNormal;
in vec3 vert;
uniform mat4 camera;

out vec3 aNormal;

void main() {
    
    aNormal = aVertexNormal;
    
    gl_Position = camera * vec4(vert, 1);
}