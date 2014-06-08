#version 150

out vec3 coord;
in vec3 aVertexNormal;
in vec3 vert;

uniform mat4 uMMatrix;
uniform mat4 uVPMatrix;
uniform mat4 rotMat;

out vec3 aNormal;

void main() {    
    vec4 tmp = uMMatrix * vec4(aVertexNormal,0.0);
    aNormal = tmp.xyz;
    tmp = uVPMatrix * uMMatrix * rotMat * vec4(vert, 1.0);
    coord = tmp.xyz;
    gl_Position = tmp;
}