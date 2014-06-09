#version 150

uniform sampler2D tex;

in vec2 fragTexCoord;

out vec4 finalColor;

void main() {
    vec4 temp = texture(tex, fragTexCoord);
    finalColor = vec4(temp.xyz, 0);
}