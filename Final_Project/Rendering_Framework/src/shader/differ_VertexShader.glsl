#version 430 core

void main(){
	const vec4 verts[4] = vec4[4](
		vec4(-1.0,-1.0, 0.5,1.0),
		vec4( 1.0,-1.0, 0.5,1.0),
		vec4(-1.0, 1.0, 0.5,1.0),
		vec4( 1.0, 1.0, 0.5,1.0));

	gl_Position = verts[gl_VertexID];
}