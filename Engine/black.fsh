#version 150

in vec3 aNormal;

out vec4 finalColor;

void main() {
    
    vec4 col = vec4(0.01, 0.01, 0.01, 1);
	
    float ambMultip = 1.0;
    
    vec3 diffVec = vec3(0.0, 0.0, 0.0);
    
    if ( length(aNormal) > 0.0){
        vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
        float diffuse = dot(normalize(aNormal),lightDir);
        
        if (diffuse < 0.0){
            diffuse = 0.0;
        }
        
        diffVec = diffuse * col.rgb;
        ambMultip = 0.2;
	}
    
    
    vec3 ambient = ambMultip * col.rgb;
	vec3 cmp = clamp(diffVec + ambient, 0.0, 1.0);
	
 	finalColor = vec4(cmp,1.0);
}