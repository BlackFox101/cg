#version 330 core

in vec4 gl_FragCoord;
out vec4 fragColor;

uniform float v_widht;
uniform float v_height;

void main()
{
    float radius = 100;
    float borderWidth = 15;
    vec3 center = vec3(v_widht / 2, v_height / 2, 0.0);
    vec3 position = vec3(gl_FragCoord) - center;

    if (length(position) <= radius && length(position) >= radius - borderWidth) 
    {
       gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    } 
    else 
    {
        gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
};
