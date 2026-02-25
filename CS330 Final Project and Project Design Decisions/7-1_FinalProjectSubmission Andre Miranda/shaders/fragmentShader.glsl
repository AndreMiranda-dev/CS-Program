#version 440 core

struct Material 
{
    vec3 ambientColor;
    float ambientStrength;
    vec3 diffuseColor;
    vec3 specularColor;
    float shininess;
}; 

struct LightSource 
{
    vec3 position;    
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
    float focalStrength;
    float specularIntensity;
};

#define TOTAL_LIGHTS 5

in vec3 fragmentPosition;
in vec3 fragmentVertexNormal;
in vec2 fragmentTextureCoordinate;

out vec4 outFragmentColor;

uniform bool bUseTexture = false;
uniform bool bUseLighting = false;
uniform vec4 objectColor = vec4(1.0f);
uniform sampler2D objectTexture;
uniform sampler2D texture2;
uniform float textureMix;
uniform vec3 viewPosition;
uniform vec2 UVscale = vec2(1.0f, 1.0f);
uniform LightSource lightSources[TOTAL_LIGHTS];
uniform Material material;

// fake glow 0.0 = off, 1.0 = full glow
uniform float emissiveStrength;

// glow pulse
uniform float uTime;

// main light toggle
uniform bool mainLightEnabled;

// main light intensity
uniform float mainLightIntensity;

// light function
vec3 CalcLightSource(LightSource light, vec3 lightNormal, vec3 vertexPosition, vec3 viewDirection);

// steam for coffee
uniform bool bSteam;
uniform float steamTime;

void main()
{
    // steam
    if (bSteam)
{
    float x = fragmentTextureCoordinate.x;
    float y = fragmentTextureCoordinate.y;

    // width
    float width = 0.16;
    float horizontal = 1.0 - smoothstep(width, width + 0.10, abs(x - 0.5));

    // fade
    float fade = smoothstep(0.0, 0.10, y) * (1.0 - smoothstep(0.50, 1.0, y));

    // wave motion
    float wave = sin((x * 4.0) + steamTime * 1.4) * 0.12;

    // transparent
    float alpha = fade * horizontal * (0.10 + 0.05 * wave);

    // color
    vec3 steamColor = vec3(0.70, 0.72, 0.75);

    outFragmentColor = vec4(steamColor, alpha);
    return;
}


    // compute emissive pulse
    float emissivePulse = 0.97 + 0.03 * sin(uTime * 40.0 + sin(uTime * 17.0));
    if (bUseLighting == true)
    {
        vec3 lightNormal = normalize(fragmentVertexNormal);
        vec3 viewDirection = normalize(viewPosition - fragmentPosition);
        vec3 phongResult = vec3(0.0f);

        for (int i = 0; i < TOTAL_LIGHTS; i++)
        {
            if (i == 0)
            {
                // skip main light if disabled
                if (!mainLightEnabled)
                    continue;

                // apply intensity multiplier
                phongResult += mainLightIntensity *
                               CalcLightSource(lightSources[i], lightNormal, fragmentPosition, viewDirection);
            }
            else
            {
                phongResult += CalcLightSource(lightSources[i], lightNormal, fragmentPosition, viewDirection);
            }
        }

        if (bUseTexture == true)
        {
            vec4 tex1 = texture(objectTexture, fragmentTextureCoordinate * UVscale);
            vec4 tex2 = texture(texture2, fragmentTextureCoordinate * UVscale);
            vec4 blendedTex = mix(tex1, tex2, textureMix);

            // base lit color
            vec3 finalColor = phongResult * blendedTex.rgb;

            // emissive glow with pulse
            finalColor += blendedTex.rgb * emissiveStrength * emissivePulse * 3.0;

            outFragmentColor = vec4(finalColor, blendedTex.a);
        }
        else
        {
            // base lit color
            vec3 finalColor = phongResult * objectColor.rgb;

            // emissive-only path with pulse
            finalColor += objectColor.rgb * emissiveStrength * emissivePulse * 3.0;

            outFragmentColor = vec4(finalColor, objectColor.a);
        }
    }
    else
    {
        if (bUseTexture == true)
        {
            vec4 tex1 = texture(objectTexture, fragmentTextureCoordinate * UVscale);
            vec4 tex2 = texture(texture2, fragmentTextureCoordinate * UVscale);
            vec4 blendedTex = mix(tex1, tex2, textureMix);

            // emissive no-lighting with pulse
            vec3 finalColor = blendedTex.rgb + blendedTex.rgb * emissiveStrength * emissivePulse * 3.0;

            outFragmentColor = vec4(finalColor, blendedTex.a);
        }
        else
        {
            // emissive no-lighting, no texture, with pulse
            vec3 finalColor = objectColor.rgb + objectColor.rgb * emissiveStrength * emissivePulse * 3.0;

            outFragmentColor = vec4(finalColor, objectColor.a);
        }
    }
}

vec3 CalcLightSource(LightSource light, vec3 lightNormal, vec3 vertexPosition, vec3 viewDirection)
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    // Ambient
    ambient = light.ambientColor * material.ambientColor * material.ambientStrength;

    // Diffuse
    vec3 lightDirection = normalize(light.position - vertexPosition);
    float impact = max(dot(lightNormal, lightDirection), 0.0);
    diffuse = impact * light.diffuseColor * material.diffuseColor;

    // Specular
    vec3 reflectDir = reflect(-lightDirection, lightNormal);
    float specularComponent = pow(max(dot(viewDirection, reflectDir), 0.0), light.focalStrength);
    specular = light.specularIntensity * specularComponent * light.specularColor * material.specularColor;

    return ambient + diffuse + specular;
}