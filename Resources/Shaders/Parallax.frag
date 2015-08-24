
#version 330 core

out vec4 color;

in vec2 texCoord;
in vec3 tangentFragmentPosition;
in vec3 tangentLightPosition;
in vec3 tangentViewPosition;

uniform sampler2D textureImage;
uniform sampler2D normalMap;
uniform sampler2D depthMap;

uniform vec3 lightColor;

uniform float heightScale = 0.1f;

uniform float ambientStrength = 0.1f;
uniform float specularStrength = 0.5f;
uniform float shininess = 32.0f;

uniform float minimumLayers = 8.0f;
uniform float maximumLayers = 32.0f;

vec2 parallaxMapping(vec3 viewDirection) {
    float numberOfLayers = mix(maximumLayers, minimumLayers, abs(dot(vec3(0.0f, 0.0f, 1.0f), viewDirection)));
    
    float layerDepth = 1.0f / numberOfLayers;
    float currentLayerDepth = 0.0f;
    vec2 deltaTexCoord = (((viewDirection.xy / viewDirection.z) * heightScale) / numberOfLayers);
    
    vec2 currentTexCoord = texCoord;
    float currentDepthMapValue = texture(depthMap, currentTexCoord).x;
    
    while (currentLayerDepth < currentDepthMapValue) {
        currentTexCoord -= deltaTexCoord;
        currentDepthMapValue = texture(depthMap, currentTexCoord).x;
        currentLayerDepth += layerDepth;
    }
    
    vec2 previousTexCoord = currentTexCoord + deltaTexCoord;
    
    float afterDepth = currentDepthMapValue - currentLayerDepth;
    float beforeDepth = texture(depthMap, previousTexCoord).x - currentLayerDepth + layerDepth;
    float weight = afterDepth / (afterDepth - beforeDepth);
    
    vec2 finalTexCoords = (previousTexCoord * weight) + (currentTexCoord * (1.0f - weight));
    return finalTexCoords;
}

void main() {
    vec3 lightDirection = normalize(tangentLightPosition - tangentFragmentPosition);
    vec3 viewDirection = normalize(tangentViewPosition - tangentFragmentPosition);
    
    vec2 parallaxTexCoord = parallaxMapping(viewDirection);
    if (parallaxTexCoord.x > 1.0 || parallaxTexCoord.y > 1.0 || parallaxTexCoord.x < 0.0 || parallaxTexCoord.y < 0.0)
        discard;
    
    vec4 objectColor = texture(textureImage, parallaxTexCoord);
    vec3 normal = normalize(vec3((texture(normalMap, parallaxTexCoord) * 2.0f) - 1.0f));
    
    vec3 reflectDirection = reflect(-lightDirection, normal);
    
    vec3 ambient = ambientStrength * lightColor;
    vec3 diffuse = max(dot(normal, lightDirection), 0.0f) * lightColor;
    vec3 specular = pow(max(dot(viewDirection, reflectDirection), 0.0f), shininess) * specularStrength * lightColor;
    vec4 lightStrength = vec4((ambient + diffuse + specular), 1.0f);
    
    color = lightStrength * objectColor;
}
