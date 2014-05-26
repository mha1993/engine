#version 150

in vec3 aVertexNormal;
in vec3 vert;

uniform mat4 uMMatrix;
uniform mat4 uVPMatrix;

out vec3 aNormal;

void main() {
    
    vec4 tmp = uVPMatrix * uMMatrix * vec4(aVertexNormal,0.0);
    
    aNormal = tmp.xyz;
    
    gl_Position = uVPMatrix * uMMatrix * vec4(vert, 1.0);
}