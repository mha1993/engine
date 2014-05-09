#version 150

in vec3 aVertexNormal;
in vec3 vert;

uniform mat4 camera;
uniform mat4 model;

out vec3 aNormal;

void main() {
    
    vec4 tmp = model * vec4(aVertexNormal,0.0);
    
    aNormal = tmp.xyz;
    
    gl_Position = camera * model * vec4(vert, 1.0);
}