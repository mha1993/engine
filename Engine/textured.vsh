#version 150

in vec3 vert;
in vec2 vertTexCoord;
uniform vec2 coord;
uniform vec2 size;

out vec2 fragTexCoord;

void main() {
    fragTexCoord = vertTexCoord;
    
    vec4 tmp = vec4(vert.x*size.x, vert.y*size.y, vert.z, 1) + vec4(coord,0,0);
    
    gl_Position = tmp;
}